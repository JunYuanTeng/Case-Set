/*1.1 问题概述
软件名称：CTU
问题类型：无符号整数上溢
引入阶段：实现阶段
编程语言：C语言
提交日期：2010年
1.2 问题分析
软件在调用Get_Time()函数进行星上时间校时处理时，会进行如下操作：on_board_millisecond = (1000 * on_board_time.second + on_board_time.millisecond);
其中，on_board_millisecond为64位无符号变量，on_board_time.second为32位无符号变量，on_board_time.millisecond为16位无符号变量。
由于1000 * on_board_time.second的计算结果为32位，导致on_board_time.second大于4294967时，1000 * 4294968=0x1000002C0，即，此时会出现32位溢出。
根据上述分析，软件以上设计会导致如下问题：
1.on_board_millisecond虽然为64位变量，但其可能的取值范围仅限于32位。
2.on_board_time.second（星上自主计时的秒值）达到4294968时，1000 * on_board_time.second的计算结果32位溢出，这意味着，软件只能实现连续计时4294968/（24*3600）=50（天）。
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

