#include "basal.h"

/*
42 �����ţ�VBUG00021683
42.1 �������
������ƣ� JXB2
�������ͣ� �޷�����������
����׶Σ�ʵ�ֽ׶�
������ԣ�C����
�ύ���ڣ� 2017��
42.2 �������
����ʣ��ɴ洢�Ĵ�����Ϣ����ʱ��
�����ּ���������ת���ܳ���p_flash->savable_err_cntС��p_flash->saved_err_cnt��������������δ���п��ǣ�
����p_flash->savable_err_cnt��ȥp_flash->saved_err_cnt����λ�����������������
*/

typedef struct  
{
	unsigned char logErr[256];
	unsigned char savable_err_cnt;
	unsigned char saved_err_cnt;
} SFLashInfo;

void case041(SFLashInfo *p_flash, unsigned char errId)
{
	unsigned char rest = p_flash->savable_err_cnt - p_flash->saved_err_cnt;
	p_flash->logErr[rest] = errId;
	p_flash->savable_err_cnt--;
	p_flash->saved_err_cnt++;

	return;
}
