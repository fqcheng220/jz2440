/**
led点灯 设置GPF4
*/
.text
.global _start

_start:
/**
配置GPF4为输出引脚 
GPFCON 0x56000050 0xFDFF
*/

ldr r1,=0x56000050
ldr r2,=0xFDFF
#ldr r2,=0x100
str r2,[r1]

/**
配置GPF4为输出高电平 
GPFDAT 0x56000054 0xEF
*/
ldr r1,=0x56000054
ldr r2,=0xEF
#ldr r2,=0x00
str r2,[r1]

/**
配置GPF5为输出引脚 
GPFCON 0x56000050 0xF7FF
*/

ldr r1,=0x56000050
ldr r2,=0xF7FF
str r2,[r1]

/**
配置GPF5为输出高电平 
GPFDAT 0x56000054 0xDF
*/
ldr r1,=0x56000054
ldr r2,=0xDF
str r2,[r1]

halt:
	b halt

