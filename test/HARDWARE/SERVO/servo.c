#include "servo.h"
#include "usart.h"
#include "timer.h"
#include "string.h"

void Move_Servo_Angle(u16 angle)
{
	u32 comp=0;
	comp=(u32)angle/9+5;
	TIM_SetTIM3Compare2(comp);
}

void Servo_Test_Order(void)
{
	u8 flag=0;
	
	if(USART_RX_BUF[0] == '2')			//�ж�����
	{
		flag = 2;
	}
		
	else if(USART_RX_BUF[0] == '3')
	{
		flag = 3;
	}
		
	else if(USART_RX_BUF[0] == '4')
	{
		flag = 4;
	}
	
	else if(USART_RX_BUF[0] == '5')
	{
		flag = 5;
	}
	
	switch(flag)							//ִ����Ӧ�������
	{
		case 2:
			Move_Servo_Angle(120);
			flag = 0;										//��־λ��λ
			memset(USART_RX_BUF,0,sizeof(USART_RX_BUF));
			printf("Servo Test-Order 2 Is Done!\r\n");	//��ӡ��ʾ��Ϣ
			break;
		
		case 3:
			Move_Servo_Angle(0);
			flag = 0;										//��־λ��λ
			memset(USART_RX_BUF,0,sizeof(USART_RX_BUF));
			printf("Servo Test-Order 3 Is Done!\r\n");	//��ӡ��ʾ��Ϣ
			break;
		case 4:
			Move_Servo_Angle(90);
			flag = 0;										//��־λ��λ
			memset(USART_RX_BUF,0,sizeof(USART_RX_BUF));
			printf("Servo Test-Order 4 Is Done!\r\n");	//��ӡ��ʾ��Ϣ
			break;
		case 5:
			Move_Servo_Angle(180);
			flag = 0;										//��־λ��λ
			memset(USART_RX_BUF,0,sizeof(USART_RX_BUF));
			printf("Servo Test-Order 5 Is Done!\r\n");	//��ӡ��ʾ��Ϣ
			break;

//		default:
//			flag = 0;										//��־λ��λ
//			printf("Do Not Received a Servo Test-Order\r\n");			//��ӡ��ʾ��Ϣ

	}

}







