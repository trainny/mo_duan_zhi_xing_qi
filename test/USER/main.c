#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "timer.h"
#include "servo.h"
#include "gpio.h"
#include "movement.h"
#include "string.h"

int main(void)
{	
	
    HAL_Init();                    	 	//初始化HAL库    
    Stm32_Clock_Init(RCC_PLL_MUL9);   	//设置时钟,72M
	delay_init(72);               		//初始化延时函数
	uart_init(115200);					//初始化串口
	LED_Init();							//初始化LED	
	GPIOA_Init();
	TIM2_Init(4000-1,7200-1);           //TIM2定时200ms
	TIM3_PWM_Init(200-1,7200-1);		//舵机信号初始化,自动重装值:200-1,时钟预分频数:7200-1,频率:50HZ
	
	Move_Servo_Angle(130);				//舵机复位
	printf("Ready\r\n");
	
    while(1)
    {
		//Movement_Order_IO();			//末端执行器接收信号引脚PA2，结束反馈信号引脚PA3	
    }
}




