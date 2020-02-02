#include "basal.h"

/*
46 问题编号：VBUG00023809
46.1 问题概述
软件名称： KDZC
问题类型： 无符号整数上溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2017年
46.2 问题分析
语句ampL_mean=ampL_mean/AmpL[IdxPDW][0]，不能排除AmpL[IdxPDW][0]为0的情况，此中情况AmpL[IdxPDW][0]用作除数出错。
*/

int AmpL[12][3];
int ampL_mean;

void case046(int IdxPDW)
{
	ampL_mean = ampL_mean/AmpL[IdxPDW][0];

	return;
}
