#include "basal.h"

/*
66 �����ţ�VBUG00011982
66.1 �������
������ƣ�DGJK
�������ͣ� �޷�����������
����׶Σ�ʵ�ֽ׶�
������ԣ�C����
�ύ���ڣ� 2015��
66.2 �������
����Sel_TranMatr_JtoO�Գ���normδ�����㱣����
*/

double rWGS[3];

void Sel_TranMatr_JtoO(double r[])
{
	double norm;

	norm = r[0] * r[0] + r[1] * r[1] + r[2] * r[2];

	r[0] = r[0] / norm;
	r[1] = r[1] / norm;
	r[2] = r[2] / norm;

	return;
}

void case066(void)
{
	Sel_TranMatr_JtoO(rWGS);

	return;
}
