/*
31.1 问题概述
软件名称： WZCL
问题类型： 无符号整数下溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2016年
31.2 问题分析
CMU指令解包过程中，针对指令中的字节长度（cmu_tc[0]&0xFF）未判合法性。如果（cmu_tc[0]&0xFF）为0，将导致计算溢出（见206行的length = (cmu_tc[0]&0xFF)/2 - 1;），且后续的cmu_tc[32]数组读访问越界；如果（cmu_tc[0]&0xFF）大于65，将导致cmu_tc[32]数组读访问越界。
*/
unsigned int ADDR_CMD = 0x21001100;
#define READ_ADDR_UI16(addr) (*((volatile unsigned int*)(addr)))

unsigned char cmu_tc[32];

void main(){
    unsigned length;
    for (int i = 0; i < 32;i++){
        cmu_tc[i] = (unsigned char)READ_ADDR_UI16(ADDR_CMD);
    }
    length = (cmu_tc[0] & 0xFF) / 2 - 1;
}
