#include "basal.h"

/*
46 �����ţ�VBUG00023809
46.1 �������
������ƣ� KDZC
�������ͣ� �޷�����������
����׶Σ�ʵ�ֽ׶�
������ԣ�C����
�ύ���ڣ� 2017��
46.2 �������
���ampL_mean=ampL_mean/AmpL[IdxPDW][0]�������ų�AmpL[IdxPDW][0]Ϊ0��������������AmpL[IdxPDW][0]������������
*/

float AmpL[12][3];
float ampL_mean;

void case046(int IdxPDW)
{
	ampL_mean = ampL_mean/AmpL[IdxPDW][0];

	return;
}
