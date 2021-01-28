/**
*led
*D10->n_LED_1->GPF4
*D11->n_LED_2->GPF5
*D12->n_LED_4->GPF6
*开关
*S2->EINT0->GPF0
*S3->EINT2->GPF2
*S4->EINT11->GPG3
*/
#define GPFCON *((unsigned int*)0x56000050)
#define GPFDAT *((unsigned int*)0x56000054)
#define GPGCON *((unsigned int*)0x56000060)
#define GPGDAT *((unsigned int*)0x56000064)

void delay(int d)
{
	while (d--);
}

int main(){

	unsigned int* pGPFCON = (unsigned int*)0x56000050;
	unsigned int* pGPFDAT = (unsigned int*)0x56000054;
	unsigned int* pGPGCON = (unsigned int*)0x56000060;
	unsigned int* pGPGDAT = (unsigned int*)0x56000064;
	
	
	
	/**
	*设置s2、s3、s4为输入模式 设为0b00
	*/
	/**
	*分别对s2 s3先清空对应的两位 保留其余位
	*/
	*pGPFCON &= (~(3<<0) & ~(3<<4));
	/**
	*分别对s2 s3对应的两位赋值0b00
	*/
	*pGPFCON |= ((0<<0) | (0<<4));
	
	/**
	*对s4先清空对应的两位 保留其余位
	*/
	*pGPGCON &= ~(3<<6);
	/**
	*对s4对应的两位赋值0b00
	*/
	*pGPGCON |= (0<<6);
	
	/**
	*设置D10、D11、D12为输出模式 设为0b01
	*/
	/**
	*分别对GPF4 GPF5 GPF6先清空对应的两位 保留其余位
	*/
	*pGPFCON &= (~(3<<8) & ~(3<<10) & ~(3<<12));
	/**
	*分别对GPF4 GPF5 GPF6对应的两位赋值0b01
	*/
	*pGPFCON |= ((1<<8) | (1<<10) | (1<<12));//之前误把1<<8写成了1<<4
	//按键点灯 
	//s2<->D12 s3<->D11 s4<->D10
	//GPF0<->GPF6 GPF2<->GPF5 GPG3<->GPF4

	//亮所有灯
	/**
	*pGPFDAT &= ~(1<<6);
	*pGPFDAT &= ~(1<<5);
	*pGPFDAT &= ~(1<<4);
	*/
	//D12、D10亮，D11灭
	/**
	*pGPFDAT &= ~(1<<6);
	*pGPFDAT |= (1<<5);
	*pGPFDAT &= ~(1<<4);
	*/
	//D12、D10灭，D11亮
	/**
	*pGPFDAT |= (1<<6);
	*pGPFDAT &= ~(1<<5);
	*pGPFDAT |= (1<<4);
	*/
	while(1){
		/**
		*正确代码 按下s2 d12灯亮
		*/
		/**
		if(*pGPFDAT & (1<<0)){
			//*pGPFDAT &= ~(1<<6);
			*pGPFDAT |= (1<<6);
		}else{
			//按下s2 低电平0
			*pGPFDAT &= ~(1<<6);
			//*pGPFDAT |= (0<<6);
		}
		*/
		/**
		*错误代码 按下s2 d12灯亮
		*/
		if((*pGPFDAT & (1<<0)) == 0){//一直无法得到执行 原因？？？？？？之前代码是if(*pGPFDAT & (1<<0) == 0) 错误的原因是&优先级要低于==  结合律使用在多个运算符优先级相等的情况下
			//按下s2 低电平0
			*pGPFDAT &= ~(1<<6);
			//*pGPFDAT |= (0<<6);
		}else{
			//*pGPFDAT &= ~(1<<6);
			*pGPFDAT |= (1<<6);
		}
		/**
		if(*pGPFDAT & (1<<2)){
			//*pGPFDAT &= ~(1<<5);
			*pGPFDAT |= (1<<5);
		}else{
			//按下s3 低电平0
			*pGPFDAT &= ~(1<<5);
			//*pGPFDAT |= (0<<5);
		}
		if(*pGPGDAT & (1<<3)){
			//*pGPFDAT &= ~(1<<4);
			*pGPFDAT |= (1<<4);
		}else{
			//按下s4 低电平0
			*pGPFDAT &= ~(1<<4);
			//*pGPFDAT |= (0<<4);
		}*/
		if((*pGPFDAT & (1<<2)) == 0){
			//按下s3 低电平0
			*pGPFDAT &= ~(1<<5);
			//*pGPFDAT |= (0<<5);
		}else{
			//*pGPFDAT &= ~(1<<5);
			*pGPFDAT |= (1<<5);
		}
		if((*pGPGDAT & (1<<3)) == 0){
			//按下s4 低电平0
			*pGPFDAT &= ~(1<<4);
			//*pGPFDAT |= (0<<4);
		}else{
			//*pGPFDAT &= ~(1<<4);
			*pGPFDAT |= (1<<4);
		}
	}
	
	return 0;

}


int mainV5(){

	unsigned int* pGPFCON = (unsigned int*)0x56000050;
	unsigned int* pGPFDAT = (unsigned int*)0x56000054;
	unsigned int* pGPGCON = (unsigned int*)0x56000060;
	unsigned int* pGPGDAT = (unsigned int*)0x56000064;
	
	
	
	/**
	*设置s2、s3、s4为输入模式 设为0b00
	*/
	/**
	*分别对s2 s3先清空对应的两位 保留其余位
	*/
	*pGPFCON &= (~(3<<0) & ~(3<<4));
	/**
	*分别对s2 s3对应的两位赋值0b00
	*/
	*pGPFCON |= ((0<<0) | (0<<4));
	
	/**
	*对s4先清空对应的两位 保留其余位
	*/
	*pGPGCON &= ~(3<<6);
	/**
	*对s4对应的两位赋值0b00
	*/
	*pGPGCON |= (0<<6);
	
	/**
	*设置D10、D11、D12为输出模式 设为0b01
	*/
	/**
	*分别对GPF4 GPF5 GPF6先清空对应的两位 保留其余位
	*/
	*pGPFCON &= (~(3<<8) & ~(3<<10) & ~(3<<12));
	/**
	*分别对GPF4 GPF5 GPF6对应的两位赋值0b01
	*/
	*pGPFCON |= ((1<<8) | (1<<10) | (1<<12));//之前误把1<<8写成了1<<4
	//按键点灯 
	//s2<->D12 s3<->D11 s4<->D10
	//GPF0<->GPF6 GPF2<->GPF5 GPG3<->GPF4

	while(1){
		if(*pGPFDAT & (1<<0) == 0){
			//按下s2 低电平0
			*pGPFDAT &= ~(1<<6);
			//*pGPFDAT |= (0<<6);
		}else{
			//*pGPFDAT &= ~(1<<6);
			*pGPFDAT |= (1<<6);
		}
		if(*pGPFDAT & (1<<2) == 0){
			//按下s3 低电平0
			*pGPFDAT &= ~(1<<5);
			//*pGPFDAT |= (0<<5);
		}else{
			//*pGPFDAT &= ~(1<<5);
			*pGPFDAT |= (1<<5);
		}
		if(*pGPGDAT & (1<<3) == 0){
			//按下s4 低电平0
			*pGPFDAT &= ~(1<<4);
			//*pGPFDAT |= (0<<4);
		}else{
			//*pGPFDAT &= ~(1<<4);
			*pGPFDAT |= (1<<4);
		}
	}
	
	//*pGPFDAT = 0xff;
	return 0;

}

int mainV4(){
	unsigned int* pGPFCON = (unsigned int*)0x56000050;
	unsigned int* pGPFDAT = (unsigned int*)0x56000054;
	unsigned int* pGPGCON = (unsigned int*)0x56000060;
	unsigned int* pGPGDAT = (unsigned int*)0x56000064;
	
	
	
	/**
	*设置s2、s3、s4为输入模式 设为0b00
	*/
	/**
	*分别对s2 s3先清空对应的两位 保留其余位
	*/
	*pGPFCON &= (~(3<<0) & ~(3<<4));
	/**
	*分别对s2 s3对应的两位赋值0b00
	*/
	*pGPFCON |= ((0<<0) | (0<<4));
	
	/**
	*对s4先清空对应的两位 保留其余位
	*/
	*pGPGCON &= ~(3<<6);
	/**
	*对s4对应的两位赋值0b00
	*/
	*pGPGCON |= (0<<6);
	
	/**
	*设置D10、D11、D12为输出模式 设为0b01
	*/
	/**
	*分别对GPF4 GPF5 GPF6先清空对应的两位 保留其余位
	*/
	*pGPFCON &= (~(3<<8) & ~(3<<10) & ~(3<<12));
	/**
	*分别对GPF4 GPF5 GPF6对应的两位赋值0b01
	*/
	*pGPFCON |= ((1<<8) | (1<<10) | (1<<12));//之前误把1<<8写成了1<<4
	//按键点灯 
	//s2<->D12 s3<->D11 s4<->D10
	//GPF0<->GPF6 GPF2<->GPF5 GPG3<->GPF4
	
	while(1){
		if(*pGPFDAT & (1<<0) == 0){
			//按下s2 低电平0
			*pGPFDAT &= ~(1<<6);
			*pGPFDAT |= (0<<6);
		}else{
			*pGPFDAT &= ~(1<<6);
			*pGPFDAT |= (1<<6);
		}
	}

	return 0;

}

int mainV3()
{
unsigned int* pGPFCON = (unsigned int*)0x56000050;
unsigned int* pGPFDAT = (unsigned int*)0x56000054;
unsigned int* pGPGCON = (unsigned int*)0x56000060;
unsigned int* pGPGDAT = (unsigned int*)0x56000064;



/**
*设置s2、s3、s4为输入模式 设为0b00
*/
/**
*分别对s2 s3先清空对应的两位 保留其余位
*/
*pGPFCON &= ~(3<<0) & ~(3<<4);
/**
*分别对s2 s3对应的两位赋值0b00
*/
*pGPFCON |= (0<<0) | (0<<4);

/**
*对s4先清空对应的两位 保留其余位
*/
*pGPGCON &= ~(3<<6);
/**
*对s4对应的两位赋值0b00
*/
*pGPGCON |= (0<<6);

/**
*设置D10、D11、D12为输出模式 设为0b01
*/
/**
*分别对GPF4 GPF5 GPF6先清空对应的两位 保留其余位
*/
*pGPFCON &= ~(3<<8) & ~(3<<10) & ~(3<<12);
/**
*分别对GPF4 GPF5 GPF6对应的两位赋值0b01
*/
*pGPFCON |= (1<<4) | (1<<10) | (1<<12);

int index = 0;
//按键点灯 
//s2<->D12 s3<->D11 s4<->D10
//GPF0<->GPF6 GPF2<->GPF5 GPG3<->GPF4
/**
while(1){
	if(*pGPFDAT & (1<<0) == 0){
		//按下s2 低电平0
		*pGPFDAT &= ~(1<<6);
		*pGPFDAT |= (1<<6);
	}else{
		*pGPFDAT &= ~(1<<6);
		*pGPFDAT |= (0<<6);
	}
}
*/
return 0;
}

int mainV2()
{
/**
*设置s2、s3、s4为输入模式 设为0b00
*/
/**
*分别对s2 s3先清空对应的两位 保留其余位
*/
GPFCON &= ~(3<<0) & ~(3<<4);
/**
*分别对s2 s3对应的两位赋值0b00
*/
GPFCON |= (0<<0) | (0<<4);

/**
*对s4先清空对应的两位 保留其余位
*/
GPGCON &= ~(3<<6);
/**
*对s4对应的两位赋值0b00
*/
GPGCON |= (0<<6);

/**
*设置D10、D11、D12为输出模式 设为0b01
*/
/**
*分别对GPF4 GPF5 GPF6先清空对应的两位 保留其余位
*/
GPFCON &= ~(3<<8) & ~(3<<10) & ~(3<<12);
/**
*分别对GPF4 GPF5 GPF6对应的两位赋值0b01
*/
GPFCON |= (1<<4) | (1<<10) | (1<<12);

int index = 0;
//按键点灯 
//s2<->D12 s3<->D11 s4<->D10
//GPF0<->GPF6 GPF2<->GPF5 GPG3<->GPF4
while(1){
	if(GPFDAT & (1<<0) == 0){
		//按下s2 低电平0
		GPFDAT &= ~(1<<6);
		GPFDAT |= (1<<6);
	}else{
		GPFDAT &= ~(1<<6);
		GPFDAT |= (0<<6);
	}
	//delay(100000);
}
return 0;
}





