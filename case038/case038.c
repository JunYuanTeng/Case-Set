#include "basal.h"

/*
38 问题编号：VBUG00020477
38.1 问题概述
软件名称： CMU
问题类型： 有符号整数上溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2017年
38.2 问题分析
tsk_create函数任务创建传入的3个参数arg1、arg2、arg3的数据类型为UINT无符号，
调用函数szos_tsk_init函数传入参数arg1、arg2、arg3的数据类型为INT有符号，
可能导致数据溢出。
*/

extern void *tsk_create(int, int, int);

void *szos_tsk_init(unsigned int arg1, unsigned int arg2, unsigned int arg3)
{
	void *tPtr;
	tPtr = tsk_create(arg1, arg2, arg3);

	return tPtr;
}

void *task1Handle;

void case038(void)
{
	task1Handle = szos_tsk_init(0xFFFF0001, 0xFFFF0002, 0xFFFF0003);

	return;
}
