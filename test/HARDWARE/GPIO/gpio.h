#ifndef _GPIO_H
#define _GPIO_H
#include "sys.h"

#define PA0       PAout(0)   	//PA0
#define PA0_SET   PAout(0)=1   	//PA0
#define PA0_RESET PAout(0)=0   	//PA0

#define PA1       PAout(1)   	//PA1
#define PA1_SET   PAout(1)=1   	//PA1
#define PA1_RESET PAout(1)=0   	//PA1

#define PA2       PAout(2)   	//PA2

#define PA3       PAout(3)   	//PA3
#define PA3_SET   PAout(3)=1   	//PA3
#define PA3_RESET PAout(3)=0   	//PA3

void GPIOA_Init(void);
void GPIO_Test_Order(void);

#endif
