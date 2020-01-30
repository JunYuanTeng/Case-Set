/*2.1 问题概述
软件名称：DHXX-A
问题类型：无符号整数下溢
引入阶段：实现阶段
编程语言：C语言
提交日期：2013年
2.2 问题分析
sig_proc1.c文件中存在语句操作tong_kp--，其中tong_kp 为32位无符号整型，在tong_kp为0的情况下执行上述语句，则导致tong_kp数据溢出为0xFFFFFFFF，影响码捕获的搜索。
*/
unsigned int tong_kp;

void isr(){
    tong_kp = 0;
}
void init(){
    tong_kp = 10;
}
int main(){
    init();
    tong_kp--;
    return 0;
}

