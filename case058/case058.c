#include "basal.h"

/*
58 �����ţ�VBUG00007632
58.1 �������
������ƣ� SZJD
�������ͣ� �޷�����������
����׶Σ�ʵ�ֽ׶�
������ԣ�C����
�ύ���ڣ� 2013��
58.2 �������
�����itmp4 = pChannel->P_Buf>>8;�ж�pChannel->P_Buf��0��stmp1=(pChannel->E_Buf+pChannel->L_Buf-pChannel->P_Buf)/itmp4;
����pChannel->P_Buf��0��itmp4���п���Ϊ0��������㱣���жϴ���
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
