#include "basal.h"

/*
69 问题编号：VBUG00021947
69.1 问题概述
软件名称：SJCL
问题类型： 无符号整数下溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2017年
69.2 问题分析
XWRep.c的L1105，存在语句“guiPUnReadPac = guiPUnReadPac - 478 + guiRepTemp2WCnt;”等式右边有可能为负值，
而变量guiPUnReadPac为无符号整型，即存在将负数赋值给无符号整型变量的情况。
*/

unsigned int guiPUnReadPac;

void case069(unsigned int guiRepTemp2WCnt)
{
	guiPUnReadPac = guiPUnReadPac - 478 + guiRepTemp2WCnt;

	return;
}
