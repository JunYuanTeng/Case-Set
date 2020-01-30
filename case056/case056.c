#include "basal.h"

/*
56 问题编号：VBUG00033459
56.1 问题概述
软件名称： GTCCQ
问题类型： 无符号整数下溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2019年
56.2 问题分析
函数CloseTimer中，未判断GTI.ValuableTimerNum大于0就进行--操作，存在数据溢出风险
*/

typedef struct  
{
	unsigned int ValuableTimerNum;
} SGTI;

SGTI GTI;

void CloseTimer(void)
{
	GTI.ValuableTimerNum--;
}

void case056(void)
{
	CloseTimer();

	return;
}
