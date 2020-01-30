/*3.1 问题概述
软件名称：DHXX-B
问题类型：无符号整数下溢
引入阶段：实现阶段
编程语言：C语言
提交日期：2013年
3.2 问题分析
sig_proc2.c文件中存在语句操作accum--，其中accum为16位无符号short型变量，若在accum为0的情况下执行上述语句，则导致accum数据溢出为0xFFFF，发生无符号整数下溢出。
*/
unsigned short accum;

void isr(){
    accum = 0;
}
void init(){
    accum = 10;
}
int main(){
    init();
    accum--;
    return 0;
}
