#include "syncFIFO.h"
#include <qdebug.h>
#include <QDateTime>
//extern "C"{
//#include "cvtTempGray_Interface.h"
//}
#include <QDir>
#ifdef WIN32  

#pragma execution_character_set("utf-8")  
#endif
unsigned char g_pDate[300 * 400*2];
syncFIFO::syncFIFO()
{
	m_spbuf.reset(new unsigned char[BUF_4M]);
	memset(m_spbuf.get(), 0, BUF_4M);
	buf_max_len = BUF_4M;
	buf_len = 0;

	memsetbuf();
	//for (int i = 0; i < 256; i++)
	//	if (i<129)
	//		grayTable.push_back(qRgb(0, 0, 0));
	//	else
	//		grayTable.push_back(qRgb(255, 255, 255));

	for (int i = 0; i < 256; i++)
			grayTable.push_back(qRgb(i, i, i));
}


syncFIFO::~syncFIFO()
{
	m_bISGetUSBDate = false;
	quit();
	wait();	
}
/*************************************************
Function: SyncFIFO_Initial// 函数名称
Description: 初始化USB参数
Input: FT_HANDLE ftHandle USB连接的句柄
Return: 无// 函数返回值的说明
*************************************************/
bool syncFIFO::SyncFIFO_Initial(FT_HANDLE ftHandle)
{
	DWORD dwCount;
	ftStatus = FT_ResetDevice(ftHandle); 	//Reset USB device
	ftStatus = FT_SetBitMode(ftHandle, 0xFF, 0x00);//reset mode
	Sleep(10);//delay 10ms
	ftStatus = FT_SetBitMode(ftHandle, 0xFF, 0x40);//Sync FIFO mode
												   //Sleep(100);//delay 10ms
												   //Purge USB receive buffer first by reading out all old data from FT2232H receive buffer
	ftStatus |= FT_GetQueueStatus(ftHandle, &dwNumInputBuffer);	 // Get the number of bytes in the FT2232H receive buffer
	if ((ftStatus == FT_OK) && (dwNumInputBuffer > 0))
		ftStatus |= FT_Read(ftHandle, DataInBuffer, dwNumInputBuffer, &dwNumBytesRead);  	//Read out the data from FT2232H receive buffer
	ftStatus |= FT_SetUSBParameters(ftHandle, MAXBUFSIZE, MAXBUFSIZE-1);	//Set USB request transfer size
	ftStatus |= FT_SetTimeouts(ftHandle, 100, 1000);		//Sets the read and write timeouts in milliseconds
	ftStatus |= FT_SetLatencyTimer(ftHandle, 16);		//Set the latency timer
	ftStatus |= FT_SetFlowControl(ftHandle, FT_FLOW_RTS_CTS, 0x00, 0x00);

	if (ftStatus != FT_OK)
	{
		printf("fail on initialize FTDI device ! \n");
		return false;
	}
	Sleep(50);	// Wait for all the USB stuff to complete and work
	printf("Sync FIFO mode initial successful\n");
	return true;
}

/*************************************************
Function: _startGetDate// 函数名称
Description: 初始化USB参数等等
Input: 无
Return: 无// 函数返回值的说明
*************************************************/

void syncFIFO::_startGetDate()
{
  	//if (m_bISGetUSBDate == true) {
	//	emit SigOutErrorInfo(tr("请先停止再开启！"));
	//	return;
	//}
	//infile == nullptr;
	//infile = fopen("g:\\code\\logdata.txt", "a+");
	
	//FT_HANDLE ftdiHandle;
	DWORD numDevs = 0;
	FT_DEVICE_LIST_INFO_NODE *devInfo;
	
	ftStatus = FT_CreateDeviceInfoList(&numDevs);//get device number
	if (ftStatus == FT_OK)
		printf("Number of devices is %d\n", numDevs);
	else
		return ;
	if (numDevs == 0) {
		printf("Cannot find FTDI device\n");
		emit SigOutErrorInfo(tr("Cannot find FTDI device!"));
		return ;
	}
	
	ftStatus = FT_Open(0, &ftdiHandle);//open first device we found
	if (ftStatus != FT_OK)
	{
		emit SigOutErrorInfo(tr("Can't open FTDI device!"));
		printf("Can't open FTDI device! \n");
		return ;
	}
	
	//initial Sync FIFO mode
	if (SyncFIFO_Initial(ftdiHandle) == true)
	{
		emit SigOutErrorInfo(tr("设备打开完成！"));
		printf("start to read data from FPGA \n");		
		m_bISGetUSBDate = true;
	}
	else
	{
		emit SigOutErrorInfo(tr("设备打开失败！"));
		FT_Close(ftdiHandle);
		return;
	}
	
	Sleep(5);
	start();
	
	run1 =new std::thread(&syncFIFO::analysisRun, this);
}
/*************************************************
Function: pushDate// 函数名称
Description: 将数据加入队列，新数据加原有队列有的数据大于最大长度就进行循环解析图像并发送界面渲染
Input: unsigned char* orgData 加入队列的数据
		int len 数据长度
Return: 无// 函数返回值的说明
*************************************************/
void syncFIFO::pushDate(unsigned char* orgData, int len)
{
	if (len <= 0)
		return;

	int i = 0;
	while (i++<100)
	{	
		if (i == 99)
		{
			i = i;
		}

		if (buf_len + len > buf_max_len)
		{
			int looplen = buf_len - 12;
			int index = 0;
			for (int j = 0; j < looplen; j++)
			{
				index = j;
				unsigned char* pd = m_spbuf.get();
				if (pd[j] == 0x55 && pd[j + 1] == 0xaa && pd[j + 2] == 0x00 && pd[j + 3] == 0x00)
				{		
					int Datetype = 0;
					int Datelen = 0;
					memcpy(&Datelen, pd + j + 4, sizeof(int));
					memcpy(&Datetype, pd + j + 8, sizeof(int));
					if ((Datelen > Y16_SIZE) && (Datelen < 0) && (buf_len <= (Datelen + 12)))
					{
						continue;
					}
					if (buf_len - j > Datelen && Datetype == RETURN_Y16_DATE) {
						index = j + Datelen + 16;
						analysisY16Date(pd + j + 12);

						//memcpy(buf, pd+j+12, Y16_SIZE);						
						//char outrgb[300 * 400 * 3];
						//memset(outrgb, 0, 300 * 400 * 3);
						//outTemp++;
						//Y16TORGB((unsigned short*)buf, outrgb, 400, 300);
						//QImage myImage((unsigned char*)outrgb, 400, 300, QImage::Format_RGB888);
						////QImage myImage = Show8BitQimage((unsigned short*)buf, 400, 300);
						//emit SidgOutImage(myImage.copy());
						//if (m_bisSenY16) {
						//	m_mutex.lock();
						//	m_bisSenY16 = false;
						//	m_mutex.unlock();
						//	memset(g_pDate, 0, 300 * 400 * 2);
						//	memcpy(g_pDate, buf, 300 * 400 * 2);
						//	emit SigHistogram(myImage.copy(), (short*)g_pDate);
						//	SaveY16Date((unsigned char*)buf);
						//}
						break;
					}
					else if (Datetype == RETURN_KB_VALUE && buf_len - j > Datelen)
					{
						index = j + Datelen + 16;
						// 分解KB值设置到算法中去
						
						break;
					}
					else if (RETURN_REQUEST_ONCE_KB == Datetype && buf_len - j > Datelen)
					{
						index = j + Datelen + 16;
						// 发送一次KB值
						break;
					}
					else
						index = 0;					
				}
			}


			//for (int j = loopstart; j < looplen; j++)
			//{
			//	index = j;
			//	unsigned char* pd = m_spbuf.get();
			//	if (pd[j] == 0xaa && pd[j + 1] == 0x55 && pd[j + 2] == 0x00 && pd[j + 3] == 0x00)
			//	{
			//		emit SigWhileDateInfo("end pos：" + QString::number(j));
			//		break;
			//	}
			//}

			memmove(m_spbuf.get(), m_spbuf.get() + index, buf_len - index);
			buf_len = buf_len - index;
		}
		else
		{
			memcpy(m_spbuf.get() + buf_len, orgData, len);
			buf_len += len;
			break;
		}
	}
}
/*************************************************
Function: analysisRun// 函数名称
Description: 解析USB数据线程从m_Listbuf中获取数据加入队列进行解析
Input: 无
Return: 无// 函数返回值的说明
*************************************************/
void syncFIFO::analysisRun()
{	
	long long runcont = 0;
	while (m_bISGetUSBDate)
	{
		runcont++;
		m_mutex.lock();
		if (m_Listbuf.isEmpty() == false) {			
			unsigned char* orgData = m_Listbuf.dequeue();
			m_mutex.unlock();
			
			int len = 0;
			memcpy(&len, orgData, 4);
			unsigned char* analysisdate = orgData+4;					
			pushDate(analysisdate, len);
			free(orgData);
		}
		else
		{
			m_mutex.unlock();
		}
	}
}

/*************************************************
Function: run// 函数名称
Description: 获取USB数据线程循环读取USB的数据加入m_Listbuf
Input: 无
Return: 无// 函数返回值的说明
*************************************************/
void syncFIFO::run()
{	

	QDateTime current_date_time = QDateTime::currentDateTime();
	QString startcurrent_date = current_date_time.toString("yyyy.MM.dd hh:mm:ss.zzz");
	long count = 0;
	long runcont = 0;
	do
	{
		do
		{
			ftStatus = FT_GetQueueStatus(ftdiHandle, &dwNumInputBuffer);	 // Get the number of bytes in the FT232H receive buffer			
			if (m_bISGetUSBDate == false)
				break;			
		} while ((ftStatus == FT_OK) && (dwNumInputBuffer == 0));		
		
		int ret = FT_Read(ftdiHandle, DataInBuffer, dwNumInputBuffer, &dwNumBytesRead);
		runcont++;
		count += dwNumBytesRead;
		if (m_bisSaveDate)
			fwrite(DataInBuffer, dwNumBytesRead, 1, infile);
		
		if (dwNumBytesRead > 0)
		{
			long buflen = dwNumBytesRead + 4;
			int datelen = dwNumBytesRead;
			unsigned char* usbdate;
			usbdate = (unsigned char*)malloc(buflen);
			memcpy(usbdate, &datelen, sizeof(int));
			memcpy(usbdate + 4, DataInBuffer, dwNumBytesRead);
			m_mutex.lock();
			m_Listbuf.enqueue(usbdate);
			m_mutex.unlock();
		}
	} while (m_bISGetUSBDate);

	QDateTime current_date_time1 = QDateTime::currentDateTime();
	QString endcurrent_date = current_date_time1.toString("yyyy.MM.dd hh:mm:ss.zzz");

}



void syncFIFO::memsetbuf()
{
	memset(buf, 0, sizeof(buf));
}
/*************************************************
Function: StartGetPix// 函数名称
Description: 向下位机请求获取图像
Input: 无
Return: 无// 函数返回值的说明
*************************************************/
void syncFIFO::StartGetPix()
{	
	if (m_bISGetUSBDate == false) {
		emit SigOutErrorInfo(tr("请先打开设备!"));
		return;
	}
	int dateHead = 0xaa55;
	int dateTail = 0x55aa;
	int dateType = GET_Y16_DATE;
	int dateLen = 4;
	int date = 0x000000bb;
	//int date = 31373393920;// xbb;

	dwNumBytesRead = 0;

	char outbuf[MAXBUFSIZE];
	memset(outbuf, 0, MAXBUFSIZE);
	memcpy(outbuf + dwNumBytesRead, &dateHead, 4); dwNumBytesRead += 4;
	memcpy(outbuf + dwNumBytesRead, &dateLen, 4); dwNumBytesRead += 4;
	memcpy(outbuf + dwNumBytesRead, &dateType, 4); dwNumBytesRead += 4;
	memcpy(outbuf + dwNumBytesRead, &date, 4); dwNumBytesRead += 4;
	memcpy(outbuf + dwNumBytesRead, &dateTail, 4); dwNumBytesRead += 4;
	//  写入命令
	int ret = FT_Write(ftdiHandle, outbuf, MAXBUFSIZE, &dwNumBytesRead);	
	if (ret == 0)
		emit SigOutErrorInfo(tr("发送获取图像指令成功！"));
	else{
		QString info = tr("发送获取图像指令失败！code = ") + QString::number(ret);
		emit SigOutErrorInfo(info);
	}
}

/*************************************************
Function: GetKBvalue// 获取KB值
Description: 向下位机请求获取K值
Input: 无
Return: 无// 函数返回值的说明
*************************************************/
void syncFIFO::GetKBvalue()
{
	if (m_bISGetUSBDate == false) {
		emit SigOutErrorInfo(tr("请先打开设备!"));
		return;
	}
	int dateHead = 0xaa55;
	int dateTail = 0x55aa;
	int dateType = GET_KB_VALUE;
	int dateLen = 4;
	int date = 0xbb000000;

	dwNumBytesRead = 0;

	char outbuf[MAXBUFSIZE];
	memset(outbuf, 0, MAXBUFSIZE);
	memcpy(outbuf + dwNumBytesRead, &dateHead, 4); dwNumBytesRead += 4;
	memcpy(outbuf + dwNumBytesRead, &dateLen, 4); dwNumBytesRead += 4;
	memcpy(outbuf + dwNumBytesRead, &dateType, 4); dwNumBytesRead += 4;
	memcpy(outbuf + dwNumBytesRead, &date, 4); dwNumBytesRead += 4;
	memcpy(outbuf + dwNumBytesRead, &dateTail, 4); dwNumBytesRead += 4;
	//  写入命令
	int ret = FT_Write(ftdiHandle, outbuf, MAXBUFSIZE, &dwNumBytesRead);
	if (ret == 0)
		emit SigOutErrorInfo(tr("获取KB值指令发送完成！"));
	else {
		QString info = tr("获取KB值指令发送失败！code = ") + QString::number(ret);
		emit SigOutErrorInfo(info);
	}
}

/*************************************************
Function: StartGetPix// 函数名称
Description: 向下位机请求调节响应率  调节探测器响应率
Input: 无
Return: 无// 函数返回值的说明
*************************************************/
void syncFIFO::SetResponseRate()
{
	if (m_bISGetUSBDate == false) {
		emit SigOutErrorInfo(tr("请先打开设备!"));
		return;
	}
	int dateHead = 0xaa55;
	int dateTail = 0x55aa;
	int dateType = SET_RESPONSERATE;
	int dateLen = 2;
	short date = 0x0500;

	dwNumBytesRead = 0;

	char outbuf[MAXBUFSIZE];
	memset(outbuf, 0, MAXBUFSIZE);
	memcpy(outbuf + dwNumBytesRead, &dateHead, 4); dwNumBytesRead += 4;
	memcpy(outbuf + dwNumBytesRead, &dateLen, 4); dwNumBytesRead += 4;
	memcpy(outbuf + dwNumBytesRead, &dateType, 4); dwNumBytesRead += 4;
	memcpy(outbuf + dwNumBytesRead, &date, 2); dwNumBytesRead += 2;
	memcpy(outbuf + dwNumBytesRead, &dateTail, 4); dwNumBytesRead += 4;
	//  写入命令
	int ret = FT_Write(ftdiHandle, outbuf, MAXBUFSIZE, &dwNumBytesRead);	
	if (ret == 0)
		emit SigOutErrorInfo(tr("发送调节探测器响应率指令成功！"));
	else{
		QString info = tr("发送调节探测器响应率指令失败！code = ") + QString::number(ret);
		emit SigOutErrorInfo(info);
	}
}

/*************************************************
Function: Y16TORGB// 函数名称
Description: Y14数据转RGB short型为16位的，实际上是只取高8位进行成像
Input: unsigned short* y16 一帧Y16数据
		char* outrgb 输出的rgb图像 需要外部先创建好大小（malloc）
		int w  图像宽
		int h  图像高
Return: 无// 函数返回值的说明
*************************************************/
void syncFIFO::Y16TORGB(unsigned short* y16, char* outrgb, int w, int h)
{	
	int loop = 0;
	for (int i = 0; i<h; i++)
	{
		for (int j = 0; j<w; j++)
		{
			short d = y16[i*w + j];
			unsigned char y = (unsigned char)(y16[i*w + j]>>2);
			unsigned char u = 0;
			unsigned char v = 0;
			int r, g, b;
			r = y + ((351 * (v - 128)) >> 8);  //r
			g = y - ((179 * (v - 128) + 86 * (u - 128)) >> 8); //g
			b = y + ((443 * (u - 128)) >> 8); //b

			r = ((r>255) ? 255 : (r<0) ? 0 : r);
			g = ((g>255) ? 255 : (g<0) ? 0 : g);
			b = ((b>255) ? 255 : (b<0) ? 0 : b);
			//r = y;
			//g = y;
			//b = y;
			outrgb[loop] = r;
			outrgb[loop + 1] = g;
			outrgb[loop + 2] = b;
			loop += 3;
		}
	}
}
/*************************************************
Function: Show8BitQimage// 函数名称
Description: QT的方式成像Y8数据
Input: unsigned short* y16 一帧Y16数据 实际只取了高8位
int w  图像宽
int h  图像高
Return: QImage 解码的图像// 函数返回值的说明
*************************************************/
QImage syncFIFO::Show8BitQimage(unsigned short* y16, int w, int h)
{
	QImage image(w, h, QImage::Format_Indexed8);
	image.setColorTable(grayTable);
	int index = 0;
	for (int i = 0; i < w; ++i)
	{
		for (int j = 0; j < h; ++j)
		{
			unsigned char color = (unsigned char)(y16[index] );			
 			image.setPixel(i, j, color);
			index++;
		}
	}
	return image;
}

/*************************************************
Function: SlotStopthread// 函数名称
Description: 槽函数,停止获取 结束接收和解析线程
Input:无
Return: 无
*************************************************/
void syncFIFO::SlotStopthread()
{
	if (m_bISGetUSBDate == false) {
		emit SigOutErrorInfo(tr("未找到需要停止的设备!"));
		return;
	}
	m_bISGetUSBDate = false;
	

	quit();
	wait();

	run1->join();
	delete run1;
	FT_Close(ftdiHandle);
	//if (m_bisSaveDate)
	//	SaveDate();
	m_Listbuf.clear();
	memset(buf, 0, sizeof(buf));
	memset(m_spbuf.get(), 0, BUF_4M);
	emit SigOutErrorInfo(tr("停止设备完成！"));
}
/*************************************************
Function: SlotGetOneY16// 函数名称
Description: 槽函数,获取当前图像的下一帧图像 做直方图
Input:无
Return: 无
*************************************************/
void syncFIFO::SlotGetOneY16()
{
	m_mutex.lock();
	m_bisSenY16 = true;
	m_mutex.unlock();
}

/*************************************************
Function: SaveDate// 函数名称
Description: 保存下位机传上来的数据
Input:无
Return: 无
*************************************************/

void syncFIFO::SaveDate()
{
	if (m_bisSaveDate == false)
	{
		QString path = QDir::currentPath()+"/ay16date.txt";
		
		infile = fopen(path.toLatin1().data(), "wb+");
		m_bisSaveDate = true;
	}
	else
	{
		m_bisSaveDate = false;
		Sleep(5);
		fclose(infile);
	}
}

/*************************************************
Function: SaveY16Date// 函数名称
Description: 保存下位机传上来的Y16数据一帧
Input:无
Return: 无
*************************************************/
void syncFIFO::SaveY16Date(unsigned char *y16)
{
	//return;
	QString path = QDir::currentPath() + "/a"+QString::number(QDateTime::currentDateTime().toTime_t()) + ".yuv";
	FILE* y16file = fopen(path.toLatin1().data(), "wb+");
	if (y16file != NULL)
		fwrite(y16,300*400*2,1, y16file);
	fclose(y16file);
}

/*************************************************
Function: analysisY16Date// 
Description: 解析下位机传来的Y16数据
Input:unsigned char* pd  数据包
Return: 无
*************************************************/
void syncFIFO::analysisY16Date(unsigned char* pd)
{
	memcpy(buf, pd , Y16_SIZE);
	char outrgb[300 * 400 * 3];
	memset(outrgb, 0, 300 * 400 * 3);
	Y16TORGB((unsigned short*)buf, outrgb, 400, 300);
	QImage myImage((unsigned char*)outrgb, 400, 300, QImage::Format_RGB888);
	//QImage myImage = Show8BitQimage((unsigned short*)buf, 400, 300);
	emit SigOutImage(myImage.copy());
	if (m_bisSenY16) {
		m_mutex.lock();
		m_bisSenY16 = false;
		m_mutex.unlock();
		memset(g_pDate, 0, 300 * 400 * 2);
		memcpy(g_pDate, buf, 300 * 400 * 2);
		emit SigHistogram(myImage.copy(), (short*)g_pDate);
		SaveY16Date((unsigned char*)buf);
	}
}