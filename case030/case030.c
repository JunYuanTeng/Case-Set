/*
30.1 问题概述
软件名称： DQMGQ
问题类型： 有符号整数上溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2017年
30.2 问题分析
变量Gx，Gy类型为signed int型范围是-32768~32767用于累计梯度计算的结果，Gx累计3对像素点图像数据差值，Gy累计6对像素点图像数据差值，像素点图像数据差值均为16位表示，计算结果会产生溢出。（计算使用的6对像素点图像数据差值平均大于5461时，Gy会溢出上限）
*/
unsigned int ADDR_GX = 0x21001000;
unsigned int ADDR_GY = 0x21001100;
#define READ_ADDR_UI16(addr) (*((volatile unsigned int*)(addr)))

unsigned int Gx, Gy;

void main(){
    for (int i = 0; i < 3;i++){
        Gx += READ_ADDR_UI16(ADDR_GX);
    }
    for (int i = 0; i < 6;i++){
        Gy += READ_ADDR_UI16(ADDR_GY);
    }
}
