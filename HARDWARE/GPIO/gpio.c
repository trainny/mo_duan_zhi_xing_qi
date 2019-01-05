#include "gpio.h"
#include "usart.h"
#include "string.h"

void GPIOA_Init(void)
{
	GPIO_InitTypeDef GPIO_Initure;

    __HAL_RCC_GPIOC_CLK_ENABLE();           	//开启GPIOA时钟
	
    GPIO_Initure.Pin=GPIO_PIN_0|GPIO_PIN_1; 	//PA0,PA1
    GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP;  	//推挽输出
    GPIO_Initure.Pull=GPIO_PULLUP;          	//上拉
    GPIO_Initure.Speed=GPIO_SPEED_HIGH;    	 	//高速
    HAL_GPIO_Init(GPIOA,&GPIO_Initure);
	
	GPIO_Initure.Pin=GPIO_PIN_3; 	//PA3
    HAL_GPIO_Init(GPIOA,&GPIO_Initure);

	GPIO_Initure.Pin=GPIO_PIN_2; 	//PA2
    GPIO_Initure.Mode=GPIO_MODE_INPUT;  	//输入模式
	HAL_GPIO_Init(GPIOA,&GPIO_Initure);

    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0|GPIO_PIN_1,GPIO_PIN_RESET);	//PA0,PA1置1
    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2|GPIO_PIN_3,GPIO_PIN_SET);	//PA2,PA3置1

}

void GPIO_Test_Order(void)
{
	u8 flag=0;
	
	if(USART_RX_BUF[0] == '6')
	{
		flag = 6;
	}
	
	else if(USART_RX_BUF[0] == '7')
	{
		flag = 7;
	}
	
	else if(USART_RX_BUF[0] == '8')
	{
		flag = 8;
	}
	
	else if(USART_RX_BUF[0] == '9')
	{
		flag = 9;
	}
	
	switch(flag)							//执行相应命令操作
	{
		case 6:
			PA0_SET;
			flag = 0;										//标志位复位
			memset(USART_RX_BUF,0,sizeof(USART_RX_BUF));
			printf("GPIO Test-Order 2 Is Done!\r\n");	//打印提示信息
			break;
		
		case 7:
			PA0_RESET;
			flag = 0;										//标志位复位
			memset(USART_RX_BUF,0,sizeof(USART_RX_BUF));
			printf("GPIO Test-Order 3 Is Done!\r\n");	//打印提示信息
			break;
		case 8:
			PA1_SET;
			flag = 0;										//标志位复位
			memset(USART_RX_BUF,0,sizeof(USART_RX_BUF));
			printf("GPIO Test-Order 4 Is Done!\r\n");	//打印提示信息
			break;
		case 9:
			PA1_RESET;
			flag = 0;										//标志位复位
			memset(USART_RX_BUF,0,sizeof(USART_RX_BUF));
			printf("GPIO Test-Order 5 Is Done!\r\n");	//打印提示信息
			break;

//		default:
//			flag = 0;										//标志位复位
//			printf("Do Not Received a GPIO Test-Order\r\n");			//打印提示信息

	}

}




