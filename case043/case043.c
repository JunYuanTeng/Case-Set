#include "basal.h"

/*
43 �����ţ�VBUG00021798
43.1 �������
������ƣ� TXXY
�������ͣ� �޷�����������
����׶Σ�ʵ�ֽ׶�
������ԣ�C����
�ύ���ڣ� 2017��
43.2 �������
bootloader�������У�����3�γ������ʧ��ʱ������Ϊuint32_t��unsigned int����loadresult����ֵΪERROR��ֵΪ-1�������ַ�Ԥ�ڵ����������
*/

#define ERROR (-1)

unsigned int loadFailCnt;
unsigned int loadresult;

void case043(void)
{
	if (loadFailCnt >= 3)
	{
		loadresult = ERROR;
	}

	return;
}
