#include "basal.h"

/*
41 问题编号：VBUG00021508
41.1 问题概述
软件名称： JXB1
问题类型： 无符号整数下溢
引入阶段：实现阶段
编程语言：C语言
提交日期： 2017年
41.2 问题分析
计算剩余可存储的错误信息条数时，
若出现计数变量翻转可能出现p_flash->savable_err_cnt小于p_flash->saved_err_cnt的情况，但是软件未进行考虑，
导致p_flash->savable_err_cnt减去p_flash->saved_err_cnt的数位溢出数，计算结果出错
*/

typedef struct  
{
	unsigned char logErr[256];
	unsigned char savable_err_cnt;
	unsigned char saved_err_cnt;
} SFLashInfo;

void case041(SFLashInfo *p_flash, unsigned char errId)
{
	unsigned char rest = p_flash->savable_err_cnt - p_flash->saved_err_cnt;
	p_flash->logErr[rest] = errId;
	p_flash->savable_err_cnt--;
	p_flash->saved_err_cnt++;

	return;
}
