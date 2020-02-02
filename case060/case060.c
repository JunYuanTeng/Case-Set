#include "basal.h"

/*
60 问题编号：VBUG00000221
60.1 问题概述
软件名称： DHXX
问题类型： 有符号整数上溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2010年
60.2 问题分析
在Nav_predict.c中第1103、1104行没进行对变量rsat 、变量rusr和变量r的除零保护：
Oc =  ( rsat2+r2-rusr2 ) / ( 2*rsat*r );
Ic = -( rusr2+r2-rsat2 ) / ( 2*rusr*r );
*/

extern int sqrtX(float);

void case060(int x, int y, int z, int rsat, int rusr)
{
	int r2;
	int Oc;
	int Ic;
	int r;
	int rsat2;
	int rusr2;

	r2 = x * x + y * y + z * z;
	r = sqrtX(r2);
	rsat2 = rsat * rsat;
	rusr2 = rusr * rusr;
	Oc =  ( rsat2+r2-rusr2 ) / ( 2*rsat*r );
	Ic = -( rusr2+r2-rsat2 ) / ( 2*rusr*r );

	return;
}
