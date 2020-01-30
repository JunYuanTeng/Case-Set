#include "basal.h"

/*
39 问题编号：VBUG00020482
39.1 问题概述
软件名称： CMU
问题类型： 无符号整数下溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2017年
39.2 问题分析
Szos_clk_gettime.c文件Time_Normalize函数第65行“tp->tv_sec--”，没有考虑边界处理情况，
若对于unsigned long类型的tv_sec为0时，进行减1操作后数据溢出。
*/

typedef struct 
{
	unsigned long tv_sec;
} STv;

STv gTv;

void Time_Normalize(STv *tp)
{
	tp->tv_sec--;

	return;
}

void case039(void)
{
	Time_Normalize(&gTv);

	return;
}
