#include "basal.h"

/*
48 问题编号：VBUG00029034
48.1 问题概述
软件名称： ZNXSQ
问题类型： 有符号整数下溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2018年
48.2 问题分析
变量buffer有符号字符型变量，范围为-128到127，而程序第159行对其进行了大于等于133且小于等于164的判断，数据使用溢出。
*/

void case048(char buffer)
{
	if ((buffer >= 133) && (buffer <= 164))
	{
		/* to do something */
	}
	else
	{
		/* to do something */
	}

	return;
}
