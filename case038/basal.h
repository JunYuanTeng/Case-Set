#ifndef __BASAL_H__
#define __BASAL_H__

#define READ_ADDR_UI32(addr) (*((volatile unsigned int*)(addr)))
#define READ_ADDR_SI32(addr) (*((volatile signed int*)(addr)))

extern double floor(double);

#endif
