#include "basal.h"

/*
44 �����ţ�VBUG00021908
44.1 �������
������ƣ� YXFP
�������ͣ� �޷�����������
����׶Σ�ʵ�ֽ׶�
������ԣ�C����
�ύ���ڣ� 2017��
44.2 �������
����������Ҫ�󣬵�һ�βɼ���·ģ����ʱ����Ҫ��¼���һ�βɼ���ֵ��Ϊ�������г����жϵĳ�ֵ��
�˲���Ӧֻ����һ�Σ�����������flag�ۼ�Ϊ1ʱ��������������
���������ʵ��ʱ����������flag��Ϊ1��ÿ��ѭ��������Ȼ�ڼ����ۼӣ�
����������ڼ䣬��unsigned char�ͼ��������п��ܳ�����������
���¼�������flag���»�0�ٽ����ۼӣ��ɴ˵�����һ��������flag����1�������������ֶ�ģ������ֵ�����˸��ģ�ʹ�ý��г����жϵĳ�ֵ��һ�¡�
*/

#define ADDR_ANG1 0x22001000
#define ADDR_ANG2 0x20001004

unsigned char flag;
unsigned int ang1;
unsigned int ang2;
unsigned int thr1;
unsigned int thr2;

void case044(void)
{
	flag = 1;

	while(1)
	{
		ang1 = READ_ADDR_UI32(ADDR_ANG1);
		ang2 = READ_ADDR_UI32(ADDR_ANG2);

		if (flag == 1)
		{
			thr1 = ang1;
			thr2 = ang2;
		}

		flag++;
	}
}
