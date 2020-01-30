#include "basal.h"

/*
59 �����ţ�VBUG00000199
59.1 �������
������ƣ� DHXX
�������ͣ� �з�����������
����׶Σ�ʵ�ֽ׶�
������ԣ�C����
�ύ���ڣ� 2010��
59.2 �������
��Nav_predict.c�е�1103��1104��û���жԱ���rsat ������rusr�ͱ���r�ĳ��㱣����
Oc =  ( rsat2+r2-rusr2 ) / ( 2*rsat*r );
Ic = -( rusr2+r2-rsat2 ) / ( 2*rusr*r );
*/

extern float sqrtX(float);

void case057(float x, float y, float z, float rsat, float rusr)
{
	float r2;
	float Oc;
	float Ic;
	float r;
	float rsat2;
	float rusr2;

	r2 = x * x + y * y + z * z;
	r = sqrtX(r2);
	rsat2 = rsat * rsat;
	rusr2 = rusr * rusr;
	Oc =  ( rsat2+r2-rusr2 ) / ( 2*rsat*r );
	Ic = -( rusr2+r2-rsat2 ) / ( 2*rusr*r );

	return;
}
