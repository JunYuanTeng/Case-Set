#include "basal.h"

/*
40 问题编号：VBUG00020618
40.1 问题概述
软件名称：IPU
问题类型： 无符号整数上溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2017年
40.2 问题分析
软件计算A=B*1000000，A为64位无符号整型，B为32位无符号整型，在计算时不会自动提升为64位，故会导致溢出，当B超过4294时即会溢出。
*/

unsigned long long A;
unsigned int B;

unsigned int ADDR_B = 0x21002000;

void case040(void)
{
	B = READ_ADDR_UI32(ADDR_B);

	A = B * 1000000;

	return;
}
