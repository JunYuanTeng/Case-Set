/*17.1 问题概述
软件名称： SZJSJ
问题类型： 无符号整数上溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2014年
17.2 问题分析
软件在Cal_Para()函数中针对unsigned int型变量para存在如下设计：para = para+(1<<(32-i))。上述设计中，当i等于0时，将导致移位结果溢出。
*/
#include "stdlib.h"
void main() {
	unsigned int para = 0;
	int i;
	i = rand();
	if (i >= 0 && i < 31) {
		para = para + (1 << (32 - i));
	}
}