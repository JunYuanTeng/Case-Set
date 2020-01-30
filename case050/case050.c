#include "basal.h"

/*
50 问题编号：VBUG00027489
50.1 问题概述
软件名称： DHJSJ
问题类型： 有符号整数上溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2018年
50.2 问题分析
代码中Selftest.c的L704行将变量sdram_count指定为char型数组，
在L721行的循环体内对其进行+1操作，循环次数远大于char型变量表示范围，
可能导致变量sdram_count溢出，之后在L730行对其判if的结果可能是不准确的
*/

#define ADDR_RAM 0x2000000
#define SIZE_RAM 0x8000

void case050(void)
{
	int i;
	char sdram_count;
	unsigned int valRam;

	sdram_count = 0;
	for (i = 0; i < SIZE_RAM; i = i + 4)
	{
		valRam = READ_ADDR_UI32(ADDR_RAM + i);
		if (0xFFFFFFFF == valRam)
		{
			/* 可能溢出 */
			sdram_count++;
		}
	}

	/* 判断可能不准确 */
	if (sdram_count == 0x37)
	{
		/* to do something */
	}

	return;
}
