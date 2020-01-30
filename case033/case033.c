/*33.1 问题概述
软件名称： KZTX
问题类型： 无符号整数下溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2016年
33.2 问题分析
在Orbit_T_Set函数中程序对轨道周期做差，轨道周期等于（XT-轨道块的T0），轨道周期、XT、轨道块的T0为无符号的数，程序未考虑XT小于轨道块的T0的情况，导致当XT小于轨道块的T0的时候，计算得出的轨道周期将为很大的数，数据出现溢*/

unsigned int ADDR_XT = 0x21001000;
unsigned int ADDR_T0 = 0x21001100;
#define READ_ADDR_UI32(addr) (*((volatile unsigned int*)(addr)))

unsigned int orbitt, xt, orbitt0;
void Orbit_T_Set(){
     xt = READ_ADDR_UI32(ADDR_XT);
     orbitt0 = READ_ADDR_UI32(ADDR_T0);
     orbitt = xt - orbitt0;
 }

 void main(){
     Orbit_T_Set();
 }
