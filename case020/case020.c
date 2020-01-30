/*20.1 问题概述
软件名称： ZHDKX
问题类型： 无符号整数上溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2012年
20.2 问题分析
软件在调用lotTimeMode函数进行时间计算时，会进行如下操作：task1startmsec=task1starttime.second*1000+task1starttime.millisecond；
其中，task1startmsec为double型，task1starttime.second为32位无符号整型，task1starttime.millisecond为16位无符号整型。
由于1000 * on_board_time.second的计算结果为32位无符号整型，task1starttime.second大于4294967时，1000 * 4294968=0x1000002C0，会出现32位溢出，导致任务时间计算错误，丢任务。
*/
unsigned int ADDR_SEC = 0x21001000;
unsigned int ADDR_MILLI = 0x21001100;
#define READ_ADDR_UI32(addr) (*((volatile unsigned int*)(addr)))
struct task1starttime_struct
{
    unsigned int second;
    unsigned short millisecond;
}task1starttime;

struct Central_Adjtm_Struct
{
    bool adjtm_flga;
    unsigned int adjust_second;
    unsigned short adjust_millisecond;    
}central_adjtm;

void clock_isr(){
    task1starttime.second += 1;
    task1starttime.millisecond = 0;
    if(central_adjtm.adjtm_flga==true){
        task1starttime.second=central_adjtm.adjust_second;
        task1starttime.millisecond=central_adjtm.adjust_millisecond;
    }
}

void timeadjust(unsigned int second,unsigned short microcnt){
    central_adjtm.adjust_second+=second;
    central_adjtm.adjust_millisecond += microcnt;
    central_adjtm.adjtm_flga = true;
}
int main(){
    double task1startmsec;
    unsigned int second;
    unsigned short microcnt;
    second=READ_ADDR_UI32(ADDR_SEC);
    microcnt=(unsigned short)READ_ADDR_UI32(ADDR_MILLI);
    timeadjust(second, microcnt);
    task1startmsec = task1starttime.second * 1000 + task1starttime.millisecond;
    return 0;
}

