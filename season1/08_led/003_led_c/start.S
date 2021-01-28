/**
led点灯 设置GPF4
*/
.text
.global _start
_start:
	//ldr sp,=4096//nandflash
	//ldr sp,=4096//nandflash
	//ldr sp,=4096//nandflash
	ldr sp,=4096//nandflash
	bl main
halt:
	b halt
