#ifndef _IDT_H
#define _IDT_H

#define ISR_BASE 0 
#define IRQ_BASE 32

#include <stdint.h>


struct idt_entry {
	uint16_t offset_low;
	uint16_t selector;
	uint8_t zero;
	uint8_t type;
	uint16_t offset_high;
}__attribute__((packed));

struct idt_pointer {
	uint16_t limit;
	uint32_t base;
}__attribute__((packed));

struct interrupts_reg {
	uint16_t ss, fs, gs, es, ds;
	uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;
	uint8_t int_n, error_code;
	uint32_t eip, cs, eflags, useresp, userss;
}__attribute__((packed));

typedef void(*irq_handler_t)(void);





void remove_irq(uint8_t index);
void install_irq(uint8_t index, irq_handler_t handler);
void init_idt(void);


#endif
