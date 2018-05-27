/**********************************************************************************************************
                                天穹飞控 —— 致力于打造中国最好的多旋翼开源飞控
                                Github: github.com/loveuav/BlueSkyFlightControl
                                技术讨论：bbs.loveuav.com/forum-68-1.html
 * @文件     drv_subs.c
 * @说明     sbus接收机协议解析
 * @版本  	 V1.0
 * @作者     BlueSky
 * @网站     bbs.loveuav.com
 * @日期     2018.05 
**********************************************************************************************************/
#include "drv_sbus.h"
#include "drv_usart.h"

RCDATA_t sbusData;
static void Sbus_Decode(uint8_t data);
static RcDataCallback rcDataCallbackFunc;

/**********************************************************************************************************
*函 数 名: Sbus_Init
*功能说明: sbus数据解析初始化
*形    参: 无
*返 回 值: 无
**********************************************************************************************************/
void Sbus_Init(void)
{
    //设置SBUS串口接收中断回调函数（即数据协议解析函数）
    Usart_SetIRQCallback(SBUS_UART, Sbus_Decode);
}

/**********************************************************************************************************
*函 数 名: Sbus_Decode
*功能说明: sbus协议解析
*形    参: 输入数据
*返 回 值: 无
**********************************************************************************************************/
static void Sbus_Decode(uint8_t data)
{  
    //一帧数据解析完成
	if(rcDataCallbackFunc != 0)
		(*rcDataCallbackFunc)(sbusData);
}


/**********************************************************************************************************
*函 数 名: Sbus_SetRcDataCallback
*功能说明: 设置遥控数据处理回调函数
*形    参: 回调函数
*返 回 值: 无
**********************************************************************************************************/
void Sbus_SetRcDataCallback(RcDataCallback rcDataCallback)
{
	rcDataCallbackFunc = rcDataCallback;
}

