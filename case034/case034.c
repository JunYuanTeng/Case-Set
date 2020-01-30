/*34.1 问题概述
软件名称： SXCLB
问题类型： 无符号整数上溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2016年
34.2 问题分析
TimeSyncOperate.c中27行CalcFreqNCO函数，软件未对Exponent变量[-1075，972]进行有效范围判读，但使用该变量对其他无符号整型变量（32bit）进行移位，可能导致无符号整型变量移位溢出。
*/
#include"stdlib.h"
void main(){
    unsigned int para=100;
    int exponent;
    exponent = rand();
    if(exponent>-1075 && exponent<=972){
        para = para << exponent;
    } 
}

