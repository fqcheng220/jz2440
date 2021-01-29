#include "uart.h"

int methodRandomName(){
	uart_init();
	uart_putchars("helloworld\n");
	return 0;
}