#define GPFCON *((unsigned int*)0x56000050)
#define GPFDAT *((unsigned int*)0x56000054)

void delay(int i){
while(i--);
}

void led_on(int ledIndex){
	unsigned int* pGPFCON = (unsigned int*)0x56000050;
	unsigned int* pGPFDAT = (unsigned int*)0x56000054;
	switch (ledIndex)
	{
	case 4:
		*pGPFCON = 0xFDFF;
		*pGPFDAT = 0xEF;
		break;
	case 5:
		*pGPFCON = 0xF7FF;
		*pGPFDAT = 0xDF;
		break;
	}
}
