/*37.1 问题概述
软件名称： AOCC
问题类型： 无符号整数下溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2017年
37.2 问题分析
软件收到上升器推进控制包后进行连续排气处理时，如果上注的排气时间Jet.TPQ为0，则4680行的Jet.TPQ = Jet.TPQ - 1;操作结果将由于计算溢出而出现大数，从而导致软件连续0xFFFFFFFF个控制周期进行连续排气。
*/
unsigned int ADDR_JET = 0x21001000;
#define READ_ADDR_UI32(addr) (*((volatile unsigned int*)(addr)))
unsigned int tpq;

void main(){
    tpq = READ_ADDR_UI32(ADDR_JET);
    tpq = tpq - 1;
}