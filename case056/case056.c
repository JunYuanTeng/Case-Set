#include "basal.h"

/*
56 �����ţ�VBUG00033459
56.1 �������
������ƣ� GTCCQ
�������ͣ� �޷�����������
����׶Σ�ʵ�ֽ׶�
������ԣ�C����
�ύ���ڣ� 2019��
56.2 �������
����CloseTimer�У�δ�ж�GTI.ValuableTimerNum����0�ͽ���--���������������������
*/

typedef struct  
{
	unsigned int ValuableTimerNum;
} SGTI;

SGTI GTI;

void CloseTimer(void)
{
	GTI.ValuableTimerNum--;
}

void case056(void)
{
	CloseTimer();

	return;
}
