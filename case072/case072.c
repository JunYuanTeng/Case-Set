#include "basal.h"

/*
72 �����ţ�VBUG00023663
72.1 �������
������ƣ�TXZC
�������ͣ� �޷�����������
����׶Σ�ʵ�ֽ׶�
������ԣ�C����
�ύ���ڣ� 2017��
72.2 �������
SetFpgaParaSampling.c�ļ���47�У������ʼ������g_wdnc_fsΪ0����������г�����g_fs_fst/g_wdnc_fsʱ��δ�Ա���g_wdnc_fsΪ0������б�����
*/

double g_fs_fst = 0.0;
double g_wdnc_fs = 0.0;
double g_fs_div = 0.0;

void case072(void)
{
	g_fs_div = g_fs_fst / g_wdnc_fs;

	return;
}
