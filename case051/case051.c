#include "basal.h"

/*
51 问题编号：VBUG00028877
51.1 问题概述
软件名称： TXCL
问题类型： 有符号整数上溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2018年
51.2 问题分析
帧计数all_data.N_frameNum为Int型数据（即有符号整型数据），在接收到一包点目标数据后，该变量进行++操作。
软件将其赋值给无符号整型变量cur_frame_number，若++溢出后（即符号位变最1），则会造成cur_frame_number变成一个超大数。
*/

#define ADDR_TC 0x40101000

int N_frameNum;
unsigned int cur_frame_number;

void case051(void)
{
	unsigned int flag;

	flag = READ_ADDR_UI32(ADDR_TC);
	if (0x1 == (flag & 0x1))
	{
		/* to do something */
		N_frameNum++;
	}

	cur_frame_number = N_frameNum;
}