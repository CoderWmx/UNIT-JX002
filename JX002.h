#pragma once

#include <QtWidgets/QMainWindow>
#include <QtCharts/QtCharts>

			
QT_CHARTS_USE_NAMESPACE
#include "ui_JX002.h"
//#include "./USB/getusbdate.h"
#include <QTableWidgetItem>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <vector>
#include "syncFIFO.h"

using namespace std;
using namespace cv;

struct TreeItem {
	QTableWidgetItem * item;
	QTableWidgetItem * item1;
	QTableWidgetItem * item2;
	QPushButton * Btn;
};
class JX002 : public QMainWindow
{
    Q_OBJECT

public:
    JX002(QWidget *parent = Q_NULLPTR);

	void DrawPix(QImage img);
	
	void Imhist(QCustomPlot * plot, QImage *img);
	void Imhistdate(QCustomPlot * plot, short *img);
	void tableWidgetInit(QTableWidget* tabel);
	//void AddItem(QTableWidget * tabel);
	void AddItem(QTableWidget * tabel, int temp = 0, int sub = 100);
	void CleanAllList(QString type);
public slots:
	void SlotWhileDateInfo(QString info);
	void SlotSaveDate();
	void SlotDeleteRow();

	void SlotBtnRestL();

	void SlotBtnRestH();

	void SlotRestCoefficient();

	void SlotBtnSave();

	void SlotRestAllListValue();

	void SlotHArrChange(QTableWidgetItem *item);
	void SlotLArrChange(QTableWidgetItem *item);
	void SlotOpenDev();
	void SlotMessageBox(QString info);
	void SlotStopDev();
	void SlotBtnMax();
	void SlotBtnMin();
	void SlotBtnCenter();
	void SlotBtnShutter();
	void SlotBtnGetPix();
	void SlotBtnResponseRate();
	void SlotUSBDate(QString);
	void SlotOutImage(QImage img);
	void SlotHistogram(QImage pix, short* grayimage);
	void SlotAddL();
	void SlotAddH();
	
	void SlotCleanTxt();
	void SlotTabWidgetChanged(int index);
private:
    Ui::JX002Class ui;
	QImage histPix;
	QCPBars *m_pbars = NULL;
	syncFIFO  syncFIFO;
	QList<TreeItem*> m_ListBtn;
	//QPushButton *HBtn = NULL;
	//QPushButton *LBtn = NULL;
};
