#include "basal.h"

/*
71 �����ţ�VBUG00022103
71.1 �������
������ƣ�NYGL
�������ͣ� �޷�����������
����׶Σ�ʵ�ֽ׶�
������ԣ�C����
�ύ���ڣ� 2017��
71.2 �������
�����2533�м���ģ��������ֵ��JZADV2[i] = (JZADV1[i] - JZVgnd) / JZa�����㹫ʽ�У�JZa�޷���֤��Ϊ0���������ӳ�0������
*/

#define NUM_JZA 12

#define ADDR_JZVgnd 0x20100010
#define ADDR_JZa    0x20100004
#define ADDR_JZADV  0x20100020

double JZADV2[NUM_JZA];
double JZADV1[NUM_JZA];
double JZVgnd;
double JZa;

void case071(void)
{
	int i;

	JZVgnd = READ_ADDR_SI32(ADDR_JZVgnd);
	JZa = READ_ADDR_SI32(ADDR_JZa);

	for (i = 0; i < NUM_JZA; i++)
	{
		JZADV1[i] = READ_ADDR_SI32(ADDR_JZADV + i * 4);
		JZADV2[i] = (JZADV1[i] - JZVgnd) / JZa;
	}

	return;
}
