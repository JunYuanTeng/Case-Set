#include "basal.h"

/*
53 �����ţ�VBUG00029199
53.1 �������
������ƣ�GNC 
�������ͣ� �޷�����������
����׶Σ�ʵ�ֽ׶�
������ԣ�C����
�ύ���ڣ� 2018��
53.2 �������
������6.1Ҫ������ڹ�����һ�����ϣ�������ʧЧ��
�������ʱ�ɼ�ʱ��1031��1032�У���ʹ��PeriodCount * 128��
���������ڼ���Ϊunsigned int���ͣ�����128���ܻ�������������50�������
*/

unsigned int StarTimeMs;
unsigned int PeriodCount;

void case053(void)
{
	StarTimeMs = PeriodCount * 128;

	return;
}
