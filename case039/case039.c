#include "basal.h"

/*
39 �����ţ�VBUG00020482
39.1 �������
������ƣ� CMU
�������ͣ� �޷�����������
����׶Σ�ʵ�ֽ׶�
������ԣ�C����
�ύ���ڣ� 2017��
39.2 �������
Szos_clk_gettime.c�ļ�Time_Normalize������65�С�tp->tv_sec--����û�п��Ǳ߽紦�������
������unsigned long���͵�tv_secΪ0ʱ�����м�1���������������
*/

typedef struct 
{
	unsigned long tv_sec;
} STv;

STv gTv;

void Time_Normalize(STv *tp)
{
	tp->tv_sec--;

	return;
}

void case039(void)
{
	Time_Normalize(&gTv);

	return;
}
