/*28.1 问题概述
软件名称： CMU
问题类型： 无符号整数下溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2015年
28.2 问题分析
发送硬件指令时判断当前时刻（current_millisecond）距离上次发送指令到该RTU的时刻（last_cmd_sent_millisecond）大于448ms，则发送该硬件指令，否则不执行。由于变量current_millisecond、last_cmd_sent_millisecond均为无符号整数，如果current_millisecond小于last_cmd_sent_millisecond，进行减操作会导致溢出。
*/
unsigned int ADDR_TIME = 0x21001000;
unsigned int ADDR_SEND = 0x21001100;
#define READ_ADDR_UI32(addr) (*((volatile unsigned int*)(addr)))
#define SEND_TIME(time) (*((volatile unsigned int*)(ADDR_SEND))=time)

unsigned int current_millisecond,last_cmd_sent_millisecond;
bool millisecond_flag = false;

void isr(){
    current_millisecond = READ_ADDR_UI32(ADDR_TIME);
    millisecond_flag = true;
}
void main(){
    while(1){
        if(millisecond_flag==true){
            millisecond_flag = false;
            if(current_millisecond-last_cmd_sent_millisecond>448){
                SEND_TIME(0x55);
                last_cmd_sent_millisecond = current_millisecond;
            }            
        }        
    }
}
