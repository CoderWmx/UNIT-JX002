#pragma once
#include <QThread>
#include <QObject>
#include "ftd2xx.h"

#include <QMutex>
#include <QImage>
#include <QQueue>
#include <thread>
#define MAXBUFSIZE 65536//65536 
//#define MAXBUFSIZE 240000//65536 
#define BUF_4M 240016*6
#define Y16_SIZE 300*400*2
#include "opencv2/imgcodecs.hpp"
#include "opencv2/videoio/videoio.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include "opencv2/photo.hpp"
#include "opencv2/imgproc/types_c.h"

enum USBDATETYPE
{
	GET_Y16_DATE = 1,			// ����λ�������ȡͼ������	
	RETURN_Y16_DATE = 2,		// ��λ������ͼ������	
	GET_KB_VALUE = 3,			// ����λ�������ȡKBֵ����
	RETURN_KB_VALUE = 4,		// ��λ������KB����
	SET_CLEAN_FLASH = 5,		// ����λ���������flash
	RETURN_REQUEST_ONCE_KB = 6,	// ��λ��������һ��KBֵ
	SET_ONCE_KB = 7,			// ����λ������һ��KB
	SET_RESPONSERATE = 8,		// ����̽������Ӧ��
	
};

class syncFIFO : public QThread
{
	Q_OBJECT
public:
	syncFIFO();
	~syncFIFO();

	bool SyncFIFO_Initial(FT_HANDLE ftHandle);
	void _startGetDate();
	void pushDate(unsigned char * orgData, int len);
	bool m_bISGetUSBDate = false;
	void StartGetPix();
	void GetKBvalue();
	void SetResponseRate();
	void run();
	void Y16TORGB(unsigned short* y16, char* outrgb, int w, int h);	
	void analysisRun();
	QImage Show8BitQimage(unsigned short* y16, int w, int h);	
	void SaveDate();
	void SaveY16Date(unsigned char * y16);
	void analysisY16Date(unsigned char * pd);
	void memsetbuf();
	FILE *infile;	
	FT_STATUS ftStatus = FT_OK;			//Status defined in D2XX to indicate operation result
										//FT_HANDLE ftHandle=0;
	bool m_bisSaveDate = false;
	DWORD dwNumBytesToSend = 0; 	//Index of output buffer
	DWORD dwNumBytesSent = 0;
	DWORD dwNumBytesRead = 0;
	DWORD dwNumInputBuffer = 0;
	//DWORD totalreadbyte = 0;
	BYTE DataOutBuffer[MAXBUFSIZE];
	BYTE DataInBuffer[MAXBUFSIZE];
	
	FT_HANDLE ftdiHandle;
	QMutex m_mutex;		//
	bool m_bisSenY16 = false;		// �Ƿ���һ��ͼ��

	char buf[Y16_SIZE];
	int outTemp = 25;
	std::thread* run1;
	QQueue<unsigned char*> m_Listbuf;
	QVector<QRgb> grayTable;        //������ɫ��


	std::shared_ptr<unsigned char > m_spbuf;
	int buf_max_len;
	int buf_len;
	float m_Larr[100][2];
	float m_Harr[100][2];
	int m_nLarrCount = 0;
	int m_nHarrCount = 0;
signals:
	void SigOutErrorInfo(QString error);
	void SigOutImage(QImage);
	void SigHistogram(QImage, short*);
	void SigWhileDateInfo(QString);
public slots:
	void SlotStopthread();
	void SlotGetOneY16();
	
};

