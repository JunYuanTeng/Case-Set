#include "basal.h"

/*
52 �����ţ�VBUG00028878
52.1 �������
������ƣ� TXCL
�������ͣ� �޷�����������
����׶Σ�ʵ�ֽ׶�
������ԣ�C����
�ύ���ڣ� 2018��
52.2 �������
frame_diff��cur_frame_number��pre_frame_number��Ϊ�޷������ͱ�����
frame_diff=cur_frame_number-pre_frame_number��
�������ʱ��������frame_diffΪһ�������������ͼ�����㷨�������
*/

unsigned int frame_diff;
unsigned int cur_frame_number;
unsigned int pre_frame_number;

void case052(void)
{
	frame_diff = cur_frame_number - pre_frame_number;

	return;
}
