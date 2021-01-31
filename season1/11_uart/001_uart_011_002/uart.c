#include "s3c2440_soc.h"

void uart_init(){
	//设置UART0通道
	//GPH2 GPH3对应配置成TXD0 RXD0
	//寄存器释义:
	//GPHCON 对应为0b10
	GPHCON |= 10 << 4;//0b1010

	GPHUP &= ~((1<<2) | (1<<3));  /* 使能内部上拉 */

	//设置波特率
	//寄存器释义:
	//UBRDIVn 计算公式UBRDIVn = (int)( UART clock / ( buad rate x 16) ) 鈥1
	//PCLK为40MHZ时候
	//UBRDIVn = (int)(40000000 / (115200 x 16) ) -1
	//= (int)(21.7) -1 [round to the nearest whole number]
	//= 22 -1 = 21
	UBRDIV0 |= 0x15;

	//PCLK为50MHZ时候
	//UBRDIVn = (int)(50000000 / (115200 x 16) ) -1
	//= (int)(27.1) -1 [round to the nearest whole number]
	//= 27 -1 = 26
	//UBRDIV0 |= 26;

	//设置传输格式
	//寄存器释义:
	//ULCONn  [1:0]数据位宽度 [2]停止位宽度 【5：3】校验模式 【6】红外模式
	ULCON0 |= 0x03;//0b00000011 8个数据位 1个停止位

	/* 设置中断源 中断方式*/
	/**
	 * 中断源为PCLK 选择中断方式或者查询方式作为UART发送模式和接收模式
	 */
	//寄存器释义:
	//UCON0 [1:0]接收模式 [3:2]发送模式
	//赋值0b0101
	UCON0 |= 0x05;

}

// void uart_init()
// {
//     //设置UART0通道
//     //GPH2 GPH3对应配置成TXD0 RXD0
//     //寄存器释义:
//     //GPHCON 对应为0b10
//     GPHCON &= ~(3 << 4) & ~(3 << 6);
//     GPHCON |= 10 << 4;//0b1010

//     GPHUP &= ~((1 << 2) | (1 << 3)); /* 使能内部上拉 */

//     /* 设置中断源 中断方式*/
//     /**
//      * 中断源为PCLK 选择中断方式或者查询方式作为UART发送模式和接收模式
//      */
//     //寄存器释义:
//     //UCON0 [1:0]接收模式 [3:2]发送模式
//     //赋值0b0101
//     UCON0 |= 0x05;

//     //设置波特率
//     //寄存器释义:
//     //UBRDIVn 计算公式UBRDIVn = (int)( UART clock / ( buad rate x 16) ) 鈥1
//     //PCLK为40MHZ时候
//     //UBRDIVn = (int)(40000000 / (115200 x 16) ) -1
//     //= (int)(21.7) -1 [round to the nearest whole number]
//     //= 22 -1 = 21
//     //UBRDIV0 |= 0x15;

//     //PCLK为50MHZ时候
//     //UBRDIVn = (int)(50000000 / (115200 x 16) ) -1
//     //= (int)(27.1) -1 [round to the nearest whole number]
//     //= 27 -1 = 26
//     UBRDIV0 |= 26;

//     //设置传输格式
//     //寄存器释义:
//     //ULCONn  [1:0]数据位宽度 [2]停止位宽度 【5：3】校验模式 【6】红外模式
//     ULCON0 |= 0x03;//0b00000011 8个数据位 1个停止位
// }

// void uart_init()
// {
//     //设置UART0通道
//     //GPH2 GPH3对应配置成TXD0 RXD0
//     //寄存器释义:
//     //GPHCON 对应为0b10
//     GPHCON &= ~(3 << 4) & ~(3 << 6);
//     GPHCON |= ((2<<4) | (2<<6));//0b1010

//     GPHUP &= ~((1 << 2) | (1 << 3)); /* 使能内部上拉 */

//     /* 设置中断源 中断方式*/
//     /**
//      * 中断源为PCLK 选择中断方式或者查询方式作为UART发送模式和接收模式
//      */
//     //寄存器释义:
//     //UCON0 [1:0]接收模式 [3:2]发送模式
//     //赋值0b0101
//     UCON0 = 0x00000005;

//     //设置波特率
//     //寄存器释义:
//     //UBRDIVn 计算公式UBRDIVn = (int)( UART clock / ( buad rate x 16) ) 鈥1
//     //PCLK为40MHZ时候
//     //UBRDIVn = (int)(40000000 / (115200 x 16) ) -1
//     //= (int)(21.7) -1 [round to the nearest whole number]
//     //= 22 -1 = 21
//     //UBRDIV0 |= 0x15;

//     //PCLK为50MHZ时候
//     //UBRDIVn = (int)(50000000 / (115200 x 16) ) -1
//     //= (int)(27.1) -1 [round to the nearest whole number]
//     //= 27 -1 = 26
//     UBRDIV0 = 26;

//     //设置传输格式
//     //寄存器释义:
//     //ULCONn  [1:0]数据位宽度 [2]停止位宽度 【5：3】校验模式 【6】红外模式
//     ULCON0 = 0x00000003;//0b00000011 8个数据位 1个停止位
// }

void uart_putchar(char ch)
{
    //状态寄存器
    //寄存器释义：
    //UTRSTAT0 [0]接受缓存区数据就绪 [1]发送缓冲区空 [2]发送器为空
    while((UTRSTAT0 & 4) == 0);
    //发送数据
    //寄存器释义:
    //UTXHn
    UTXH0_L = ch;
}

char uart_getchar()
{
    //状态寄存器
    //寄存器释义：
    //UTRSTAT0 [0]接受缓存区数据就绪 [1]发送缓冲区空 [2]发送器为空
    while((UTRSTAT0 & 1) == 0);
    //接受数据
    //寄存器释义:
    //URXHn
    return URXH0_L;
}

void uart_putchars(char *chars)
{
    //空串\0j结束
    while(*chars){
    	uart_putchar(*chars);
    	chars++;
    }
    // uart_putchar(*chars);
    // UTXH0_L = 'A';
}