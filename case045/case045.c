#include "basal.h"

/*
45 �����ţ�VBUG00022605
45.1 �������
������ƣ� SIFU
�������ͣ� �޷�����������
����׶Σ�ʵ�ֽ׶�
������ԣ�C����
�ύ���ڣ� 2017��
45.2 �������
����ں���LED_Control���ж�����else if(k_led<(LED_count*10*20-300))ǰδ�ж�LED_count�Ĵ�С�����ܻᵼ�¼������
*/

unsigned char LED_count;

void case045(unsigned char k_led)
{
	if (k_led < (LED_count * 10 * 20))
	{
		/* to do something... */
	}
	else if (k_led < (LED_count * 10 * 20 - 300))
	{
		/* to do something... */
	}
	else
	{
		/* to do something... */
	}

	return;
}
