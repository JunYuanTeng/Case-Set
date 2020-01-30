/*7.1 问题概述
软件名称： GXTLZJ
问题类型：有符号整数上溢
引入阶段：实现阶段
编程语言：C语言
提交日期：2011年
7.2 问题分析
程序实现读取温度数据和光功率后对读取的数据进行预处理时使用公式：iTempBL[0] = (100 * (TEMPPARA1 + TEMPPARA2 * tmp)) / (TEMPPARA3 + TEMPPARA4 * tmp);
公式中iTempBL[0]为有符号整型变量，公式的分子计算当tmp取值为8960时会造成分子计算数据溢出，导致程序计算错误。
*/
#define TEMPPARA1 0x7D4E5200
#define TEMPPARA2 0x09C4
#define TEMPPARA3 0x09C4
#define TEMPPARA4 0x01C2
unsigned int ADDR_TEMP = 0x21001100;
#define READ_ADDR_SI32(addr) (*((volatile signed int*)(addr)))
void main(){
    int iTempBL,tmp;
    tmp = READ_ADDR_SI32(ADDR_TEMP);
    iTempBL = (100 * (TEMPPARA1 + TEMPPARA2 * tmp)) / (TEMPPARA3 + TEMPPARA4 * tmp); 
}