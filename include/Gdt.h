#ifndef _GDT_H
#define _GDT_H

#include <stdint.h>


typedef struct {
	uint16_t limit_low;
	uint16_t base_low;
	uint8_t base_middle;
	uint8_t access;
	uint8_t flags;
	uint8_t base_high;
}__attribute__((packed)) gdt_entry;

typedef struct {
	uint16_t size;
	uint32_t offset;
}__attribute__((packed)) gdt_pointer;

typedef struct {
	gdt_entry entry[7];
	gdt_pointer pointer;
}__attribute__((packed)) gdt;


void init_gdt(void);

#endif