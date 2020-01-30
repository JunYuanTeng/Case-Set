#include "basal.h"

/*
44 问题编号：VBUG00021908
44.1 问题概述
软件名称： YXFP
问题类型： 无符号整数上溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2017年
44.2 问题分析
按照软件设计要求，第一次采集两路模拟量时，需要记录其第一次采集的值做为后续进行超限判断的初值，
此操作应只进行一次，当计数变量flag累加为1时进行上述操作。
但软件具体实现时，计数变量flag加为1后，每个循环周期仍然在继续累加，
在软件运行期间，此unsigned char型计数变量有可能出现溢出情况，
则导致计数变量flag重新回0再进行累加，由此导致再一次满足了flag等于1的条件，程序又对模拟量初值进行了更改，使得进行超限判断的初值不一致。
*/

#define ADDR_ANG1 0x22001000
#define ADDR_ANG2 0x20001004

unsigned char flag;
unsigned int ang1;
unsigned int ang2;
unsigned int thr1;
unsigned int thr2;

void case044(void)
{
	flag = 1;

	while(1)
	{
		ang1 = READ_ADDR_UI32(ADDR_ANG1);
		ang2 = READ_ADDR_UI32(ADDR_ANG2);

		if (flag == 1)
		{
			thr1 = ang1;
			thr2 = ang2;
		}

		flag++;
	}
}
