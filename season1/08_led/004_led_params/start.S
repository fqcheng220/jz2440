/**
led点灯 先点灯GPF4 延时后 再点灯GPF5
*/
.text
.global _start
_start:
	ldr sp,=4096//nandflash
	ldr r0,=4
	bl led_on

	ldr r0,=100000
	bl delay

	ldr r0,=5
	bl led_on
	
halt:
	b halt
