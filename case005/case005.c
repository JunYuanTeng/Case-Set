/*5.1 问题概述
软件名称：ZGWH
问题类型：无符号整数上溢
引入阶段：实现阶段
编程语言：C语言
提交日期：2010年
5.2 问题分析
星时的秒数据存放在32位无符号整型中，程序将秒数据乘以1000后再加上保存在16位无符号整型中的毫秒得到总毫秒数，最后赋值给64位无符号整型。程序在计算过程中未进行强制转换，所以计算后的数据还是32位整型数据，如果数据超出32位则会丢掉超出32位的高位部分，即当秒数据大于等于4294968（对应50天，1000*4294968=0x1,0000,02C0）时则会发生溢出。
*/
unsigned int ADDR_SEC = 0x21001000;
unsigned int ADDR_MILLI = 0x21001100;
#define READ_ADDR_UI32(addr) (*((volatile unsigned int*)(addr)))

struct On_Board_Time_Struct
{
    unsigned int second;
    unsigned short millisecond;
}on_board_time;

struct Central_Adjtm_Struct
{
    bool adjtm_flga;
    unsigned int adjust_second;
    unsigned short adjust_millisecond;    
}central_adjtm;

void clock_isr(){
    on_board_time.second += 1;
    on_board_time.millisecond = 0;
    if(central_adjtm.adjtm_flga==true){
        on_board_time.second=central_adjtm.adjust_second;
        on_board_time.millisecond=central_adjtm.adjust_millisecond;
    }
}

void timeadjust(unsigned int second,unsigned short microcnt){
    central_adjtm.adjust_second+=second;
    central_adjtm.adjust_millisecond += microcnt;
    central_adjtm.adjtm_flga = true;
}
int main(){
    unsigned long on_board_millisecond;
    unsigned int second;
    unsigned short microcnt;
    second=READ_ADDR_UI32(ADDR_SEC);
    microcnt=(unsigned short)READ_ADDR_UI32(ADDR_MILLI);
    timeadjust(second, microcnt);
    on_board_millisecond = (1000 * on_board_time.second + on_board_time.millisecond);
    return 0;
}

