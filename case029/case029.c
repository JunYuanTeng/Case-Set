/*29.1 问题概述
软件名称： DLL
问题类型： 无符号整数上溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2015年
29.2 问题分析
软件将FwCapT2Tmp[0].ul初始化为119304647，之后以119304647递增，因此，T2中断中的时间变量初始化设置导致FwCapT2Tmp[36].ul=37*119304647=0x1071C71C3，而FwCapT2Tmp[].ul为unsigned int型，从而导致FwCapT2Tmp[36].ul赋值结果溢出。
*/
struct FWCAPT2_STRUCT{
    unsigned int ul;
    bool timeflag;
};

void main(){
    struct FWCAPT2_STRUCT FwCapT2Tmp[37];
    FwCapT2Tmp[0].ul = 119304647;
    FwCapT2Tmp[0].timeflag = false;
    for (int i = 1; i < 37;i++){
        FwCapT2Tmp[i].ul = FwCapT2Tmp[i - 1].ul + 119304647;
        FwCapT2Tmp[i].timeflag = false;
    }
}