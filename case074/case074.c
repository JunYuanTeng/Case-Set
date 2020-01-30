#include "basal.h"

/*
74 问题编号：VBUG00027982
74.1 问题概述
软件名称：BWTXCL
问题类型： 无符号整数上溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2018年
74.2 问题分析
1、软件在Pullen_track.c中223行计算epk_temp时，除数为变量从FPAG获得，存在除数为0的可能。
2、CN0_estimate.c中78行M-CN0_Estimate_TF.NP[ii]作为除数存在等于零的可能。
*/

#define ADDR_EPK 0x20010010

void case074(void)
{
	unsigned int EPK;
	double dEPK;
	double epk_temp;

	EPK = READ_ADDR_UI32(ADDR_EPK);
	dEPK = ((double)((int)EPK)) * 0.125;
	epk_temp = 1.0 / dEPK;

	return;
}
