#include "basal.h"

/*
62 �����ţ�VBUG00010533
62.1 �������
������ƣ�CTU
�������ͣ� �޷�����������
����׶Σ�ʵ�ֽ׶�
������ԣ�C����
�ύ���ڣ� 2014��
62.2 �������
����������²���ʱ��XJ_gain = 429 * log10((( XJ_k1/acs_sinRTS ) + XJ_k2 )/( XJ_stage/16 ))��
���δ���ӶԱ���acs_sinRTSΪ0����ı������������acs_sinRTSΪ0�����¼���������
*/

extern int log10(int);

int case062(int XJ_k1, int XJ_k2, int acs_sinRTS, int XJ_stage)
{
	int XJ_gain;
	XJ_gain = 429 * log10((( XJ_k1 / acs_sinRTS ) + XJ_k2 )/( XJ_stage/16 ));

	return XJ_gain;
}
