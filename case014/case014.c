/*14.1 问题概述
软件名称： ZHGL
问题类型： 无符号整数下溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2012年
14.2 问题分析
软件对主循环计时变量t1sCount有如下处理：当t1sCount大于等于80时，将其进行减100操作，该操作导致变量t1sCount溢出。
*/
unsigned int ADDR_CH = 0x21001000;
#define READ_ADDR_UI32(addr) (*((volatile unsigned int*)(addr)))
void main(){
    unsigned int t1sCount;
    t1sCount = READ_ADDR_UI32(ADDR_CH);
    if (t1sCount >= 80){
        t1sCount -= 100;
    }
}