#include "basal.h"
/*
75.1 问题概述
软件名称：JHJZJ
问题类型： 无符号整数上溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2018年
75.2 问题分析
"L762~L765行
VDD = 12276/VBG;
VTEM25 = 6900/VDD; 
VHOT =  1809/VDD; 
VCOLD =  1900/VDD;除数VBG、VDD为0的情况未考虑"
*/

unsigned int ADDR_VBG = 0x21001000;
unsigned int ADDR_VDD = 0x21001004;

unsigned int VBG;
unsigned int VDD;

unsigned int VHOT;
unsigned int VCOLD;

void case075(void)
{
	unsigned int VTEM25;

	VBG = READ_ADDR_UI32(ADDR_VBG);
	VDD = READ_ADDR_UI32(ADDR_VDD);

	VDD = 12276/VBG;
	VTEM25 = 6900/VDD; 
	VHOT =  1809/VDD; 
	VCOLD =  1900/VDD;

	return;
}
