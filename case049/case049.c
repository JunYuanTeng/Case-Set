#include "basal.h"

/* 
49 �����ţ�VBUG00028514
49.1 �������
������ƣ�CDHU 
�������ͣ� �޷�����������
����׶Σ�ʵ�ֽ׶�
������ԣ�C����
�ύ���ڣ� 2018��
49.2 �������
�����֯�豸����ָ��ң��֡ʱ���������£�
servicemangepk[20]=(char)ptr_Crc16(servicemangepk, 20)>>8;
����ptr_Crc16����У��ֵʱ������ֵ����Ϊuint16�����ǿ��ת��Ϊchar���ͺ��������8λ���������������
*/

extern unsigned short ptr_Crc16(char*, int);

char servicemangepk[22];

void case049(void)
{
	unsigned short crc16;

	crc16 = ptr_Crc16(servicemangepk, 20);
	servicemangepk[20] = (char)crc16 >> 8;
	servicemangepk[21] = (char)crc16;

	return;
}
