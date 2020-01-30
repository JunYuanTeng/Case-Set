#include "basal.h"

/*
71 问题编号：VBUG00022103
71.1 问题概述
软件名称：NYGL
问题类型： 无符号整数上溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2017年
71.2 问题分析
软件在2533行计算模拟量补偿值：JZADV2[i] = (JZADV1[i] - JZVgnd) / JZa，计算公式中，JZa无法保证不为0，建议增加除0保护。
*/

#define NUM_JZA 12

#define ADDR_JZVgnd 0x20100010
#define ADDR_JZa    0x20100004
#define ADDR_JZADV  0x20100020

double JZADV2[NUM_JZA];
double JZADV1[NUM_JZA];
double JZVgnd;
double JZa;

void case071(void)
{
	int i;

	JZVgnd = READ_ADDR_SI32(ADDR_JZVgnd);
	JZa = READ_ADDR_SI32(ADDR_JZa);

	for (i = 0; i < NUM_JZA; i++)
	{
		JZADV1[i] = READ_ADDR_SI32(ADDR_JZADV + i * 4);
		JZADV2[i] = (JZADV1[i] - JZVgnd) / JZa;
	}

	return;
}
