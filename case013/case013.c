/*13.1 问题概述
软件名称： GXTLCL
问题类型： 无符号整数下溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2011年
13.2 问题分析
当前时刻的电路板温度平均值小于上一时刻电路板温度平均值时，在执行公式fTemp_cha=(fTemp_fogDianLu-fTemp_DianLu_Last)*TEMP_SCALE*C025时，(fTemp_fogDianLu-fTemp_DianLu_Last)为负值，导致累加器A溢出。
*/
#define TEMP_SCALE 0x64
#define C025 25
unsigned int ADDR_CH1 = 0x21001000;
unsigned int ADDR_CH2 = 0x21001100;
#define READ_ADDR_UI32(addr) (*((volatile unsigned int*)(addr)))
void main(){
    unsigned int fTemp_cha, fTemp_fogDianLu, fTemp_DianLu_Last;
    fTemp_fogDianLu = READ_ADDR_UI32(ADDR_CH1);
    fTemp_DianLu_Last = READ_ADDR_UI32(ADDR_CH2);
    fTemp_cha = (fTemp_fogDianLu - fTemp_DianLu_Last) * TEMP_SCALE * C025;
}