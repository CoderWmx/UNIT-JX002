#pragma once
#define IN
#define OUT
#define INOUT
#define OK  (1)
#define FAIL (-1)


/*tec补偿算法结构体参数 函数说明*/
typedef struct {
	float temp0;  //(TEC0)  常温标定TEC温度值
	float tempCur;//(TEC当前）  当前TEC温度值
	float self_com;//(self_com)  自动补偿值
	int  segFlag; //分段标号（如低温档8，高温档3）
	float offset[3];//补偿系数
	char enable; //tec补偿算法使能开关， 0-关，1-开
	char res[3];
}tecCompensationParam;

typedef struct {
	tecCompensationParam tecParam;
	int res[56];
}stParamOffset;

typedef int status;

/*根据灰度计算目标温度温度  函数说明
输入：
float baseTemp: 基准温度值
float baseGray_corr;基准温度对应灰度值，默认4096
float tarGray:目标灰度值
float drifTemp:温漂补偿，默认0
float diffTable[n][2]:灰度差值和黑体温度关系表：二维数组，第一列为黑体温度，第二列是灰度值
int n：关系表中，有效数据行数。即diffTable数组的第0维数组
float drifTemp;温漂补偿，默认1

ERROR INFO：（-999999） 测温标定表温度顺序非递增
ERROR INFO：（-888888）基础温度越界
*/
__declspec(dllexport) float getTarTemp(float baseTemp, float baseGray_corr, float tarGray, float drifTemp, float diffTable_ori[][2], int n, stParamOffset *stParamTotal);

/*根据温度计算目标灰度 函数说明
输入：
float baseTemp: 基准温度值
float baseGray_corr;基准温度对应灰度值
float tarTemp:目标温度值
float diffTable[n][2]:灰度差值和黑体温度关系表：二维数组，第一列为黑体温度，第二列是灰度值
int n：关系表中，有效数据行数。即diffTable数组的第0维数组

ERROR INFO：（-999999） 测温标定表温度顺序非递增
ERROR INFO：（-888888）基础温度越界
*/
__declspec(dllexport) float getTarGary(float baseTemp, float baseGray_corr, float tarTemp, float diffTable[][2], int n, stParamOffset *stParam);

/*辐射率反射灰度计算目标真实灰度值 函数说明
输入：
float eps：辐射率
float grayInstru：仪器灰度值
float grayReflex：反射灰度值

ERROR INFO：（-777777）辐射率系数为0

*/
__declspec(dllexport) float getGrayTruth(float eps, float grayInstru, float grayReflex);


///* 远距离补偿温度补偿算法一 函数说明
//输入：
//float bareTemperature:未补偿的裸温度,单位℃
//float longDistance：距离参数,单位m
//float diffTable[8]:距离补偿系数
//
//ERROR INFO：（-666666）距离参数为负数
//*/
//float getTarTemperCompensation(float bareTemperature, float longDistance,float diffTable[8]);

///*远距离补偿温度补偿算法二： 函数说明
//输入：
//float bareTemperature:未补偿的裸温度,单位℃
//float ft_ld：近距离值 单位m
//float ft_hd：远距离值 单位m
//float ft_ht1：高温黑体在 ft_ld 处的测量值
//float ft_lt1：低温黑体在 ft_ld 处的测量值
//float ft_ht2：高温黑体在 ft_hd 处的测量值
//float ft_lt2：低温黑体在 ft_hd 处的测量值
//
//ERROR INFO：（-111111）距离参数为负数
//
//*/
//float  getTarTemperCompensation2(float bareTemperature, float longDistance, float ft_ld, float ft_hd,float ft_ht1, float ft_lt1, float ft_ht2,float ft_lt2);

/*Final远距离补偿温度补偿算法 函数说明
输入：
float bareTemperature:未补偿的裸温度,单位℃
float longDistance：距离参数,单位m
float caliDistance：校准距离，单位m
float diffTable[8]:距离补偿系数
float ft_ld：近距离值 单位cm
float ft_hd：远距离值 单位cm
float ft_ht1：高温黑体在 ft_ld 处的测量值
float ft_lt1：低温黑体在 ft_ld 处的测量值
float ft_ht2：高温黑体在 ft_hd 处的测量值
float ft_lt2：低温黑体在 ft_hd 处的测量值

int enble;使能开关，打开1，关闭0.默认是1
ERROR INFO：（-666666）距离参数为负数
*/
__declspec(dllexport) float  getFinalTarTemperCompensation(float bareTemperature, float longDistance, float caliDistance, float diffTable[8], float ft_ld, float ft_hd, float ft_ht1, float ft_lt1, float ft_ht2, float ft_lt2,int enble);



/*输入环境温度、湿度和传输距离计算透过率 函数说明
输入：
float realDist：距离参数（用于透过率计算），单位cm
float Envitemper：环境温度
float Hum:湿度，单位%

ERROR INFO：（-444444）湿度小于0或大于100时报错
*/
__declspec(dllexport) float get_RealHumTrans(float Envitemper, float Hum, float realDist);



//*输入湿度、环境温度、发射率、大气温度、指示温度以及距离 函数说明
//输入：
//float Hum:湿度，单位%
//float eps：辐射率
//float EnvironmentTemper：环境温度
//float AtmosTemper：大气温度
//float IndiTemper：指示温度
//float trans：透过率
//ERROR INFO：（-555555）:透过率小于0
//
//*/
__declspec(dllexport) float getTarRealTemper(float Hum, float eps, float IndiTemper, float EnvironmentTemper, float AtmosTemper, float trans);



/* demo */
/*==========================================================
int main()
{

//灰度表和黑体温度关系表，2维数组，第一列是黑体温度，第二列为灰度值
/***********************低温档**********************************/
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

/*************************高温档*******************************
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

int n = 16;//有效数据记录行数

float baseTemp = 43.7f;//基准温度
float baseGray_corr = 8192;//基准温度对应灰度值
float tarGray = 8800;//目标灰度值
float tarTemp = 54.9f;//目标温度值
float longDistance = 10.f;//目标距离，单位m
float caliDistance = 10.f;//校准距离，单位m
float B_diffTable[8] = { -4.93402944994933f,2.28986549940018f,1.03131550494217f,-0.457537979056656f,-0.000360948613934302f,0.0159964881698997f,0.0232531651017539f,-0.0000811805056848589f };//距离补偿系数

float Hum = 0.5f;//湿度50%
float eps = 0.97f;
float EnvironmentTemper = 25.0f;
float AtmosTemper = 25.0f;
float LongDist_trans = 2.0f;

stParamOffset stParam1 = {

	{
		50.0f,      //(TEC)        常温标定TEC温度值
		45.0f,     //（TEC当前）  当前TEC温度值
	2.0f,     //(self_com)   自动补偿值
	3,        //分段标号
	{ 0.9f,1.0f,1.1f }, //offset[3]  补偿系数
	1,               //enable
	{ 0,0,0 }
	},
	{ 0 }
};


stParamOffset stParam2 = {

	{
		50.0f,      //(TEC)        常温标定TEC温度值
		31.8f,     //（TEC当前）  当前TEC温度值
	20.0f,     //(self_com)   自动补偿值
	6,        //分段标号
	{ 1.1f,1.0f,1.1f }, //offset[3]  （a，b，c）补偿系数
	0,               //enable
	{ 0,0,0 }
	},
	{ 0 }
};

//demo 根据灰度计算目标温度(指示温度)  
float result_Temp = getTarTemp(baseTemp, baseGray_corr, tarGray, diffTable, n, &stParam1);

//demo 根据温度计算目标灰度 
float result_Gary = getTarGary(baseTemp, baseGray_corr, result_Temp, diffTable, n, &stParam1);

//demo 根据指示温度计算不同环境温度、发射率、大气温度、透过率下真实温度
float result_Temper = getTarRealTemper(Hum, LongDist_trans, eps, result_Temp, EnvironmentTemper, AtmosTemper);


//demo 根据真实温度裸数据计算远距离温度补偿值
float result_DistTemp = getTarTemperCompensation(result_Temper, longDistance,caliDistance, B_diffTable);

//demo 根据环境温度、湿度、距离计算透过率
float result_trans = get_RealHumTrans(EnvironmentTemper, Hum, LongDist_trans);

printf("result_Temp：%.2f\n\n", result_Temp);
printf("result_Gary：%.2f\n\n", result_Gary);
printf("result_Temper：%.2f\n\n", result_Temper);
printf("result_DistTemp：%.2f\n\n", result_DistTemp);
printf("result_trans：%.3f℃\n\n", result_trans);


system("pause");

return 0;
}

*/