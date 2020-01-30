#include "basal.h"

/*
50 �����ţ�VBUG00027489
50.1 �������
������ƣ� DHJSJ
�������ͣ� �з�����������
����׶Σ�ʵ�ֽ׶�
������ԣ�C����
�ύ���ڣ� 2018��
50.2 �������
������Selftest.c��L704�н�����sdram_countָ��Ϊchar�����飬
��L721�е�ѭ�����ڶ������+1������ѭ������Զ����char�ͱ�����ʾ��Χ��
���ܵ��±���sdram_count�����֮����L730�ж�����if�Ľ�������ǲ�׼ȷ��
*/

#define ADDR_RAM 0x2000000
#define SIZE_RAM 0x8000

void case050(void)
{
	int i;
	char sdram_count;
	unsigned int valRam;

	sdram_count = 0;
	for (i = 0; i < SIZE_RAM; i = i + 4)
	{
		valRam = READ_ADDR_UI32(ADDR_RAM + i);
		if (0xFFFFFFFF == valRam)
		{
			/* ������� */
			sdram_count++;
		}
	}

	/* �жϿ��ܲ�׼ȷ */
	if (sdram_count == 0x37)
	{
		/* to do something */
	}

	return;
}
