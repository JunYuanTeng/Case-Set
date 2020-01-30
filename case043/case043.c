#include "basal.h"

/*
43 问题编号：VBUG00021798
43.1 问题概述
软件名称： TXXY
问题类型： 无符号整数下溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2017年
43.2 问题分析
bootloader主程序中，连续3次程序加载失败时，类型为uint32_t（unsigned int）的loadresult被赋值为ERROR（值为-1），出现非预期的数据溢出。
*/

#define ERROR (-1)

unsigned int loadFailCnt;
unsigned int loadresult;

void case043(void)
{
	if (loadFailCnt >= 3)
	{
		loadresult = ERROR;
	}

	return;
}
