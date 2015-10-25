#include <stdint.h>
#include "../include/Pic.h"
#include "../include/AsmFuncs.h"
#include "../include/Terminal.h"

static void Pic_remap(uint8_t offset, uint8_t offset2);

void init_pic(){
	Pic_remap(0x20, 0x28);
	os_outb(PIC1_DATA, 0xFF);
	os_outb(PIC2_DATA, 0xFF);
	
	
	return;
}



static void Pic_remap(uint8_t offset, uint8_t offset2){
	
	os_outb(PIC1_COMMAND, 0x11);
	os_io_wait();
	os_outb(PIC2_COMMAND, 0x11);
	os_io_wait();
	os_outb(PIC1_DATA, offset);
	os_io_wait();
	os_outb(PIC2_DATA, offset2);
	os_io_wait();
	os_outb(PIC1_DATA, 4);
	os_io_wait();
	os_outb(PIC2_DATA, 2);
	os_io_wait();
	os_outb(PIC1_DATA, 1);
	os_io_wait();
	os_outb(PIC2_DATA, 1);
	return;
}

void SendPicEOI(uint8_t irq){
	if (irq > 7){
		os_outb(PIC2_COMMAND, PIC_EOI);
	}
	
	os_outb(PIC1_COMMAND, PIC_EOI);
	
	return;
}

uint16_t GetIRR(void){
	os_outb(PIC1_COMMAND, PIC_IRR);
	os_outb(PIC2_COMMAND, PIC_IRR);
	
	return ((os_inb(PIC1_COMMAND) << 8) | os_inb(PIC2_COMMAND));
} 

uint16_t GetISR(void){
	os_outb(PIC1_COMMAND, PIC_ISR);
	os_outb(PIC2_COMMAND, PIC_ISR);
	
	return ((os_inb(PIC1_COMMAND) << 8) | os_inb(PIC2_COMMAND));
}