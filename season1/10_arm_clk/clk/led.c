#include "s3c2440_soc.h"
void delay(int i);
int methodRandomName()
{
    /**
     *循环点灯
     */
    /**
     * 设置GPF4、GPF5、GPF6为输出模式,先清空相应位，在初始化对应的位0b01
     */
    GPFCON &= ~(3 << 8) & ~(3 << 10) & ~(3 << 12);
    GPFCON |= (1 << 8) | (1 << 10) | (1 << 12);
    //清空相应数据位为0b000
    //GPFDAT &= ~(7 << 4);
    /**
    GPFDAT &= ~(7 << 4);
    GPFDAT |= (1 << 4);
    */

    int i = 0;
    while(1)
    {
    if(i >= 8)
    {
        i = 0;
    }
    //清空相应数据位为0b000
    GPFDAT &= ~(7 << 4);
    GPFDAT |= (i << 4);
    delay(100000);
    ++i;
    }
}

void delay(int i)
{
    while(i--);
}