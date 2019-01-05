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
			PA0 = !PA0;								//����
			delay_ms(300);
			
			Move_Servo_Angle(70);					//����̧��20��
			delay_ms(1000);
			
			PA1 = !PA1;								//����λ��
			delay_ms(300);
			
			PA0 = !PA0;								//�յ�

			delay_ms(100);
			PA0 = !PA0;								//����
			delay_ms(100);
			PA0 = !PA0;								//�յ�
			delay_ms(50);

			PA1 = !PA1;								//����λ��
			delay_ms(500);
			
			Move_Servo_Angle(130);					//�ָ�90��λ��
			
			flag = 0;								//��־λ��λ
			memset(USART_RX_BUF,0,sizeof(USART_RX_BUF));
			printf("0\r\n");
			printf("Movement Order 1 Is Done!\r\n");	//��ӡ��ʾ��Ϣ
			
			break;
		
//		default:
//			flag = 0;								//��־λ��λ
//			printf("\r\nDo Not Received a Movement Order\r\n");					//��ӡ��ʾ��Ϣ

	}
		
}

//ͨ��IO�ڼ��100ms�͵�ƽ����
void Movement_Order_IO(void)
{
	
	if(PA2 == 0)
	{
		delay_ms(70);
		if(PA2 == 0)
		{
			PA0 = !PA0;								//����
			delay_ms(300);
			
			Move_Servo_Angle(80);					//����̧��20��
			delay_ms(1000);
			
			PA1 = !PA1;								//����λ��
			delay_ms(300);
			
			PA0 = !PA0;								//�յ�
			PA1 = !PA1;								//����λ��
			delay_ms(300);
			
			Move_Servo_Angle(110);					//�ָ�90��λ��
			
			PA3_RESET;								//���100ms�͵�ƽ�ش�
			delay_ms(100);
			PA3_SET;
			
			printf("0\r\n");
			printf("Movement Order Is Done!\r\n");	//��ӡ��ʾ��Ϣ
		}
		
	}
	
}



