#include "basal.h"

/*
51 �����ţ�VBUG00028877
51.1 �������
������ƣ� TXCL
�������ͣ� �з�����������
����׶Σ�ʵ�ֽ׶�
������ԣ�C����
�ύ���ڣ� 2018��
51.2 �������
֡����all_data.N_frameNumΪInt�����ݣ����з����������ݣ����ڽ��յ�һ����Ŀ�����ݺ󣬸ñ�������++������
������丳ֵ���޷������ͱ���cur_frame_number����++����󣨼�����λ����1����������cur_frame_number���һ����������
*/

#define ADDR_TC 0x40101000

int N_frameNum;
unsigned int cur_frame_number;

void case051(void)
{
	unsigned int flag;

	flag = READ_ADDR_UI32(ADDR_TC);
	if (0x1 == (flag & 0x1))
	{
		/* to do something */
		N_frameNum++;
	}

	cur_frame_number = N_frameNum;
}