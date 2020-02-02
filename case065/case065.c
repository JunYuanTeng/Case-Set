#include "basal.h"

/*
65 问题编号：VBUG00005401
65.1 问题概述
软件名称：XHCL
问题类型： 无符号整数上溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2012年
65.2 问题分析
软件定义g_dTargetPowerMax为信号功率极值，在输出测量数据时采用如下表达式计算当前噪声门限：
temp = 10*log10(g_dTargetPowerMax*DELTA_NEAR/g_dNoisePower);
temp = 10*log10(g_dTargetPowerMax*DELTA_FAR/g_dNoisePower);
由于软件未对g_dTargetPowerMax和g_dNoisePower为0的情况进行保护，导致计算结果出现10*log10（0）或者除数为0的情况，造成计算错误。
*/

extern int log10(double);

#define DELTA_NEAR 0.125
#define DELTA_FAR  0.5

int g_dTargetPowerMax;
int g_dNoisePower;

void case065(int powerNow)
{
	int temp1;
	int temp2;

	temp1 = 10 * log10(g_dTargetPowerMax*DELTA_NEAR/g_dNoisePower);
	temp2 = 10 * log10(g_dTargetPowerMax*DELTA_FAR/g_dNoisePower);

	if (powerNow < temp1)
	{
		/* to do something */
	} 
	else if (powerNow > temp2)
	{
		/* to do something */
	}
	else
	{
		/* to do something */
	}

	return;
}
