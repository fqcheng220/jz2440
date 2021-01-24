#define GPF4CON *((unsigned int*)0x56000050)
#define GPF4DAT *((unsigned int*)0x56000054)

int main(){
	/**
	*失败代码 原因可能是没有读权限
	*/
	/**
	GPF4CON  &= 0xFDFF;
	GPF4DAT  &= 0xEF;
	*/
	/**
	*成功代码
	*/
	/**
	GPF4CON  = 0xFDFF;
	GPF4DAT  = 0xEF;
	*/
	/**
	*成功代码
	*因为有局部变量，需要用到sp堆栈指针寄存器
	*/
	unsigned int* pGPF4CON = (unsigned int*)0x56000050;
	unsigned int* pGPF4DAT = (unsigned int*)0x56000054;
	*pGPF4CON = 0xFDFF;
	*pGPF4DAT = 0xEF;
	/**
	*成功代码
	*/
	/**
	*((unsigned int*)0x56000050)  = 0x100;
	*((unsigned int*)0x56000054)  = 0;
	*/
	return 0;
}