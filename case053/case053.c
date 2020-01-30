#include "basal.h"

/*
53 问题编号：VBUG00029199
53.1 问题概述
软件名称：GNC 
问题类型： 无符号整数上溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2018年
53.2 问题分析
任务书6.1要求软件在轨运行一年以上，不允许失效；
软件在星时采集时（1031、1032行），使用PeriodCount * 128，
而控制周期计数为unsigned int类型，乘以128可能会溢出的情况。（50天溢出）
*/

unsigned int StarTimeMs;
unsigned int PeriodCount;

void case053(void)
{
	StarTimeMs = PeriodCount * 128;

	return;
}
