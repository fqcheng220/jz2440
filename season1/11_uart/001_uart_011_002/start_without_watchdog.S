.text
.global _start
_start:
	/**
	 * 
	 * 并没有关闭看门狗
 	 */
	
	ldr sp,=4096
	/**
	 * 目标：
	 * 设置FCLK始终频率为400MHZ
	 * 寄存器释义:
	 * MPLLCON [19:12]=MDIV [9:4]=PDIV [1:0]=SDIV
	 * MPLL(FCLK) = (2*m*Fin)/(p*2^s) 其中m=MDIV+8,p=PDIV+2,s=SDIV,fin为晶振频率12MHZ 
	 *
	 * 所以可以让MDIV=92,PDIV=1,SDIV=1
	 * MPLLCON地址为0x4C000004
	 * (92<<12 | 1<<4 | 1) 十六进制表示为0x5c011 对应400MHZ
	 * (17<<12 | 1<<4 | 1) 十六进制表示为0x11011 对应100MHZ
	 */
	ldr r0,=0x4C000004
	ldr r1,=0x5c011
	str r1,[r0]
	/**
	 * 目标：
	 * 设置FCLK:HCLK:PCLK 1:4:8 即400MHZ：100MHZ：50MHZ
	 * 寄存器释义:
	 * CLKDIVN [2:1]=HDIVN [0]=PDIVN
	 * CAMDIVN [9]=HCLK4_HALF [8]=HCLK3_HALF
	 *
	 * 要求HDIVN为2，PDIVN为1,HCLK3_HALF/HCLK4_HALF为0/0
	 * CLKDIVN地址为0x4C000014
	 * CAMDIVN地址为0x4C000018
     *
	 */
	ldr r0,=0x4C000014
	ldr r1,=0x5
	str r1,[r0]
	/**
	 * 如果HDIVN不为0,设置cpu总线模式从快速总线模式变为异步总线模式
	 */
	mrc p15,0,r0,c1,c0,0
  	orr r0,r0,#0xc0000000   //R1_nF:OR:R1_iA
	mcr p15,0,r0,c1,c0,0
	/**
	 * 目标：
	 * 设置LOCKTIME时间
	 * 寄存器释义:
	 * 
	 * 
	 * 
	 */
	bl methodRandomName
loop:
	b loop