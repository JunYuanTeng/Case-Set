#include "basal.h"

/*
69 �����ţ�VBUG00021947
69.1 �������
������ƣ�SJCL
�������ͣ� �޷�����������
����׶Σ�ʵ�ֽ׶�
������ԣ�C����
�ύ���ڣ� 2017��
69.2 �������
XWRep.c��L1105��������䡰guiPUnReadPac = guiPUnReadPac - 478 + guiRepTemp2WCnt;����ʽ�ұ��п���Ϊ��ֵ��
������guiPUnReadPacΪ�޷������ͣ������ڽ�������ֵ���޷������ͱ����������
*/

unsigned int guiPUnReadPac;

void case069(unsigned int guiRepTemp2WCnt)
{
	guiPUnReadPac = guiPUnReadPac - 478 + guiRepTemp2WCnt;

	return;
}
