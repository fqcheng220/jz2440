#include "uart.h"

int methodRandomName(){
	uart_init();
	uart_putchars("helloworld\n");
	// uart_putchars("h");
	char tmp;
	while(1){
		tmp = uart_getchar();
		//支持换行
		if(tmp == '\r'){
			uart_putchar('\n');
		}
		uart_putchar(tmp);
		
	}
	return 0;
}