#include "led.h"

//��ʼ��PC13Ϊ���.��ʹ��ʱ��	    
//LED IO��ʼ��
void LED_Init(void)
{
    GPIO_InitTypeDef GPIO_Initure;

    __HAL_RCC_GPIOC_CLK_ENABLE();           	//����GPIOBʱ��
	
    GPIO_Initure.Pin=GPIO_PIN_13; 				//PC13
    GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP;  	//�������
    GPIO_Initure.Pull=GPIO_PULLUP;          	//����
    GPIO_Initure.Speed=GPIO_SPEED_HIGH;    	 	//����
    HAL_GPIO_Init(GPIOC,&GPIO_Initure);

    HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,GPIO_PIN_SET);	//PB5��1��Ĭ�ϳ�ʼ�������
}
