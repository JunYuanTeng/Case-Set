#include "basal.h"

/*
68 �����ţ�VBUG00017339
68.1 �������
������ƣ�ZDKZ
�������ͣ� �޷�����������
����׶Σ�ʵ�ֽ׶�
������ԣ�C����
�ύ���ڣ� 2016��
68.2 �������
WK_Comm.c��L182��L246��ber_rate = ber/ber_all;û�н��г��㱣����
*/

double ber_all;
double ber_rate;

void case068(double ber)
{
	ber_rate = ber/ber_all;
	ber_all = ber_all + ber;

	return;
}
