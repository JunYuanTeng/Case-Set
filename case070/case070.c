#include "basal.h"

/*
70 问题编号：VBUG00022009
70.1 问题概述
软件名称：NYGL
问题类型： 无符号整数上溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2017年
70.2 问题分析
软件在2533行计算模拟量补偿值：JZADV2[i] = (JZADV1[i] - JZVgnd) / JZa，计算公式中，JZa无法保证不为0，建议增加除0保护。
*/

#define NUM_JZA 12

#define ADDR_JZVgnd 0x20100010
#define ADDR_JZa    0x20100004
#define ADDR_JZADV  0x20100020

int JZADV2[NUM_JZA];
int JZADV1[NUM_JZA];
int JZVgnd;
int JZa;

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
