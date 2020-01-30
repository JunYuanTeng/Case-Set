/*
32.1 问题概述
软件名称： XKZB
问题类型： 无符号整数下溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2016年
32.2 问题分析
变量CmdNavRate为unsigned int类型，且为注入数据，软件中未判断其是否为0，而第140行存在CmdNavRate-1操作，如果该变量为0，则导致变量溢出。
*/

unsigned int ADDR_CMD = 0x21001100;
#define READ_ADDR_UI32(addr) (*((volatile unsigned int*)(addr)))
unsigned int CmdNavRate;
void main(){
    unsigned int rate;
    CmdNavRate = READ_ADDR_UI32(ADDR_CMD);
    rate = CmdNavRate - 1;
}