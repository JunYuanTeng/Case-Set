#include "basal.h"

/*
63 问题编号：VBUG00004290
63.1 问题概述
软件名称：XJRK
问题类型： 无符号整数上溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2012年
63.2 问题分析
在函数CollectData()中，程序381行和385行，当value[1]和value[0]相等时分母为零，会造成除零操作，对除零运算没有进行保护。
*/

int dataCollected[4];

void CollectData(int value[])
{
	value[3] = value[2] / (value[1] - value[0]);

	return;
}

void case063(void)
{
	CollectData(dataCollected);

	return;
}
