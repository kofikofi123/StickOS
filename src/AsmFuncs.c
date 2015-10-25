#include "../include/AsmFuncs.h"
#include "../include/Terminal.h"

void os_outb(uint16_t port, uint16_t address){
	__asm__("out dx, ax"
			:
			: "a" (address), "d" (port)
			:
	);
	/*
	print_string("(Port: ", White, Blue);
	print_number(port, White, Blue);
	print_string(" Address: ", White, Blue);
	print_number(address, White, Blue);
	print_string(") ", White, Blue);*/
}

uint16_t os_inb(uint16_t port){
	uint16_t data;
	__asm__("in ax, dx\nmov %1, ax"
			: "=r" (data)
			: "d" (port)
	);
	
	return data;
}

void os_halt(void){
	__asm__("hlt");
	return;
}

void os_cli(void){
	__asm__("cli");
	return;
}

void os_sti(void){
	__asm__("sti");
	return;
}

