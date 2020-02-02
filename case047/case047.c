#include "basal.h"

/*
47 问题编号：VBUG00025675
47.1 问题概述
软件名称： PDXWJ
问题类型： 无符号整数上溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2017年
47.2 问题分析
软件对120路模拟量遥测数据进行采集，模拟量每一路遥测采集值N均使用下位机+5V基准遥测的采集值N5进行同源校准，
校准公式：校准值=（N/N5）×1000.0，
下位机+5V基准遥测的采集值是AD采集的某一路值，是随机值，
软件在进行校准前没有对下位机+5V基准遥测的采集值范围进行限定，导致如果采集的下位机+5V基准遥测值是一个很小的值，作为除数后计算结果会溢出。
*/

#define NUM_ANG 120

#define EQU 0.125
#define ADDR_BASE 0x20101000
#define ADDR_ANG  0x20102000

int ANGM[NUM_ANG];
int ANGBase;

void case047(void)
{
	int i;
	int i32Base;
	int i32Ang;

	i32Base = READ_ADDR_SI32(ADDR_BASE);
	ANGBase = i32Base * EQU;

	for (i = 0; i < NUM_ANG; i++)
	{
		i32Ang = READ_ADDR_SI32(ADDR_ANG + i * 4);
		ANGM[i] = i32Ang * EQU;
		ANGM[i] = (ANGM[i] / ANGBase) * 1000.0;
	}

	return;
}
