#include "basal.h"

/* 
49 问题编号：VBUG00028514
49.1 问题概述
软件名称：CDHU 
问题类型： 无符号整数下溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2018年
49.2 问题分析
软件组织设备管理指令遥控帧时，代码如下：
servicemangepk[20]=(char)ptr_Crc16(servicemangepk, 20)>>8;
调用ptr_Crc16计算校验值时，返回值类型为uint16，软件强制转换为char类型后进行右移8位操作，导致溢出。
*/

extern unsigned short ptr_Crc16(char*, int);

char servicemangepk[22];

void case049(void)
{
	unsigned short crc16;

	crc16 = ptr_Crc16(servicemangepk, 20);
	servicemangepk[20] = (char)crc16 >> 8;
	servicemangepk[21] = (char)crc16;

	return;
}
