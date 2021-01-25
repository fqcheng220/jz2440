/**
led点灯 开关控制led
*/
.text
.global _start
_start:
	//关闭看门狗
	ldr r0,=0x53000000
	ldr r1,=0
	str r1,[r0]
	
	ldr sp,=4096//nandflash
	bl main
halt:
	b halt
