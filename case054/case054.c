#include "basal.h"

/*
54 问题编号：VBUG00030586
54.1 问题概述
软件名称： SIFU1
问题类型： 有符号整数下溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2018年
54.2 问题分析
close_control函数中若X/Y轴预置角度与X/Y轴实际角度的差值(abs((x_set_word+0x8000)-(int)A_angle))为0x8000时，也即X/Y轴未限位，
应继续输出相应电机相序，但由于绝对值函数abs参数类型为int型，返回值也为int型，
而0x8000为-32768，取绝对值后为32768却大于32767，此时溢出，为-32768，
导致无法满足abs((x_set_word+0x8000)-(int)A_angle)大于5的条件，
使X/Y轴未转动到位即停止转动。（Xx20.c的L530、555）
*/

extern int abs(int);

short x_set_word;
short A_angle;

void case054(void)
{
	unsigned short delta;

	delta = abs((x_set_word+0x8000)-(int)A_angle);
	if (delta > 5)
	{
		/* stop the axis motor ... */
	}

	return;
}
