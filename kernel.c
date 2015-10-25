#include "include/System.h"
#include <stdint.h>


void kernel_main(void){
	//uintptr_t pointer;
	
	//get_memorymap();
	init_gdt();
	init_idt();
	init_pic();
	
	install_timer();
	install_keyboard();
	
	os_sti();
	for (;;){
		os_halt();
	}
}
