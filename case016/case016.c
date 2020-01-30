/*16.1 问题概述
软件名称： XMGQ
问题类型： 无符号整数下溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2015年
16.2 问题分析
变量BadPixellength定义为unsigned int类型，第3434行存在对其减1操作，未对其进行可能为0的判断，可能导致无符号变量溢出。
*/
unsigned int ADDR_CH = 0x21001000;
#define READ_ADDR_UI32(addr) (*((volatile unsigned int*)(addr)))

void main(){
    unsigned int BadPixellength;
    BadPixellength = READ_ADDR_UI32(ADDR_CH);
    BadPixellength = BadPixellength - 1;
}