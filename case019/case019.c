/*19.1 问题概述
软件名称： YDKZ
问题类型： 无符号整数上溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2013年
19.2 问题分析
软件在更新指令时设置溢出时间tYC = tcom +2000，其中停留时间tcom为unsigned long型、tYC为unsigned int型，CPU字长为16位，tcom数据范围为75~61775及0xFFFFD，当tcom为0xFFFFD，则tYC会溢出。
*/
unsigned int ADDR_COM = 0x21001100;
#define READ_ADDR_UI32(addr) (*((volatile unsigned int*)(addr)))
void main(){
    unsigned int tcom;
    unsigned short tYC;
    tcom = READ_ADDR_UI32(ADDR_COM);
    if((tcom>=75 && tcom<=61775) || tcom==0xFFFFD){
        tYC = tcom + 2000;
    }
}