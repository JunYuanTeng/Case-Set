#include "basal.h"

/*
74 �����ţ�VBUG00027982
74.1 �������
������ƣ�BWTXCL
�������ͣ� �޷�����������
����׶Σ�ʵ�ֽ׶�
������ԣ�C����
�ύ���ڣ� 2018��
74.2 �������
1�������Pullen_track.c��223�м���epk_tempʱ������Ϊ������FPAG��ã����ڳ���Ϊ0�Ŀ��ܡ�
2��CN0_estimate.c��78��M-CN0_Estimate_TF.NP[ii]��Ϊ�������ڵ�����Ŀ��ܡ�
*/

#define ADDR_EPK 0x20010010

void case074(void)
{
	unsigned int EPK;
	double dEPK;
	double epk_temp;

	EPK = READ_ADDR_UI32(ADDR_EPK);
	dEPK = ((double)((int)EPK)) * 0.125;
	epk_temp = 1.0 / dEPK;

	return;
}
