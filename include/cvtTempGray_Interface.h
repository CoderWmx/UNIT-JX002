#pragma once
#define IN
#define OUT
#define INOUT
#define OK  (1)
#define FAIL (-1)


/*tec�����㷨�ṹ����� ����˵��*/
typedef struct {
	float temp0;  //(TEC0)  ���±궨TEC�¶�ֵ
	float tempCur;//(TEC��ǰ��  ��ǰTEC�¶�ֵ
	float self_com;//(self_com)  �Զ�����ֵ
	int  segFlag; //�ֶα�ţ�����µ�8�����µ�3��
	float offset[3];//����ϵ��
	char enable; //tec�����㷨ʹ�ܿ��أ� 0-�أ�1-��
	char res[3];
}tecCompensationParam;

typedef struct {
	tecCompensationParam tecParam;
	int res[56];
}stParamOffset;

typedef int status;

/*���ݻҶȼ���Ŀ���¶��¶�  ����˵��
���룺
float baseTemp: ��׼�¶�ֵ
float baseGray_corr;��׼�¶ȶ�Ӧ�Ҷ�ֵ��Ĭ��4096
float tarGray:Ŀ��Ҷ�ֵ
float drifTemp:��Ư������Ĭ��0
float diffTable[n][2]:�ҶȲ�ֵ�ͺ����¶ȹ�ϵ����ά���飬��һ��Ϊ�����¶ȣ��ڶ����ǻҶ�ֵ
int n����ϵ���У���Ч������������diffTable����ĵ�0ά����
float drifTemp;��Ư������Ĭ��1

ERROR INFO����-999999�� ���±궨���¶�˳��ǵ���
ERROR INFO����-888888�������¶�Խ��
*/
__declspec(dllexport) float getTarTemp(float baseTemp, float baseGray_corr, float tarGray, float drifTemp, float diffTable_ori[][2], int n, stParamOffset *stParamTotal);

/*�����¶ȼ���Ŀ��Ҷ� ����˵��
���룺
float baseTemp: ��׼�¶�ֵ
float baseGray_corr;��׼�¶ȶ�Ӧ�Ҷ�ֵ
float tarTemp:Ŀ���¶�ֵ
float diffTable[n][2]:�ҶȲ�ֵ�ͺ����¶ȹ�ϵ����ά���飬��һ��Ϊ�����¶ȣ��ڶ����ǻҶ�ֵ
int n����ϵ���У���Ч������������diffTable����ĵ�0ά����

ERROR INFO����-999999�� ���±궨���¶�˳��ǵ���
ERROR INFO����-888888�������¶�Խ��
*/
__declspec(dllexport) float getTarGary(float baseTemp, float baseGray_corr, float tarTemp, float diffTable[][2], int n, stParamOffset *stParam);

/*�����ʷ���Ҷȼ���Ŀ����ʵ�Ҷ�ֵ ����˵��
���룺
float eps��������
float grayInstru�������Ҷ�ֵ
float grayReflex������Ҷ�ֵ

ERROR INFO����-777777��������ϵ��Ϊ0

*/
__declspec(dllexport) float getGrayTruth(float eps, float grayInstru, float grayReflex);


///* Զ���벹���¶Ȳ����㷨һ ����˵��
//���룺
//float bareTemperature:δ���������¶�,��λ��
//float longDistance���������,��λm
//float diffTable[8]:���벹��ϵ��
//
//ERROR INFO����-666666���������Ϊ����
//*/
//float getTarTemperCompensation(float bareTemperature, float longDistance,float diffTable[8]);

///*Զ���벹���¶Ȳ����㷨���� ����˵��
//���룺
//float bareTemperature:δ���������¶�,��λ��
//float ft_ld��������ֵ ��λm
//float ft_hd��Զ����ֵ ��λm
//float ft_ht1�����º����� ft_ld ���Ĳ���ֵ
//float ft_lt1�����º����� ft_ld ���Ĳ���ֵ
//float ft_ht2�����º����� ft_hd ���Ĳ���ֵ
//float ft_lt2�����º����� ft_hd ���Ĳ���ֵ
//
//ERROR INFO����-111111���������Ϊ����
//
//*/
//float  getTarTemperCompensation2(float bareTemperature, float longDistance, float ft_ld, float ft_hd,float ft_ht1, float ft_lt1, float ft_ht2,float ft_lt2);

/*FinalԶ���벹���¶Ȳ����㷨 ����˵��
���룺
float bareTemperature:δ���������¶�,��λ��
float longDistance���������,��λm
float caliDistance��У׼���룬��λm
float diffTable[8]:���벹��ϵ��
float ft_ld��������ֵ ��λcm
float ft_hd��Զ����ֵ ��λcm
float ft_ht1�����º����� ft_ld ���Ĳ���ֵ
float ft_lt1�����º����� ft_ld ���Ĳ���ֵ
float ft_ht2�����º����� ft_hd ���Ĳ���ֵ
float ft_lt2�����º����� ft_hd ���Ĳ���ֵ

int enble;ʹ�ܿ��أ���1���ر�0.Ĭ����1
ERROR INFO����-666666���������Ϊ����
*/
__declspec(dllexport) float  getFinalTarTemperCompensation(float bareTemperature, float longDistance, float caliDistance, float diffTable[8], float ft_ld, float ft_hd, float ft_ht1, float ft_lt1, float ft_ht2, float ft_lt2,int enble);



/*���뻷���¶ȡ�ʪ�Ⱥʹ���������͸���� ����˵��
���룺
float realDist���������������͸���ʼ��㣩����λcm
float Envitemper�������¶�
float Hum:ʪ�ȣ���λ%

ERROR INFO����-444444��ʪ��С��0�����100ʱ����
*/
__declspec(dllexport) float get_RealHumTrans(float Envitemper, float Hum, float realDist);



//*����ʪ�ȡ������¶ȡ������ʡ������¶ȡ�ָʾ�¶��Լ����� ����˵��
//���룺
//float Hum:ʪ�ȣ���λ%
//float eps��������
//float EnvironmentTemper�������¶�
//float AtmosTemper�������¶�
//float IndiTemper��ָʾ�¶�
//float trans��͸����
//ERROR INFO����-555555��:͸����С��0
//
//*/
__declspec(dllexport) float getTarRealTemper(float Hum, float eps, float IndiTemper, float EnvironmentTemper, float AtmosTemper, float trans);



/* demo */
/*==========================================================
int main()
{

//�Ҷȱ�ͺ����¶ȹ�ϵ��2ά���飬��һ���Ǻ����¶ȣ��ڶ���Ϊ�Ҷ�ֵ
/***********************���µ�**********************************/
//float diffTable[20][2] = {

//	-30,    0.0,//0
//	-20,	235.0,
//	-10,	289.0,
//	0,	    335.0,
//	10,  	373.0,//4
//	20, 	386.0,
//	30, 	448.0,
//	40, 	496.0,
//	50, 	534.0,
//	60, 	579.0,
//	70, 	620.0,//10
//	80, 	661.0,
//	90, 	701.0,
//	100,	761.0,
//	110,	821.0,
//	120,	881.0,
//	130,	927.0,
//	140,	974.0,
//	150,	1020.0,//18
//  160,    1035.0
//};

/*************************���µ�*******************************
float diffTable[19][2] = {

	-30,	 0.0,//0
	10,     105.0,
	50,	    179.0,
	90,	    238.0,
	130,	328.0,//4
	170,	404.0,
	210,	478.0,
	250,	553.0,
	290,    628.0,
	330,	703.0,
	370,	778.0,
	410,	854.0,
	450,	919.0,
	490,	984.0,
	530,	1050.0,
	570,	1115.0,//15  

};

int n = 16;//��Ч���ݼ�¼����

float baseTemp = 43.7f;//��׼�¶�
float baseGray_corr = 8192;//��׼�¶ȶ�Ӧ�Ҷ�ֵ
float tarGray = 8800;//Ŀ��Ҷ�ֵ
float tarTemp = 54.9f;//Ŀ���¶�ֵ
float longDistance = 10.f;//Ŀ����룬��λm
float caliDistance = 10.f;//У׼���룬��λm
float B_diffTable[8] = { -4.93402944994933f,2.28986549940018f,1.03131550494217f,-0.457537979056656f,-0.000360948613934302f,0.0159964881698997f,0.0232531651017539f,-0.0000811805056848589f };//���벹��ϵ��

float Hum = 0.5f;//ʪ��50%
float eps = 0.97f;
float EnvironmentTemper = 25.0f;
float AtmosTemper = 25.0f;
float LongDist_trans = 2.0f;

stParamOffset stParam1 = {

	{
		50.0f,      //(TEC)        ���±궨TEC�¶�ֵ
		45.0f,     //��TEC��ǰ��  ��ǰTEC�¶�ֵ
	2.0f,     //(self_com)   �Զ�����ֵ
	3,        //�ֶα��
	{ 0.9f,1.0f,1.1f }, //offset[3]  ����ϵ��
	1,               //enable
	{ 0,0,0 }
	},
	{ 0 }
};


stParamOffset stParam2 = {

	{
		50.0f,      //(TEC)        ���±궨TEC�¶�ֵ
		31.8f,     //��TEC��ǰ��  ��ǰTEC�¶�ֵ
	20.0f,     //(self_com)   �Զ�����ֵ
	6,        //�ֶα��
	{ 1.1f,1.0f,1.1f }, //offset[3]  ��a��b��c������ϵ��
	0,               //enable
	{ 0,0,0 }
	},
	{ 0 }
};

//demo ���ݻҶȼ���Ŀ���¶�(ָʾ�¶�)  
float result_Temp = getTarTemp(baseTemp, baseGray_corr, tarGray, diffTable, n, &stParam1);

//demo �����¶ȼ���Ŀ��Ҷ� 
float result_Gary = getTarGary(baseTemp, baseGray_corr, result_Temp, diffTable, n, &stParam1);

//demo ����ָʾ�¶ȼ��㲻ͬ�����¶ȡ������ʡ������¶ȡ�͸��������ʵ�¶�
float result_Temper = getTarRealTemper(Hum, LongDist_trans, eps, result_Temp, EnvironmentTemper, AtmosTemper);


//demo ������ʵ�¶������ݼ���Զ�����¶Ȳ���ֵ
float result_DistTemp = getTarTemperCompensation(result_Temper, longDistance,caliDistance, B_diffTable);

//demo ���ݻ����¶ȡ�ʪ�ȡ��������͸����
float result_trans = get_RealHumTrans(EnvironmentTemper, Hum, LongDist_trans);

printf("result_Temp��%.2f\n\n", result_Temp);
printf("result_Gary��%.2f\n\n", result_Gary);
printf("result_Temper��%.2f\n\n", result_Temper);
printf("result_DistTemp��%.2f\n\n", result_DistTemp);
printf("result_trans��%.3f��\n\n", result_trans);


system("pause");

return 0;
}

*/