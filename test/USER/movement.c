#include "servo.h"
#include "usart.h"
#include "gpio.h"
#include "delay.h"
#include "string.h"

void Movement_Order(void)
{
	u8 flag=0;
	
	if(USART_RX_BUF[0] == '1')
	{
		flag = 1;
	}
	
	switch(flag)
	{
		case 1:
			PA0 = !PA0;								//出刀
			delay_ms(300);
			
			Move_Servo_Angle(70);					//向上抬起20度
			delay_ms(1000);
			
			PA1 = !PA1;								//出限位板
			delay_ms(300);
			
			PA0 = !PA0;								//收刀

			delay_ms(100);
			PA0 = !PA0;								//出刀
			delay_ms(100);
			PA0 = !PA0;								//收刀
			delay_ms(50);

			PA1 = !PA1;								//收限位板
			delay_ms(500);
			
			Move_Servo_Angle(130);					//恢复90度位置
			
			flag = 0;								//标志位复位
			memset(USART_RX_BUF,0,sizeof(USART_RX_BUF));
			printf("0\r\n");
			printf("Movement Order 1 Is Done!\r\n");	//打印提示信息
			
			break;
		
//		default:
//			flag = 0;								//标志位复位
//			printf("\r\nDo Not Received a Movement Order\r\n");					//打印提示信息

	}
		
}

//通过IO口检测100ms低电平触发
void Movement_Order_IO(void)
{
	
	if(PA2 == 0)
	{
		delay_ms(70);
		if(PA2 == 0)
		{
			PA0 = !PA0;								//出刀
			delay_ms(300);
			
			Move_Servo_Angle(80);					//向上抬起20度
			delay_ms(1000);
			
			PA1 = !PA1;								//出限位板
			delay_ms(300);
			
			PA0 = !PA0;								//收刀
			PA1 = !PA1;								//收限位板
			delay_ms(300);
			
			Move_Servo_Angle(110);					//恢复90度位置
			
			PA3_RESET;								//输出100ms低电平回传
			delay_ms(100);
			PA3_SET;
			
			printf("0\r\n");
			printf("Movement Order Is Done!\r\n");	//打印提示信息
		}
		
	}
	
}



