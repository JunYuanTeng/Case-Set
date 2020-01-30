#include "basal.h"

/*
59 问题编号：VBUG00000199
59.1 问题概述
软件名称： DHXX
问题类型： 有符号整数上溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2010年
59.2 问题分析
在Nav_predict.c中第1103、1104行没进行对变量rsat 、变量rusr和变量r的除零保护：
Oc =  ( rsat2+r2-rusr2 ) / ( 2*rsat*r );
Ic = -( rusr2+r2-rsat2 ) / ( 2*rusr*r );
*/

extern float sqrtX(float);

void case057(float x, float y, float z, float rsat, float rusr)
{
	float r2;
	float Oc;
	float Ic;
	float r;
	float rsat2;
	float rusr2;

	r2 = x * x + y * y + z * z;
	r = sqrtX(r2);
	rsat2 = rsat * rsat;
	rusr2 = rusr * rusr;
	Oc =  ( rsat2+r2-rusr2 ) / ( 2*rsat*r );
	Ic = -( rusr2+r2-rsat2 ) / ( 2*rusr*r );

	return;
}
