#include <stdint.h>
#include "../include/Keyboard.h"
#include "../include/Memtools.h"
#include "../include/AsmFuncs.h"
#include "../include/Idt.h"

void Keyboard_event(void){
	*(volatile char*)0xFFFF = 0xFA;
	return;
}

void install_keyboard(void){
	install_irq(0x21, Keyboard_event);
	return;
}
