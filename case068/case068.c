#include "basal.h"

/*
68 问题编号：VBUG00017339
68.1 问题概述
软件名称：ZDKZ
问题类型： 无符号整数上溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2016年
68.2 问题分析
WK_Comm.c的L182、L246的ber_rate = ber/ber_all;没有进行除零保护。
*/

int ber_all;
int ber_rate;

void case068(int ber)
{
	ber_rate = ber/ber_all;
	ber_all = ber_all + ber;
	return;
}
