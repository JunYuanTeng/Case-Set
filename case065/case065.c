#include "basal.h"

/*
65 �����ţ�VBUG00005401
65.1 �������
������ƣ�XHCL
�������ͣ� �޷�����������
����׶Σ�ʵ�ֽ׶�
������ԣ�C����
�ύ���ڣ� 2012��
65.2 �������
�������g_dTargetPowerMaxΪ�źŹ��ʼ�ֵ���������������ʱ�������±��ʽ���㵱ǰ�������ޣ�
temp = 10*log10(g_dTargetPowerMax*DELTA_NEAR/g_dNoisePower);
temp = 10*log10(g_dTargetPowerMax*DELTA_FAR/g_dNoisePower);
�������δ��g_dTargetPowerMax��g_dNoisePowerΪ0��������б��������¼���������10*log10��0�����߳���Ϊ0���������ɼ������
*/

extern double log10(double);

#define DELTA_NEAR 0.125
#define DELTA_FAR  0.5

double g_dTargetPowerMax;
double g_dNoisePower;

void case065(double powerNow)
{
	double temp1;
	double temp2;

	temp1 = 10.0 * log10(g_dTargetPowerMax*DELTA_NEAR/g_dNoisePower);
	temp2 = 10.0 * log10(g_dTargetPowerMax*DELTA_FAR/g_dNoisePower);

	if (powerNow < temp1)
	{
		/* to do something */
	} 
	else if (powerNow > temp2)
	{
		/* to do something */
	}
	else
	{
		/* to do something */
	}

	return;
}
