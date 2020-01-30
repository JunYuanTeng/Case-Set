/*6 问题编号：VBUG00003978
6.1 问题概述
软件名称：ALTU
问题类型：无符号整数下溢
引入阶段：实现阶段
编程语言：C语言
提交日期：2011年
6.2 问题分析
当25路电磁阀脉宽某一路超过120ms会进行以下处理：
if( uartRcv[i+16]>120 ){
   uartRcv[i+16]--;
}
当要对某一路脉冲脉宽减1时，突然安全指令4到来，在安全指令4中会对所有电磁阀脉宽清0，当中断返回时，主程序会对脉宽减1，这就会造成数据溢出，脉宽会变为0xFF。
*/
#define CMDPKG_NO 46
#define XBYTE ((unsigned char *)0)
#define SBUF XBYTE[0x92]
#define IntStateReg XBYTE[0x006E]

unsigned int uartRcv[CMDPKG_NO];

void func_initCPU(){
    for (int i = 0; i < 8;i++){
        uartRcv[2 * i] = 0x08;
        uartRcv[2 * i+1] = 0x00;
    }
    for (int i = 0; i < CMDPKG_NO;i++){
        uartRcv[i + 16] = 0x00;
    }
}

void uartRcv_ISR(){
    unsigned char rcvCouter=0,accSum = 0xf4;
    uartRcv[rcvCouter] = SBUF;
    if(rcvCouter<CMDPKG_NO-1)
        {
                accSum += uartRcv[rcvCouter];
        }
    rcvCouter++;

}

void ex1_ISR(){
    if((IntStateReg | 0xfd)==0xfd){
        func_initCPU();
    }
}
int main(){
    func_initCPU();
    for (int i = 0; i < 25;i++){
        if(uartRcv[i+16]>120){
            uartRcv[i + 16]--;
        }
    }
    return 0;
}