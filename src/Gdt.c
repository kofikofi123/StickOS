#include <stdint.h>
#include "../include/Terminal.h" 
#include "../include/Gdt.h"


gdt new_gdt;

extern void FlushGDT(gdt_pointer* pointer);
static void EncodeGDT(uint8_t offset, uint32_t base, uint32_t limit, uint8_t access, uint8_t flag); 

void init_gdt(void){
	EncodeGDT(0, 0, 0, 0, 0); //null descriptor
	EncodeGDT(1, 0, 0xFFFFF, 0x9A, 0xC0);//kernel code descriptor 
	EncodeGDT(2, 0, 0xFFFFF, 0x92, 0xC0);//kernel data descriptor
	EncodeGDT(3, 0, 0xFFFFF, 0x92, 0xC0);//kernel stack descriptor (will change)
	//EncodeGDT(4, 0xC0000, 0xFFFF, 0xFA, 0xC0);//userspace code descriptor 
	//EncodeGDT(5, 0xC0000, 0xFFFF, 0xF2, 0xC0);//userspace data descriptor
	//EncodeGDT(6, 0xC0000, 0xFFFF, 0xF2, 0xC0);//userspace stack descriptor (will change)
	
	new_gdt.pointer.size = (sizeof(gdt_entry) * 4) - 1;
	new_gdt.pointer.offset = (uint32_t)(&new_gdt.entry[0]);

	FlushGDT(&new_gdt.pointer);
	
	return;
}

static void EncodeGDT(uint8_t offset, uint32_t base, uint32_t limit, uint8_t access, uint8_t flag){
	//if (!entry) return;
	
	new_gdt.entry[offset].limit_low = (limit & 0xFFFF);
	new_gdt.entry[offset].base_low = (base & 0xFFFF);
	new_gdt.entry[offset].base_middle = ((base >> 16) & 0xFF);
	new_gdt.entry[offset].access = access;
	new_gdt.entry[offset].flags = flag | ((limit >> 16) & 0xF);
	new_gdt.entry[offset].base_high = ((base >> 24) & 0xFF);
	
}
