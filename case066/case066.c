#include "basal.h"

/*
66 问题编号：VBUG00011982
66.1 问题概述
软件名称：DGJK
问题类型： 无符号整数上溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2015年
66.2 问题分析
函数Sel_TranMatr_JtoO对除数norm未做除零保护。
*/

double rWGS[3];

void Sel_TranMatr_JtoO(double r[])
{
	double norm;

	norm = r[0] * r[0] + r[1] * r[1] + r[2] * r[2];

	r[0] = r[0] / norm;
	r[1] = r[1] / norm;
	r[2] = r[2] / norm;

	return;
}

void case066(void)
{
	Sel_TranMatr_JtoO(rWGS);

	return;
}
