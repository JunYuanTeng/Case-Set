#include "basal.h"

/*
47 �����ţ�VBUG00025675
47.1 �������
������ƣ� PDXWJ
�������ͣ� �޷�����������
����׶Σ�ʵ�ֽ׶�
������ԣ�C����
�ύ���ڣ� 2017��
47.2 �������
�����120·ģ����ң�����ݽ��вɼ���ģ����ÿһ·ң��ɼ�ֵN��ʹ����λ��+5V��׼ң��Ĳɼ�ֵN5����ͬԴУ׼��
У׼��ʽ��У׼ֵ=��N/N5����1000.0��
��λ��+5V��׼ң��Ĳɼ�ֵ��AD�ɼ���ĳһ·ֵ�������ֵ��
����ڽ���У׼ǰû�ж���λ��+5V��׼ң��Ĳɼ�ֵ��Χ�����޶�����������ɼ�����λ��+5V��׼ң��ֵ��һ����С��ֵ����Ϊ������������������
*/

#define NUM_ANG 120

#define EQU 0.125
#define ADDR_BASE 0x20101000
#define ADDR_ANG  0x20102000

double ANGM[NUM_ANG];
double ANGBase;

void case047(void)
{
	int i;
	int i32Base;
	int i32Ang;

	i32Base = READ_ADDR_SI32(ADDR_BASE);
	ANGBase = i32Base * EQU;

	for (i = 0; i < NUM_ANG; i++)
	{
		i32Ang = READ_ADDR_SI32(ADDR_ANG + i * 4);
		ANGM[i] = i32Ang * EQU;
		ANGM[i] = (ANGM[i] / ANGBase) * 1000.0;
	}

	return;
}
