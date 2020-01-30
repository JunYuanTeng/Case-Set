#include "basal.h"

/*
55 问题编号：VBUG00031442
55.1 问题概述
软件名称： GK2115
问题类型： 无符号整数上溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2018年
55.2 问题分析
32位无符号变量cntPeriod64ms，每控制周期（64ms）加1，约8.7年后溢出清零。溢出时将导致软件中的%7、%100计算发生跳变。建议对此完善设计。

*/

unsigned int cntPeriod64ms;

void case055(void)
{
	cntPeriod64ms++;

	return;
}
