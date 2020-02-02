#include "basal.h"

/*
62 问题编号：VBUG00010533
62.1 问题概述
软件名称：CTU
问题类型： 无符号整数上溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2014年
62.2 问题分析
软件进行如下操作时：XJ_gain = 429 * log10((( XJ_k1/acs_sinRTS ) + XJ_k2 )/( XJ_stage/16 ))，
软件未增加对变量acs_sinRTS为0情况的保护，如果变量acs_sinRTS为0，导致计算结果错误。
*/

extern int log10(int);

int case062(int XJ_k1, int XJ_k2, int acs_sinRTS, int XJ_stage)
{
	int XJ_gain;
	XJ_gain = 429 * log10((( XJ_k1 / acs_sinRTS ) + XJ_k2 )/( XJ_stage/16 ));

	return XJ_gain;
}
