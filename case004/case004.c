/*4.1 问题概述
软件名称：KZCL
问题类型：无符号整数下溢
引入阶段：实现阶段
编程语言：C语言
提交日期：2013年
4.2 问题分析
针对置接收机频率（0x32）指令中的频率值，软件未做合法性判断就直接用于LookTableGain()函数调用，可能导致函数中的计算结果（list = (frequence - 2500 ) / 10）溢出，并进而导致衰减表读访问越界。
*/
unsigned int ADDR_CMD = 0x21001000;
unsigned int ADDR_FRE = 0x21001100;
#define READ_ADDR_UI32(addr) (*((volatile unsigned int*)(addr)))

unsigned int list, frequence;
void LookTableGain(){
    list = (frequence - 2500) / 10;
    return;
}
int main(){
    unsigned int fre_cmd,fre_val;
    fre_cmd = READ_ADDR_UI32(ADDR_CMD);
    fre_val = READ_ADDR_UI32(ADDR_FRE);
    if(fre_cmd==0x32){
        frequence = fre_val;
    }
    LookTableGain();
    return 0;
}