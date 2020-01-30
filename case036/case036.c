/*36.1 问题概述
软件名称： XJZK
问题类型： 无符号整数下溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2017年
36.2 问题分析
代码使用B_485send_No1表示软件向CCD1 FPGA成像单元发送的帧数，使用UartA_RvData[10]表示CCD1 FPGA成像单元从软件接收的帧数，两者之差即为CCD1应答错误计数。
在9249行，代码判断若B_485send_No1>=UartA_RvData[10]，则CCD1应答错误计数加B_485send_No1-UartA_RvData[10]；否则，CCD1应答错误计数加UartA_RvData[10]-B_485send_No1。
该计算未考虑数据溢出的问题，导致B_485send_No1溢出后计算CCD1 应答错误计数结果错误。
*/
unsigned int ADDR_RV = 0x21001000;

#define READ_ADDR_UI32(addr) (*((volatile unsigned int*)(addr)))

unsigned int B_485send_No1, UartA_RvData[11];
void isr(){
    B_485send_No1++;
}

void main(){
    unsigned int cmdcnt=0;
    UartA_RvData[10] = READ_ADDR_UI32(ADDR_RV);
    if(B_485send_No1>=UartA_RvData[10]){
        cmdcnt += B_485send_No1 - UartA_RvData[10];
    }else{
        cmdcnt += UartA_RvData[10] - B_485send_No1;
    }
}