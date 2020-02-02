#include "basal.h"

/*
64 问题编号：VBUG00005400
64.1 问题概述
软件名称：XHCL
问题类型： 无符号整数上溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2012年
64.2 问题分析
针对程序533~534、651~652行使用除法运算时，未对除数进行除零保护。
*/
int dataCollected[3];

void CollectData(int value[])
{
	value[2] = value[1] / value[0];

	return;
}

void case064(void)
{
	CollectData(dataCollected);

	return;
}

