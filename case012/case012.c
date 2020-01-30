/*12.1 问题概述
软件名称： GXTLCL
问题类型： 有符号整数上溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2011年
12.2 问题分析
Calc_ZUHE_Pulse函数中，giT_period为unsigned short型，执行giT_period = 399 + iTemp时，负脉冲时，iTemp范围为[-400,0）时，git_period溢出。
*/
unsigned int ADDR_GIT = 0x21001100;
#define READ_ADDR_SI16(addr) (*((volatile signed int*)(addr)))
void main(){
    unsigned int giT_period;
    int iTemp;
    iTemp = READ_ADDR_SI16(ADDR_GIT);
    if(iTemp<0 && iTemp>=-400){
        giT_period = 399 + iTemp;
    }    
}
