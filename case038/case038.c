#include "basal.h"

/*
38 �����ţ�VBUG00020477
38.1 �������
������ƣ� CMU
�������ͣ� �з�����������
����׶Σ�ʵ�ֽ׶�
������ԣ�C����
�ύ���ڣ� 2017��
38.2 �������
tsk_create�������񴴽������3������arg1��arg2��arg3����������ΪUINT�޷��ţ�
���ú���szos_tsk_init�����������arg1��arg2��arg3����������ΪINT�з��ţ�
���ܵ������������
*/

extern void *tsk_create(int, int, int);

void *szos_tsk_init(unsigned int arg1, unsigned int arg2, unsigned int arg3)
{
	void *tPtr;
	tPtr = tsk_create(arg1, arg2, arg3);

	return tPtr;
}

void *task1Handle;

void case038(void)
{
	task1Handle = szos_tsk_init(0xFFFF0001, 0xFFFF0002, 0xFFFF0003);

	return;
}
