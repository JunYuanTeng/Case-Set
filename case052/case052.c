#include "basal.h"

/*
52 问题编号：VBUG00028878
52.1 问题概述
软件名称： TXCL
问题类型： 无符号整数下溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2018年
52.2 问题分析
frame_diff、cur_frame_number、pre_frame_number均为无符号整型变量，
frame_diff=cur_frame_number-pre_frame_number；
若减溢出时，则会造成frame_diff为一大数，进而造成图像处理算法计算错误。
*/

unsigned int frame_diff;
unsigned int cur_frame_number;
unsigned int pre_frame_number;

void case052(void)
{
	frame_diff = cur_frame_number - pre_frame_number;

	return;
}
