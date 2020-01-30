/*
35.1 问题概述
软件名称： MBJC
问题类型： 无符号整数上溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2016年
35.2 问题分析
软件在中断中将g_frameNum加加操作，在主函数中进行比较，若g_frameNum_r小于g_frameNum，则进行读取、处理图像的操作，然后设置g_frameNum_r等于g_frameNum。但是由于软件没有对g_frameNum溢出的情况进行处理，导致g_frameNum溢出后，g_frameNum_r小于g_frameNum的情况不再发生，于是软件无法继续读取、处理图像的操作，软件失效。
*/
unsigned char g_frameNum, g_frameNum_r;

void isr(){
    g_frameNum++;
}

void main(){
    while(1){
        if(g_frameNum_r<g_frameNum){
           g_frameNum_r = g_frameNum;
        }
    }
}