#include "basal.h"

/*
67 问题编号：VBUG00013467
67.1 问题概述
软件名称：OBC
问题类型： 无符号整数上溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2015年
67.2 问题分析
软件在计算阳光规避时间预报值时，未对中间变量tmpff进行除零判断，可能导致除零。
*/
int rWGS[3];

void Sel_TranMatr_JtoO(double r[])

{
	int norm;
	tmpff = r[0] + r[1] + r[2];
	r[0] = r[0] / tmpff;
	r[1] = r[1] / tmpff;
	r[2] = r[2] / tmpff;
	return;
}
void case067(void)
{
	Sel_TranMatr_JtoO(rWGS);
	return;
}
