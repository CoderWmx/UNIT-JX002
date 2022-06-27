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
	
	ui.textEdit->document()->setMaximumBlockCount(15000); //������Ϣ�������������
	tableWidgetInit(ui.HtableWidget);//��ʼ�������б�
	tableWidgetInit(ui.LtableWidget);//��ʼ�������б�
	////���������б����Ӱ�ť
	//LBtn = new QPushButton;
	//LBtn->setIcon(QIcon(":/JX002/Res/add.png"));
	//ui.LtableWidget->setCellWidget(0, 3, LBtn);
	connect(ui.BtnAddL, &QPushButton::clicked, this, &JX002::SlotAddL);
	////���������б����Ӱ�ť
	//HBtn = new QPushButton;
	//HBtn->setIcon(QIcon(":/JX002/Res/add.png"));
	//ui.HtableWidget->setCellWidget(0, 3, HBtn);
	connect(ui.BtnAddH, &QPushButton::clicked, this, &JX002::SlotAddH);

	// ����ֱ��ͼ��ʽ
	QLinearGradient plotGradient;	//���ý���
	plotGradient.setStart(0, 0);
	plotGradient.setFinalStop(0, 350);
	plotGradient.setColorAt(0, QColor(80, 80, 80)); 
	plotGradient.setColorAt(1, QColor(50, 50, 50));
	//plotGradient.se(1, QColor(50, 50, 50));
//	ui.widget->xAxis->setLabelColor(QColor(255, 255, 0));
	ui.PlotWidget->xAxis->setTickLabelColor(QColor(164, 164, 164));
//	ui.widget->yAxis->setLabelColor(QColor(255, 255, 0));
	ui.PlotWidget->yAxis->setTickLabelColor(QColor(164, 164, 164));
	ui.PlotWidget->setBackground(plotGradient);//���ñ�����ɫ
	SlotRestAllListValue();
	SlotBtnSave();
}

void JX002::tableWidgetInit(QTableWidget* tabel)
{	
	tabel->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//ƽ�������п�
	//tabel->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);//ƽ�������п�
	tabel->horizontalHeader()->setVisible(false);
	tabel->verticalHeader()->setVisible(false);	
	//tabel->insertRow(tabel->rowCount()); //���
	//QTableWidgetItem *item = new QTableWidgetItem();
	//item->setText("���");
	//item->setTextAlignment(Qt::AlignCenter);
	//item->setFlags(item->flags() & (~Qt::ItemIsEnabled));
	//item->setBackground(QColor(34, 34, 34));	
	//tabel->setItem(0, 0, item);
	//
	//QTableWidgetItem *item1 = new QTableWidgetItem();
	//item1->setText("�¶�");
	//item1->setTextAlignment(Qt::AlignCenter);
	//item1->setFlags(item->flags() & (~Qt::ItemIsEnabled));
	//item1->setBackground(QColor(34, 34, 34));
	//tabel->setItem(0, 1, item1);
	//
	//QTableWidgetItem *item2 = new QTableWidgetItem();
	//item2->setText("��ֵ");
	//item2->setTextAlignment(Qt::AlignCenter);
	//item2->setFlags(item->flags() & (~Qt::ItemIsEnabled));
	//item2->setBackground(QColor(34, 34, 34));
	//tabel->setItem(0, 2, item2);
}

/*************************************************
Function: Imhistdate// ��������
Description: QCustomPlot QT��һ���ؼ�������һ��Widget���룬���������ǽ�Y14��ֵ��ֱ��ͼ����ʽչʾ����
Input: QCustomPlot * plot �ؼ�// QT��һ���ؼ�������һ��Widget����
QImage *img RGB�����ݣ�ÿ�����ص�0-255
Return: ��// ��������ֵ��˵��
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
	//  ��ֱ��ͼ�������ݴ���
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

	plot->xAxis->setRange(0, 256);  //x�᷶Χ
	plot->yAxis->setRange(0, (int)yrange);  //y�᷶Χ
	
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
Function: Imhistdate// ��������
Description: QCustomPlot QT��һ���ؼ�������һ��Widget���룬���������ǽ�Y14��ֵ��ֱ��ͼ����ʽչʾ����
Input: QCustomPlot * plot �ؼ�// QT��һ���ؼ�������һ��Widget����
		short *img Y14�����ݣ�short��16λ�Ľ��д����ʱ��Ҫ����2λ
Return: ��// ��������ֵ��˵��
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
	//  ��ֱ��ͼ�������ݴ���
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

	plot->xAxis->setRange(0, 16383);  //x�᷶Χ
	plot->yAxis->setRange(0, (int)yrange);  //y�᷶Χ
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
Function: SlotHistogram// ��������
Description: �ۺ�����������Ⱦֱ��ͼ��һ��ͼ��ģ����ҷֽ�ֱ��ͼ����
Input: QImage pix ��Ҫ��Ⱦ��ͼ��
short* grayimage Y14������
Return: ��// ��������ֵ��˵��
*************************************************/
void JX002::SlotHistogram(QImage pix, short* grayimage)
{
	ui.label_Original->setPixmap(QPixmap::fromImage(pix));
	Imhistdate(ui.PlotWidget, grayimage);
	//Imhist(ui.widget, &pix);
}

/*************************************************
Function: SlotAddL// ��������
Description: �ۺ�������ӵ��µ����б�ֵ
Input: ��
Return: ��// ��������ֵ��˵��
*************************************************/
void JX002::SlotAddL()
{
	AddItem(ui.LtableWidget);
}

/*************************************************
Function: SlotAddH// ��������
Description: �ۺ�������Ӹ��µ����б�ֵ
Input: ��
Return: ��// ��������ֵ��˵��
*************************************************/
void JX002::SlotAddH()
{
	AddItem(ui.HtableWidget);
}
/*************************************************
Function: AddItem// ��������
Description: ���б����ֵ
Input: QTableWidget ��Ӧ�Ŀؼ�
Return: ��// ��������ֵ��˵��
*************************************************/
void JX002::AddItem(QTableWidget* tabel,int temp, int sub)
{
	int row = tabel->rowCount();
	tabel->insertRow(row); //���
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
Function: SlotDeleteRow// ��������
Description: �ۺ��� ɾ��һ�����ݣ��Ҷ�ת�¶�  �ߵ��¶������ɾ��
Input:
Return: ��// ��������ֵ��˵��
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
Function: SlotBtnRestL// ��������
Description: �ۺ��������ûָ������б��Ĭ��ֵ
Input:��
Return: ��// ��������ֵ��˵��
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
Function: SlotBtnRestH// ��������
Description: �ۺ��������ûָ������б��Ĭ��ֵ
Input:��
Return: ��// ��������ֵ��˵��
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
Function: SlotRestCoefficient// ��������
Description: �ۺ��������ûָ������б��Ĭ��ֵ
Input:��
Return: ��// ��������ֵ��˵��
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
Function: SlotBtnSave// ��������
Description: �ۺ����������¶�ϵ��
Input:��
Return: ��// ��������ֵ��˵��
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
		syncFIFO.m_Larr[i][0] = LTempList.at(i)->item1->text().toFloat();  //�˵��µ�ϵ��
		syncFIFO.m_Larr[i][1] = LTempList.at(i)->item2->text().toFloat();
	}
	syncFIFO.m_nLarrCount = size;
	size = HTempList.size();
	for (int i = 0; i < size; i++)
	{
		syncFIFO.m_Harr[i][0] = HTempList.at(i)->item1->text().toFloat(); //�˸��µ�ϵ��
		syncFIFO.m_Harr[i][1] = HTempList.at(i)->item2->text().toFloat();
	}


}

/*************************************************
Function: SlotRestAllListValue// ��������
Description: ȫ�����ݻָ�Ĭ��
Input:��
Return: ��// ��������ֵ��˵��
*************************************************/
void JX002::SlotRestAllListValue()
{
	SlotRestCoefficient();
	SlotBtnRestH();
	SlotBtnRestL();
}

/*************************************************
Function: CleanAllList// ��������
Description: ��ոߵ��µ��б�
Input:QString type   == "H" ��ո��µ��б�   ��յ��µ��б�
Return: ��// ��������ֵ��˵��
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
Function: SlotHArrChange// ��������
Description: �ۺ��� �������鷢���仯
Input:
Return: ��// ��������ֵ��˵��
*************************************************/
void JX002::SlotHArrChange(QTableWidgetItem *item)
{

}
/*************************************************
Function: SlotLArrChange// ��������
Description: �ۺ��� �������鷢���仯
Input:
Return: ��// ��������ֵ��˵��
*************************************************/
void JX002::SlotLArrChange(QTableWidgetItem *item)
{
}
/*************************************************
Function: SlotOpenDev// ��������
Description: �ۺ��������豸 //��������
Input: ��	// ��������
Return: ��// ��������ֵ��˵��
*************************************************/
void JX002::SlotOpenDev()
{
	syncFIFO._startGetDate();
}

/*************************************************
Function: SlotStopDev// ��������
Description: �ۺ����� ֹͣ�豸 //��������
Input: ��	// ��������
Return: ��// ��������ֵ��˵��
*************************************************/
void JX002::SlotStopDev()
{
	syncFIFO.SlotStopthread();
}

/*************************************************
Function: SlotMessageBox// ��������
Description: �ۺ����� Message���� �� ��Ϣ���� //��������
Input: ��	// ��������
Return: ��// ��������ֵ��˵��
*************************************************/
void JX002::SlotMessageBox(QString info)
{
	//QMessageBox::information(this, "info", info);
	ui.textEdit->append(info);
}
/*************************************************
Function: SlotBtnMax// ��������
Description: �ۺ��� ������¶ȿ��� //��������
Input: ��	// ��������
Return: ��// ��������ֵ��˵��
*************************************************/
void JX002::SlotBtnMax()
{
}

/*************************************************
Function: SlotUSBDate// ��������
Description: �ۺ���  û�ã������ˣ��Ժ��Ƿ�����������ʱû�ã�//��������
Input: ��	// ��������
Return: ��// ��������ֵ��˵��
*************************************************/
void JX002::SlotUSBDate(QString date)
{
}

/*************************************************
Function: SlotBtnShutter		// ��������
Description: �ۺ���  �����	//��������
Input: ��					// ��������
Return: ��					// ��������ֵ��˵��
*************************************************/
void JX002::SlotBtnShutter()
{
}

/*************************************************
Function: SlotOutImage		// ��������
Description: �ۺ���  ���մ����QImage������Ⱦ	//��������
Input: QImage img ��Ҫ��Ⱦ��ͼ��					// ��������
Return: ��					// ��������ֵ��˵��
*************************************************/
void JX002::SlotOutImage(QImage img)
{
	DrawPix(img);
}
/*************************************************
Function: SlotBtnMin		// ��������
Description: �ۺ���  ����¶ȿ���	//��������
Input: ��					// ��������
Return: ��					// ��������ֵ��˵��
*************************************************/
void JX002::SlotBtnMin()
{

}
/*************************************************
Function: SlotBtnCenter		// ��������
Description: �ۺ���  �����¶ȿ���	//��������
Input: ��					// ��������
Return: ��					// ��������ֵ��˵��
*************************************************/
void JX002::SlotBtnCenter()
{

}

/*************************************************
Function: SlotBtnGetPix		// ��������
Description: �ۺ���  �ؼ���ȡͼ��ť���Ӳۣ�����USB��ȡͼ��	//��������
Input: ��					// ��������
Return: ��					// ��������ֵ��˵��
*************************************************/
void JX002::SlotBtnGetPix()
{
	syncFIFO.StartGetPix();
}

/*************************************************
Function: SlotBtnResponseRate		// ��������
Description: �ۺ���  �ؼ�������Ӧ�ʽӲ�	//��������
Input: ��					// ��������
Return: ��					// ��������ֵ��˵��
*************************************************/
void JX002::SlotBtnResponseRate()
{
	syncFIFO.SetResponseRate();
}

/*************************************************
Function: DrawPix		// ��������
Description: ��Ⱦͼ����ui.label����ʾ	//��������
Input: QImage img ��Ҫ��Ⱦ��ͼ��					// ��������
Return: ��					// ��������ֵ��˵��
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
Function: SlotSaveDate		// ��������
Description: �ۺ���  ��ťsaveDate�����Ƿ񱣴����ݳ��ļ�
Input: 
Return: 
*************************************************/
void JX002::SlotSaveDate()
{
	syncFIFO.SaveDate();

	if (syncFIFO.m_bisSaveDate == false)
	{
		ui.BtnSaveDate->setText(tr("���ݱ�����ļ�"));
	}
	else
	{
		ui.BtnSaveDate->setText(tr("ֹͣ���ݱ�����ļ�"));
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
Function: SlotSaveDate		// ��������
Description: �ۺ���  tabWidgetҳ�����仯
Input:
Return:
*************************************************/
void JX002::SlotTabWidgetChanged(int index)
{
	//ui.stackedWidget->setCurrentIndex(index);
}