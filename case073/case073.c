#include "basal.h"

/*
73 问题编号：VBUG00024083
73.1 问题概述
软件名称：KDZC
问题类型： 无符号整数上溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2017年
73.2 问题分析
函数Mode_Analyze中temp_x=floor((ana_objt[i]-min_objt)/x_hist_num);
temp_x = (hist2[i].sum)/(hist2[i].num);等语句中存在变量作为除数，而缺少除零保护措施。
PRI_Eigenvector1函数、OrbitalParaMatch函数、LS_LineMatch函数、CAF_calc函数、Dadi2Digu函数、DiguCart2Dadi函数、QR函数、Matrix_Inv函数、crlb_tfdoa等函数中也存在此问题。
*/

void case073(void)
{
	//temp_x = floor((ana_objt[i] - min_objt) / x_hist_num);

	return;
}
