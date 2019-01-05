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
	
    HAL_Init();                    	 	//��ʼ��HAL��    
    Stm32_Clock_Init(RCC_PLL_MUL9);   	//����ʱ��,72M
	delay_init(72);               		//��ʼ����ʱ����
	uart_init(115200);					//��ʼ������
	LED_Init();							//��ʼ��LED	
	GPIOA_Init();
	TIM2_Init(4000-1,7200-1);           //TIM2��ʱ200ms
	TIM3_PWM_Init(200-1,7200-1);		//����źų�ʼ��,�Զ���װֵ:200-1,ʱ��Ԥ��Ƶ��:7200-1,Ƶ��:50HZ
	
	Move_Servo_Angle(130);				//�����λ
	printf("Ready\r\n");
	
    while(1)
    {
		//Movement_Order_IO();			//ĩ��ִ���������ź�����PA2�����������ź�����PA3	
    }
}




