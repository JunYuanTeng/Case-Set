#include "basal.h"

/*
54 �����ţ�VBUG00030586
54.1 �������
������ƣ� SIFU1
�������ͣ� �з�����������
����׶Σ�ʵ�ֽ׶�
������ԣ�C����
�ύ���ڣ� 2018��
54.2 �������
close_control��������X/Y��Ԥ�ýǶ���X/Y��ʵ�ʽǶȵĲ�ֵ(abs((x_set_word+0x8000)-(int)A_angle))Ϊ0x8000ʱ��Ҳ��X/Y��δ��λ��
Ӧ���������Ӧ������򣬵����ھ���ֵ����abs��������Ϊint�ͣ�����ֵҲΪint�ͣ�
��0x8000Ϊ-32768��ȡ����ֵ��Ϊ32768ȴ����32767����ʱ�����Ϊ-32768��
�����޷�����abs((x_set_word+0x8000)-(int)A_angle)����5��������
ʹX/Y��δת����λ��ֹͣת������Xx20.c��L530��555��
*/

extern int abs(int);

short x_set_word;
short A_angle;

void case054(void)
{
	unsigned short delta;

	delta = abs((x_set_word+0x8000)-(int)A_angle);
	if (delta > 5)
	{
		/* stop the axis motor ... */
	}

	return;
}
