/*9.1 问题概述
软件名称： SJCL
问题类型：无符号整数下溢
引入阶段：实现阶段
编程语言：C语言
提交日期：2011年
9.2 问题分析
monitor.c的第295行存在语句：nLength -= (nBlock_Len + 2)，由于nLength定义为unsigned int类型，并且此处计算结果可能小于0，因此可能会导致变量nLength溢出。
*/
unsigned int nLength, nBlock_Len;
unsigned int block_len;
void input(){
    nLength = 100;
    nBlock_Len = block_len;
}
void main(){
    input();
    nLength -= (nBlock_Len + 2);
}
