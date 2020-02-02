#include "basal.h"

/*
72 问题编号：VBUG00023663
72.1 问题概述
软件名称：TXZC
问题类型： 无符号整数上溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2017年
72.2 问题分析
SetFpgaParaSampling.c文件第47行，软件初始化变量g_wdnc_fs为0，而软件进行除操作g_fs_fst/g_wdnc_fs时，未对变量g_wdnc_fs为0情况进行保护。
*/

int g_fs_fst = 0;
int g_wdnc_fs = 0;
int g_fs_div = 0;

void case072(void)
{
	g_fs_div = g_fs_fst / g_wdnc_fs;

	return;
}
