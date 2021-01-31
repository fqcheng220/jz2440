#include "s3c2440_soc.h"

void uart_init(){
	//����UART0ͨ��
	//GPH2 GPH3��Ӧ���ó�TXD0 RXD0
	//�Ĵ�������:
	//GPHCON ��ӦΪ0b10
	GPHCON |= 10 << 4;//0b1010

	GPHUP &= ~((1<<2) | (1<<3));  /* ʹ���ڲ����� */

	//���ò�����
	//�Ĵ�������:
	//UBRDIVn ���㹫ʽUBRDIVn = (int)( UART clock / ( buad rate x 16) ) �1
	//PCLKΪ40MHZʱ��
	//UBRDIVn = (int)(40000000 / (115200 x 16) ) -1
	//= (int)(21.7) -1 [round to the nearest whole number]
	//= 22 -1 = 21
	UBRDIV0 |= 0x15;

	//PCLKΪ50MHZʱ��
	//UBRDIVn = (int)(50000000 / (115200 x 16) ) -1
	//= (int)(27.1) -1 [round to the nearest whole number]
	//= 27 -1 = 26
	//UBRDIV0 |= 26;

	//���ô����ʽ
	//�Ĵ�������:
	//ULCONn  [1:0]����λ��� [2]ֹͣλ��� ��5��3��У��ģʽ ��6������ģʽ
	ULCON0 |= 0x03;//0b00000011 8������λ 1��ֹͣλ

	/* �����ж�Դ �жϷ�ʽ*/
	/**
	 * �ж�ԴΪPCLK ѡ���жϷ�ʽ���߲�ѯ��ʽ��ΪUART����ģʽ�ͽ���ģʽ
	 */
	//�Ĵ�������:
	//UCON0 [1:0]����ģʽ [3:2]����ģʽ
	//��ֵ0b0101
	UCON0 |= 0x05;

}

// void uart_init()
// {
//     //����UART0ͨ��
//     //GPH2 GPH3��Ӧ���ó�TXD0 RXD0
//     //�Ĵ�������:
//     //GPHCON ��ӦΪ0b10
//     GPHCON &= ~(3 << 4) & ~(3 << 6);
//     GPHCON |= 10 << 4;//0b1010

//     GPHUP &= ~((1 << 2) | (1 << 3)); /* ʹ���ڲ����� */

//     /* �����ж�Դ �жϷ�ʽ*/
//     /**
//      * �ж�ԴΪPCLK ѡ���жϷ�ʽ���߲�ѯ��ʽ��ΪUART����ģʽ�ͽ���ģʽ
//      */
//     //�Ĵ�������:
//     //UCON0 [1:0]����ģʽ [3:2]����ģʽ
//     //��ֵ0b0101
//     UCON0 |= 0x05;

//     //���ò�����
//     //�Ĵ�������:
//     //UBRDIVn ���㹫ʽUBRDIVn = (int)( UART clock / ( buad rate x 16) ) �1
//     //PCLKΪ40MHZʱ��
//     //UBRDIVn = (int)(40000000 / (115200 x 16) ) -1
//     //= (int)(21.7) -1 [round to the nearest whole number]
//     //= 22 -1 = 21
//     //UBRDIV0 |= 0x15;

//     //PCLKΪ50MHZʱ��
//     //UBRDIVn = (int)(50000000 / (115200 x 16) ) -1
//     //= (int)(27.1) -1 [round to the nearest whole number]
//     //= 27 -1 = 26
//     UBRDIV0 |= 26;

//     //���ô����ʽ
//     //�Ĵ�������:
//     //ULCONn  [1:0]����λ��� [2]ֹͣλ��� ��5��3��У��ģʽ ��6������ģʽ
//     ULCON0 |= 0x03;//0b00000011 8������λ 1��ֹͣλ
// }

// void uart_init()
// {
//     //����UART0ͨ��
//     //GPH2 GPH3��Ӧ���ó�TXD0 RXD0
//     //�Ĵ�������:
//     //GPHCON ��ӦΪ0b10
//     GPHCON &= ~(3 << 4) & ~(3 << 6);
//     GPHCON |= ((2<<4) | (2<<6));//0b1010

//     GPHUP &= ~((1 << 2) | (1 << 3)); /* ʹ���ڲ����� */

//     /* �����ж�Դ �жϷ�ʽ*/
//     /**
//      * �ж�ԴΪPCLK ѡ���жϷ�ʽ���߲�ѯ��ʽ��ΪUART����ģʽ�ͽ���ģʽ
//      */
//     //�Ĵ�������:
//     //UCON0 [1:0]����ģʽ [3:2]����ģʽ
//     //��ֵ0b0101
//     UCON0 = 0x00000005;

//     //���ò�����
//     //�Ĵ�������:
//     //UBRDIVn ���㹫ʽUBRDIVn = (int)( UART clock / ( buad rate x 16) ) �1
//     //PCLKΪ40MHZʱ��
//     //UBRDIVn = (int)(40000000 / (115200 x 16) ) -1
//     //= (int)(21.7) -1 [round to the nearest whole number]
//     //= 22 -1 = 21
//     //UBRDIV0 |= 0x15;

//     //PCLKΪ50MHZʱ��
//     //UBRDIVn = (int)(50000000 / (115200 x 16) ) -1
//     //= (int)(27.1) -1 [round to the nearest whole number]
//     //= 27 -1 = 26
//     UBRDIV0 = 26;

//     //���ô����ʽ
//     //�Ĵ�������:
//     //ULCONn  [1:0]����λ��� [2]ֹͣλ��� ��5��3��У��ģʽ ��6������ģʽ
//     ULCON0 = 0x00000003;//0b00000011 8������λ 1��ֹͣλ
// }

void uart_putchar(char ch)
{
    //״̬�Ĵ���
    //�Ĵ������壺
    //UTRSTAT0 [0]���ܻ��������ݾ��� [1]���ͻ������� [2]������Ϊ��
    while((UTRSTAT0 & 4) == 0);
    //��������
    //�Ĵ�������:
    //UTXHn
    UTXH0_L = ch;
}

char uart_getchar()
{
    //״̬�Ĵ���
    //�Ĵ������壺
    //UTRSTAT0 [0]���ܻ��������ݾ��� [1]���ͻ������� [2]������Ϊ��
    while((UTRSTAT0 & 1) == 0);
    //��������
    //�Ĵ�������:
    //URXHn
    return URXH0_L;
}

void uart_putchars(char *chars)
{
    //�մ�\0j����
    while(*chars){
    	uart_putchar(*chars);
    	chars++;
    }
    // uart_putchar(*chars);
    // UTXH0_L = 'A';
}