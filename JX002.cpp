#include "JX002.h"
#include <QDebug>
#include <QMessageBox>
#include <QPainter>
#include <QStandardItemModel>
#include <QtCharts/QtCharts>


#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif
#include <QTableWidget>
#include <QModelIndex>
JX002::JX002(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	connect(&syncFIFO, &syncFIFO::SigOutErrorInfo, this, &JX002::SlotMessageBox);
	connect(&syncFIFO, &syncFIFO::SigOutImage, this, &JX002::SlotOutImage);
	connect(&syncFIFO, &syncFIFO::SigHistogram, this, &JX002::SlotHistogram);
	connect(ui.BtnOpenDev, &QPushButton::clicked, this, &JX002::SlotOpenDev);
	connect(ui.BtnStop, &QPushButton::clicked, this, &JX002::SlotStopDev);
	connect(ui.BtnShutter, &QPushButton::clicked, this, &JX002::SlotBtnShutter);
	connect(ui.BtnMax, &QPushButton::clicked, this, &JX002::SlotBtnMax);
	connect(ui.BtnMin, &QPushButton::clicked, this, &JX002::SlotBtnMin);
	connect(ui.BtnCenter, &QPushButton::clicked, this, &JX002::SlotBtnCenter);
	connect(ui.BtnGetPix, &QPushButton::clicked, this, &JX002::SlotBtnGetPix);
	connect(ui.BtnGetDate, &QPushButton::clicked, &syncFIFO, &syncFIFO::SlotGetOneY16);	
	connect(ui.BtnCleanTxt, &QPushButton::clicked, this, &JX002::SlotCleanTxt);
	connect(ui.BtnSaveDate, &QPushButton::clicked, this, &JX002::SlotSaveDate);
	connect(&syncFIFO, &syncFIFO::SigWhileDateInfo, this, &JX002::SlotWhileDateInfo);
	connect(ui.HtableWidget, &QTableWidget::itemChanged, this, &JX002::SlotHArrChange);
	connect(ui.tabWidget, &QTabWidget::currentChanged, this, &JX002::SlotTabWidgetChanged);
	connect(ui.BtnRestLList, &QPushButton::clicked, this, &JX002::SlotBtnRestL);
	connect(ui.BtnRestHList, &QPushButton::clicked, this, &JX002::SlotBtnRestH);
	connect(ui.BtnDefault, &QPushButton::clicked, this, &JX002::SlotRestCoefficient);
	connect(ui.BtnRestAll, &QPushButton::clicked, this, &JX002::SlotRestAllListValue);
	connect(ui.BtnResponseRate, &QPushButton::clicked, this, &JX002::SlotBtnResponseRate);
	connect(ui.BtnSave, &QPushButton::clicked, this, &JX002::SlotBtnSave);
	
	ui.textEdit->document()->setMaximumBlockCount(15000); //设置信息栏最大数据行数
	tableWidgetInit(ui.HtableWidget);//初始化高温列表
	tableWidgetInit(ui.LtableWidget);//初始化低温列表
	////创建低温列表增加按钮
	//LBtn = new QPushButton;
	//LBtn->setIcon(QIcon(":/JX002/Res/add.png"));
	//ui.LtableWidget->setCellWidget(0, 3, LBtn);
	connect(ui.BtnAddL, &QPushButton::clicked, this, &JX002::SlotAddL);
	////创建高温列表增加按钮
	//HBtn = new QPushButton;
	//HBtn->setIcon(QIcon(":/JX002/Res/add.png"));
	//ui.HtableWidget->setCellWidget(0, 3, HBtn);
	connect(ui.BtnAddH, &QPushButton::clicked, this, &JX002::SlotAddH);

	// 设置直方图样式
	QLinearGradient plotGradient;	//设置渐变
	plotGradient.setStart(0, 0);
	plotGradient.setFinalStop(0, 350);
	plotGradient.setColorAt(0, QColor(80, 80, 80)); 
	plotGradient.setColorAt(1, QColor(50, 50, 50));
	//plotGradient.se(1, QColor(50, 50, 50));
//	ui.widget->xAxis->setLabelColor(QColor(255, 255, 0));
	ui.PlotWidget->xAxis->setTickLabelColor(QColor(164, 164, 164));
//	ui.widget->yAxis->setLabelColor(QColor(255, 255, 0));
	ui.PlotWidget->yAxis->setTickLabelColor(QColor(164, 164, 164));
	ui.PlotWidget->setBackground(plotGradient);//设置背景颜色
	SlotRestAllListValue();
	SlotBtnSave();
}

void JX002::tableWidgetInit(QTableWidget* tabel)
{	
	tabel->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//平均分配列宽
	//tabel->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);//平均分配行宽
	tabel->horizontalHeader()->setVisible(false);
	tabel->verticalHeader()->setVisible(false);	
	//tabel->insertRow(tabel->rowCount()); //添加
	//QTableWidgetItem *item = new QTableWidgetItem();
	//item->setText("序号");
	//item->setTextAlignment(Qt::AlignCenter);
	//item->setFlags(item->flags() & (~Qt::ItemIsEnabled));
	//item->setBackground(QColor(34, 34, 34));	
	//tabel->setItem(0, 0, item);
	//
	//QTableWidgetItem *item1 = new QTableWidgetItem();
	//item1->setText("温度");
	//item1->setTextAlignment(Qt::AlignCenter);
	//item1->setFlags(item->flags() & (~Qt::ItemIsEnabled));
	//item1->setBackground(QColor(34, 34, 34));
	//tabel->setItem(0, 1, item1);
	//
	//QTableWidgetItem *item2 = new QTableWidgetItem();
	//item2->setText("差值");
	//item2->setTextAlignment(Qt::AlignCenter);
	//item2->setFlags(item->flags() & (~Qt::ItemIsEnabled));
	//item2->setBackground(QColor(34, 34, 34));
	//tabel->setItem(0, 2, item2);
}

/*************************************************
Function: Imhistdate// 函数名称
Description: QCustomPlot QT的一个控件，提升一个Widget传入，函数作用是将Y14的值用直方图的形式展示出来
Input: QCustomPlot * plot 控件// QT的一个控件，提升一个Widget传入
QImage *img RGB的数据，每个像素点0-255
Return: 无// 函数返回值的说明
*************************************************/
void JX002::Imhist(QCustomPlot * plot, QImage *img)
{
	double yrange = 0;
	QVector<double> datax;
	QVector<double> datay;
	plot->clearPlottables();
	datay.resize(256);
	for (double i = 0; i < 256; i = i + 1)
		datax.append(i);
	QImage  grayimg = img->copy();
	unsigned char * data = grayimg.bits();
	//  对直方图进行数据处理
	int width = img->width();
	int hight = img->height();

	for (int i = 0; i <hight; i++)
	{
		for (int j = 0; j < width; j++)
		{		
			datay.replace(data[i*hight + j], datay.at(data[i*hight + j]) + 1);
		}
	}

	QVector<double>::iterator it;
	for (it = datay.begin(); it != datay.end(); it++)
	{
		if (*it > yrange)
			yrange = *it;
	}

	plot->xAxis->setRange(0, 256);  //x轴范围
	plot->yAxis->setRange(0, (int)yrange);  //y轴范围
	
	//QCPBars* bars = new QCPBars(plot->xAxis, plot->yAxis);
	//m_pbars = bars;
	//bars->setData(datax, datay);
	//bars->setPen(QColor(255, 255, 0));
	//bars->setWidth(2);
	//plot->setVisible(true);
	//plot->replot();


	QCPBars* bars = new QCPBars(plot->xAxis, plot->yAxis);
	m_pbars = bars;
	bars->setData(datax, datay);
	bars->setPen(QColor(250, 250, 0));
	bars->setBrush(QColor(250, 250, 0));
	bars->setWidth(2);
	plot->setVisible(true);
	plot->replot();
}

/*************************************************
Function: Imhistdate// 函数名称
Description: QCustomPlot QT的一个控件，提升一个Widget传入，函数作用是将Y14的值用直方图的形式展示出来
Input: QCustomPlot * plot 控件// QT的一个控件，提升一个Widget传入
		short *img Y14的数据，short是16位的进行处理的时候要右移2位
Return: 无// 函数返回值的说明
*************************************************/
void JX002::Imhistdate(QCustomPlot * plot, short *img)
{	
	double yrange = 0;
	QVector<double> datax;
	QVector<double> datay;
	plot->clearPlottables();
	datay.resize(16383);
	for (double i = 0; i < 16383; i = i + 1)
		datax.append(i);
	//QImage  grayimg = img->copy();
	short * data = img;
	//  对直方图进行数据处理
	int width = 400;
	int hight = 300;

	int loop = 0;
	for (int i = 0; i <hight; i++)
	{
		for (int j = 0; j < width; j++)
		{
			unsigned short ee = data[i*hight + j];
			unsigned short number = (unsigned short)data[i*hight + j] >> 2;
			int bb = number;
			datay.replace(bb, datay.at(bb) + 1);
		}
	}

	QVector<double>::iterator it;
	for (it = datay.begin(); it != datay.end(); it++)
	{
		if (*it > yrange)
			yrange = *it;
	}

	plot->xAxis->setRange(0, 16383);  //x轴范围
	plot->yAxis->setRange(0, (int)yrange);  //y轴范围
	QCPBars* bars = new QCPBars(plot->xAxis, plot->yAxis);
	m_pbars = bars;
	bars->setData(datax, datay);
	bars->setPen(QColor(250, 250, 0));
	bars->setBrush(QColor(250, 250, 0));
	bars->setWidth(1);
	plot->setVisible(true);
	plot->replot();
}

/*************************************************
Function: SlotHistogram// 函数名称
Description: 槽函数，用来渲染直方图那一张图像的，并且分解直方图数据
Input: QImage pix 需要渲染的图像
short* grayimage Y14的数据
Return: 无// 函数返回值的说明
*************************************************/
void JX002::SlotHistogram(QImage pix, short* grayimage)
{
	ui.label_Original->setPixmap(QPixmap::fromImage(pix));
	Imhistdate(ui.PlotWidget, grayimage);
	//Imhist(ui.widget, &pix);
}

/*************************************************
Function: SlotAddL// 函数名称
Description: 槽函数，添加低温档的列表值
Input: 无
Return: 无// 函数返回值的说明
*************************************************/
void JX002::SlotAddL()
{
	AddItem(ui.LtableWidget);
}

/*************************************************
Function: SlotAddH// 函数名称
Description: 槽函数，添加高温档的列表值
Input: 无
Return: 无// 函数返回值的说明
*************************************************/
void JX002::SlotAddH()
{
	AddItem(ui.HtableWidget);
}
/*************************************************
Function: AddItem// 函数名称
Description: 给列表添加值
Input: QTableWidget 对应的控件
Return: 无// 函数返回值的说明
*************************************************/
void JX002::AddItem(QTableWidget* tabel,int temp, int sub)
{
	int row = tabel->rowCount();
	tabel->insertRow(row); //添加
	QTableWidgetItem *item = new QTableWidgetItem();
	item->setText(QString::number(row+1));
	item->setFlags(item->flags() & (~Qt::ItemIsEnabled));
	item->setTextAlignment(Qt::AlignCenter);	
	item->setBackground(QColor(34, 34, 34));
	tabel->setItem(row, 0, item);

	QTableWidgetItem *item1 = new QTableWidgetItem();
	item1->setText(QString::number(temp));
	item1->setTextAlignment(Qt::AlignCenter);	
	item1->setBackground(QColor(34, 34, 34));
	tabel->setItem(row, 1, item1);

	QTableWidgetItem *item2 = new QTableWidgetItem();
	item2->setText(QString::number(sub));
	item2->setTextAlignment(Qt::AlignCenter);	
	item2->setBackground(QColor(34, 34, 34));
	tabel->setItem(row, 2, item2);

	QPushButton *HBtn = new QPushButton;
	HBtn->setIcon(QIcon(":/JX002/Res/sub.png"));
	if (tabel->objectName() == "LtableWidget")
		HBtn->setObjectName("L"+ QString::number(row));
	else
		HBtn->setObjectName("H" + QString::number(row));
	tabel->setCellWidget(row, 3, HBtn);
	connect(HBtn, &QPushButton::clicked, this, &JX002::SlotDeleteRow);


	TreeItem* pti = new TreeItem;
	pti->item = item;
	pti->item1 = item1;
	pti->item2 = item2;
	pti->Btn = HBtn;
	m_ListBtn.append(pti);
}
/*************************************************
Function: SlotDeleteRow// 函数名称
Description: 槽函数 删除一列数据（灰度转温度  高低温都用这个删）
Input:
Return: 无// 函数返回值的说明
*************************************************/
void JX002::SlotDeleteRow()
{
	QPushButton *Btn = qobject_cast<QPushButton *>(sender());
	QString type = Btn->objectName().mid(0, 1);
	QString inde = Btn->objectName().mid(1, Btn->objectName().length());
	int Btnindex = 0;
	TreeItem* Deletepti = NULL;
	for (int i = 0; i < m_ListBtn.size(); i++)
	{
		TreeItem* pti = m_ListBtn.at(i);
		if (Btn == pti->Btn)
		{
			Btnindex = i;	
			Deletepti = m_ListBtn.at(Btnindex);
		}		
		if (pti->Btn->objectName().mid(0, 1) == type)
		{
			int ptiindex = pti->Btn->objectName().mid(1, pti->Btn->objectName().length()).toInt();
			if (ptiindex > inde.toInt() && ptiindex != inde.toInt())
			{
				pti->item->setText(QString::number(ptiindex));
				pti->Btn->setObjectName(type+QString::number(ptiindex-1));
			}
		}
	}
	m_ListBtn.removeAt(Btnindex);
	
	if (type == "L" && Deletepti != NULL){
		ui.LtableWidget->removeRow(inde.toInt());	
		
	}
	else if (type == "H" && Deletepti != NULL)	{
		ui.HtableWidget->removeRow(inde.toInt());
		
	}
	Deletepti->Btn->deleteLater();
	delete Deletepti;

	ui.BtnAddL->setFocus();
	ui.BtnAddH->setFocus();
}
/*************************************************
Function: SlotBtnRestL// 函数名称
Description: 槽函数，设置恢复低温列表的默认值
Input:无
Return: 无// 函数返回值的说明
*************************************************/
void JX002::SlotBtnRestL()
{
	CleanAllList("L");
	AddItem(ui.LtableWidget, -30, 0);
	AddItem(ui.LtableWidget, -20, 141);
	AddItem(ui.LtableWidget, -10, 168);
	AddItem(ui.LtableWidget, 0, 195);
	AddItem(ui.LtableWidget, 10, 223);
	AddItem(ui.LtableWidget, 20, 250);
	AddItem(ui.LtableWidget, 30, 277);
	AddItem(ui.LtableWidget, 40, 305);
	AddItem(ui.LtableWidget, 50, 332);
	AddItem(ui.LtableWidget, 60, 360);
	AddItem(ui.LtableWidget, 70, 389);
	AddItem(ui.LtableWidget, 80, 417);
	AddItem(ui.LtableWidget, 90, 447);
	AddItem(ui.LtableWidget, 100, 478);
	AddItem(ui.LtableWidget, 110, 508);
	AddItem(ui.LtableWidget, 120, 541);
	AddItem(ui.LtableWidget, 130, 574);
	AddItem(ui.LtableWidget, 140, 608);
	AddItem(ui.LtableWidget, 150, 642);
	AddItem(ui.LtableWidget, 160, 677);
}
/*************************************************
Function: SlotBtnRestH// 函数名称
Description: 槽函数，设置恢复高温列表的默认值
Input:无
Return: 无// 函数返回值的说明
*************************************************/
void JX002::SlotBtnRestH()
{
	CleanAllList("H");
	AddItem(ui.HtableWidget, -30, 0);	
	AddItem(ui.HtableWidget, 10 , 105);
	AddItem(ui.HtableWidget, 50,  179);
	AddItem(ui.HtableWidget, 90,  238);
	AddItem(ui.HtableWidget, 130, 328);
	AddItem(ui.HtableWidget, 170, 404);
	AddItem(ui.HtableWidget, 210, 478);
	AddItem(ui.HtableWidget, 250, 553);
	AddItem(ui.HtableWidget, 290, 628);
	AddItem(ui.HtableWidget, 330, 703);
	AddItem(ui.HtableWidget, 370, 778);
	AddItem(ui.HtableWidget, 410, 854);
	AddItem(ui.HtableWidget, 450, 919);
	AddItem(ui.HtableWidget, 490, 984);
	AddItem(ui.HtableWidget, 530, 1050);
	AddItem(ui.HtableWidget, 570, 1115);
}

/*************************************************
Function: SlotRestCoefficient// 函数名称
Description: 槽函数，设置恢复高温列表的默认值
Input:无
Return: 无// 函数返回值的说明
*************************************************/
void JX002::SlotRestCoefficient()
{
	ui.LLlineEdit->setText("3");
	ui.LHlineEdit->setText("3");
	ui.HLlineEdit->setText("8");
	ui.HHlineEdit->setText("8");
	ui.LlineEdit->setText("1");
	ui.HlineEdit->setText("1");
}

/*************************************************
Function: SlotBtnSave// 函数名称
Description: 槽函数，保存温度系数
Input:无
Return: 无// 函数返回值的说明
*************************************************/
void JX002::SlotBtnSave()
{
	QList<TreeItem*> LTempList;
	QList<TreeItem*> HTempList;

	for (int i = 0; i < m_ListBtn.size(); i++)
	{
		TreeItem* pti = m_ListBtn.at(i);
		qDebug() << pti->Btn->objectName()<< pti->Btn->objectName().mid(0, 1);
		if (pti->Btn->objectName().mid(0,1) == "L")		
			LTempList.append(pti);
		else		
			HTempList.append(pti);
	}
	int size = LTempList.size();  
	for (int i = 0; i < size; i++)
	{
		syncFIFO.m_Larr[i][0] = LTempList.at(i)->item1->text().toFloat();  //乘低温档系数
		syncFIFO.m_Larr[i][1] = LTempList.at(i)->item2->text().toFloat();
	}
	syncFIFO.m_nLarrCount = size;
	size = HTempList.size();
	for (int i = 0; i < size; i++)
	{
		syncFIFO.m_Harr[i][0] = HTempList.at(i)->item1->text().toFloat(); //乘高温档系数
		syncFIFO.m_Harr[i][1] = HTempList.at(i)->item2->text().toFloat();
	}


}

/*************************************************
Function: SlotRestAllListValue// 函数名称
Description: 全部数据恢复默认
Input:无
Return: 无// 函数返回值的说明
*************************************************/
void JX002::SlotRestAllListValue()
{
	SlotRestCoefficient();
	SlotBtnRestH();
	SlotBtnRestL();
}

/*************************************************
Function: CleanAllList// 函数名称
Description: 清空高低温档列表
Input:QString type   == "H" 清空高温档列表   清空低温档列表
Return: 无// 函数返回值的说明
*************************************************/
void JX002::CleanAllList(QString type)
{
	bool isbrak = true;
	while (isbrak == true)
	{
		isbrak = false;
		for (int i = 0; i < m_ListBtn.size(); i++)
		{			
			TreeItem* pti = m_ListBtn.at(i);
			if (pti->Btn->objectName().mid(0, 1) == type)
			{
				if (type == "H")
					ui.HtableWidget->removeRow(pti->item->row());
				else
					ui.LtableWidget->removeRow(pti->item->row());
				
				pti->Btn->deleteLater();
				m_ListBtn.removeAt(i);				
				isbrak = true;
				break;
			}
		}
	}	
}

/*************************************************
Function: SlotHArrChange// 函数名称
Description: 槽函数 高温数组发生变化
Input:
Return: 无// 函数返回值的说明
*************************************************/
void JX002::SlotHArrChange(QTableWidgetItem *item)
{

}
/*************************************************
Function: SlotLArrChange// 函数名称
Description: 槽函数 低温数组发生变化
Input:
Return: 无// 函数返回值的说明
*************************************************/
void JX002::SlotLArrChange(QTableWidgetItem *item)
{
}
/*************************************************
Function: SlotOpenDev// 函数名称
Description: 槽函数，打开设备 //函数描述
Input: 无	// 函数输入
Return: 无// 函数返回值的说明
*************************************************/
void JX002::SlotOpenDev()
{
	syncFIFO._startGetDate();
}

/*************************************************
Function: SlotStopDev// 函数名称
Description: 槽函数， 停止设备 //函数描述
Input: 无	// 函数输入
Return: 无// 函数返回值的说明
*************************************************/
void JX002::SlotStopDev()
{
	syncFIFO.SlotStopthread();
}

/*************************************************
Function: SlotMessageBox// 函数名称
Description: 槽函数， Message弹窗 ， 消息盒子 //函数描述
Input: 无	// 函数输入
Return: 无// 函数返回值的说明
*************************************************/
void JX002::SlotMessageBox(QString info)
{
	//QMessageBox::information(this, "info", info);
	ui.textEdit->append(info);
}
/*************************************************
Function: SlotBtnMax// 函数名称
Description: 槽函数 ，最高温度开关 //函数描述
Input: 无	// 函数输入
Return: 无// 函数返回值的说明
*************************************************/
void JX002::SlotBtnMax()
{
}

/*************************************************
Function: SlotUSBDate// 函数名称
Description: 槽函数  没用（丢弃了，以后看是否用起来，暂时没用）//函数描述
Input: 无	// 函数输入
Return: 无// 函数返回值的说明
*************************************************/
void JX002::SlotUSBDate(QString date)
{
}

/*************************************************
Function: SlotBtnShutter		// 函数名称
Description: 槽函数  打快门	//函数描述
Input: 无					// 函数输入
Return: 无					// 函数返回值的说明
*************************************************/
void JX002::SlotBtnShutter()
{
}

/*************************************************
Function: SlotOutImage		// 函数名称
Description: 槽函数  接收传入的QImage进行渲染	//函数描述
Input: QImage img 需要渲染的图像					// 函数输入
Return: 无					// 函数返回值的说明
*************************************************/
void JX002::SlotOutImage(QImage img)
{
	DrawPix(img);
}
/*************************************************
Function: SlotBtnMin		// 函数名称
Description: 槽函数  最低温度开关	//函数描述
Input: 无					// 函数输入
Return: 无					// 函数返回值的说明
*************************************************/
void JX002::SlotBtnMin()
{

}
/*************************************************
Function: SlotBtnCenter		// 函数名称
Description: 槽函数  中心温度开关	//函数描述
Input: 无					// 函数输入
Return: 无					// 函数返回值的说明
*************************************************/
void JX002::SlotBtnCenter()
{

}

/*************************************************
Function: SlotBtnGetPix		// 函数名称
Description: 槽函数  控件获取图像按钮链接槽，开启USB获取图像	//函数描述
Input: 无					// 函数输入
Return: 无					// 函数返回值的说明
*************************************************/
void JX002::SlotBtnGetPix()
{
	syncFIFO.StartGetPix();
}

/*************************************************
Function: SlotBtnResponseRate		// 函数名称
Description: 槽函数  控件调节响应率接槽	//函数描述
Input: 无					// 函数输入
Return: 无					// 函数返回值的说明
*************************************************/
void JX002::SlotBtnResponseRate()
{
	syncFIFO.SetResponseRate();
}

/*************************************************
Function: DrawPix		// 函数名称
Description: 渲染图像并在ui.label上显示	//函数描述
Input: QImage img 需要渲染的图像					// 函数输入
Return: 无					// 函数返回值的说明
*************************************************/
void JX002::DrawPix(QImage img)
{
	QImage  map(ui.label->width()-5, ui.label->height()-5, QImage::Format_RGB888);
	QPainter painter(&map);
	painter.drawImage(QRect(0, 0, ui.label->width()-5, ui.label->height()-5), img);
	painter.end();
	ui.label->setPixmap(QPixmap::fromImage(map));
}

/*************************************************
Function: SlotSaveDate		// 函数名称
Description: 槽函数  按钮saveDate发送是否保存数据成文件
Input: 
Return: 
*************************************************/
void JX002::SlotSaveDate()
{
	syncFIFO.SaveDate();

	if (syncFIFO.m_bisSaveDate == false)
	{
		ui.BtnSaveDate->setText(tr("数据保存成文件"));
	}
	else
	{
		ui.BtnSaveDate->setText(tr("停止数据保存成文件"));
	}
}


void JX002::SlotWhileDateInfo(QString info)
{
	ui.textEdit->append(info);
}

void JX002::SlotCleanTxt()
{
	ui.textEdit->clear();
}

/*************************************************
Function: SlotSaveDate		// 函数名称
Description: 槽函数  tabWidget页发生变化
Input:
Return:
*************************************************/
void JX002::SlotTabWidgetChanged(int index)
{
	//ui.stackedWidget->setCurrentIndex(index);
}