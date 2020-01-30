/*27.1 问题概述
软件名称： YJGLQ
问题类型： 无符号整数下溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2015年
27.2 问题分析
变量g_nFinaleFrameID定义为unsigned int类型，如果接收到上行邮件首帧类型即为结束帧（0x55），由于未对帧序号nFrameID进行大于0的判断，因此第196行存在语句：g_nFinaleFrameID = nFrameID-1;，导致unsingned int类型变量可能溢出。
*/
unsigned int ADDR_IDS = 0x21001000;

#define READ_ADDR_UI32(addr) (*((volatile unsigned int*)(addr)))

unsigned int g_nFinaleFrameID,nFrameID;

void main(){
    nFrameID = READ_ADDR_UI32(ADDR_IDS);
    if(nFrameID<4){
        g_nFinaleFrameID = nFrameID - 1;
    }   
}
