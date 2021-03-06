/*22.1 问题概述
软件名称： GDB
问题类型： 无符号整数下溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2011年
22.2 问题分析
Check.c的第353行存在语句：GL_Length=GL_Length-GL_block_len-2，由于GL_Length定义为unsigned int类型，并且此处计算结果可能小于0，因此可能会导致变量GL_Length溢出。
*/
unsigned int GL_Length, GL_block_len;
unsigned int block_len;
void input(){
    GL_Length = 100;
    GL_block_len = block_len;
}
void main(){
    input();
    GL_Length = GL_Length - GL_block_len - 2;
}
