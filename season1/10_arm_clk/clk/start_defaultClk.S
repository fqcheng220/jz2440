/**
 * 使用没有调整过FCLK HCLK PCLK的启动代码，发现点灯闪烁频率很低，因为默认的晶振频率就很低
 */
.text
.global _start
_start:
	/**
	 * 
	 * 并没有关闭看门狗
 	 */
	ldr sp,=4096
	bl methodRandomName
loop:
	b loop