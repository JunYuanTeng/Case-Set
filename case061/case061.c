#include "basal.h"

/*
61 �����ţ�VBUG00000669
61.1 �������
�������ƣ�YBKZQ
�������ͣ� �޷�����������
����׶Σ�ʵ�ֽ׶�
������ԣ�C����
�ύ���ڣ� 2010��
61.2 �������
�����ڸ���GPS���ݼ�����Ԥ���������������ʱ��
���������δ�жϳ����Ƿ�Ϊ0���硰a=P/(1-e*e);����eΪ֮ǰ������������ݣ����e*e����1�������ɳ���Ϊ0��
*/

float case061(float P, float e)
{
	float a;

	a = P / (1.0f - e * e);

	return a;
}