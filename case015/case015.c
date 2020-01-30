/*15.1 问题概述
软件名称： GXTLZJ
问题类型： 有符号整数上溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2014年
15.2 问题分析
软件累加20次的陀螺角度脉冲数，然后再*171作为陀螺角度增量，程序中均定义为short型变量来表示20次的累加值与最终的角度增量，若累加值溢出或*171后溢出，则会造成最终结果值的正负符号发生变化，进而造成星务应答输出数值错误以及对角度增量的限幅错误。
*/
unsigned int ADDR_PULSE = 0x21001000;
#define READ_ADDR_SI16(addr) (*((volatile signed int*)(addr)))

void main(){
    short rad;
    short angledelta=0;
    for (int i = 0; i < 20;i++){
        rad = READ_ADDR_SI16(ADDR_PULSE);
        angledelta += rad;
    }
    angledelta = angledelta * 171;
}