#include "basal.h"
/*
75.1 �������
������ƣ�JHJZJ
�������ͣ� �޷�����������
����׶Σ�ʵ�ֽ׶�
������ԣ�C����
�ύ���ڣ� 2018��
75.2 �������
"L762~L765��
VDD = 12276/VBG;
VTEM25 = 6900/VDD; 
VHOT =  1809/VDD; 
VCOLD =  1900/VDD;����VBG��VDDΪ0�����δ����"
*/

unsigned int ADDR_VBG = 0x21001000;
unsigned int ADDR_VDD = 0x21001004;

unsigned int VBG;
unsigned int VDD;

unsigned int VHOT;
unsigned int VCOLD;

void case075(void)
{
	unsigned int VTEM25;

	VBG = READ_ADDR_UI32(ADDR_VBG);
	VDD = READ_ADDR_UI32(ADDR_VDD);

	VDD = 12276/VBG;
	VTEM25 = 6900/VDD; 
	VHOT =  1809/VDD; 
	VCOLD =  1900/VDD;

	return;
}
