#include "basal.h"

/*
45 问题编号：VBUG00022605
45.1 问题概述
软件名称： SIFU
问题类型： 无符号整数下溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2017年
45.2 问题分析
软件在函数LED_Control中判断条件else if(k_led<(LED_count*10*20-300))前未判断LED_count的大小，可能会导致减溢出。
*/

unsigned char LED_count;

void case045(unsigned char k_led)
{
	if (k_led < (LED_count * 10 * 20))
	{
		/* to do something... */
	}
	else if (k_led < (LED_count * 10 * 20 - 300))
	{
		/* to do something... */
	}
	else
	{
		/* to do something... */
	}

	return;
}
