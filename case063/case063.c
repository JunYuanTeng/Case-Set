#include "basal.h"

/*
63 �����ţ�VBUG00004290
63.1 �������
������ƣ�XJRK
�������ͣ� �޷�����������
����׶Σ�ʵ�ֽ׶�
������ԣ�C����
�ύ���ڣ� 2012��
63.2 �������
�ں���CollectData()�У�����381�к�385�У���value[1]��value[0]���ʱ��ĸΪ�㣬����ɳ���������Գ�������û�н��б�����
*/

int dataCollected[4];

void CollectData(int value[])
{
	value[3] = value[2] / (value[1] - value[0]);

	return;
}

void case063(void)
{
	CollectData(dataCollected);

	return;
}
