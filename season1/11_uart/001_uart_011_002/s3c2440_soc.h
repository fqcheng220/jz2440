/**
* gpio
*/
#define GPFCON *((unsigned int*)0x56000050)
#define GPFDAT *((unsigned int*)0x56000054)
#define GPGCON *((unsigned int*)0x56000060)
#define GPGDAT *((unsigned int*)0x56000064)
#define GPHCON *((unsigned int*)0x56000070)
#define GPHDAT *((unsigned int*)0x56000074)
#define GPHUP *((unsigned int*)0x56000078)


/**
* uart
*/
#define ULCON0 *((unsigned int*)0x50000000)
#define UCON0 *((unsigned int*)0x50000004)
#define UBRDIV0 *((unsigned int*)0x50000028)
//发送寄存器
#define UTXH0_L *((unsigned char*)0x50000020)
#define UTXH0_B *((unsigned char*)0x50000023)
//接收寄存器
#define URXH0_L *((unsigned char*)0x50000024)
#define URXH0_B *((unsigned char*)0x50000027)
//状态寄存器
#define UTRSTAT0 *((unsigned int*)0x50000010)
