#include "basal.h"

/*
58 问题编号：VBUG00007632
58.1 问题概述
软件名称： SZJD
问题类型： 无符号整数上溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2013年
58.2 问题分析
软件中itmp4 = pChannel->P_Buf>>8;判断pChannel->P_Buf非0后stmp1=(pChannel->E_Buf+pChannel->L_Buf-pChannel->P_Buf)/itmp4;
由于pChannel->P_Buf非0，itmp4仍有可能为0，软件除零保护判断错误。
*/

typedef struct  
{
	int P_Buf;
	int E_Buf;
	int L_Buf;

} SChannel;

void case058(SChannel *pChannel)
{
	int stmp1;
	int itmp4;

	itmp4 = pChannel->P_Buf>>8;

	if (0 != pChannel->P_Buf)
	{
		stmp1 = (pChannel->E_Buf+pChannel->L_Buf-pChannel->P_Buf)/itmp4;
	}

	return;
}
