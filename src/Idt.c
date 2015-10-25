#include "../include/idt.h"
#include "../include/idt_funcs.h"
#include "../include/AsmFuncs.h"
//#include "../include/Terminal.h"
#include "../include/Pic.h"
#include <stdint.h>

irq_handler_t irq_h[16];

static void encode_idt(uint8_t index, uint32_t address, uint8_t selector, uint8_t type);
struct idt_entry entry[256];
struct idt_pointer p_idt;
extern void FlushIDT(void);
void isr_handler(struct interrupts_reg interrupts);
void irq_handler(struct interrupts_reg interrupts);

const char* Execeptions[] = {
	"Divide by 0", // 0
	"Debug",
	"Non-maskable Interrupt",
	"Breakpoint",
	"Overflow", //4
	"BoundRangeExceeded",
	"Invalid Opcode",
	"Device Not Available",
	"Double Fault",
	"Reserved", // 9
	"Invalid TSS",
	"Segment Not Present",
	"Stack-Segment Fault"
	"General Protection Fault",
	"Page Fault",
	"Reserved",
	"x87 Floating-Point Exception",
	"Alignment Check",
	"Machine Check",
	"SIMD Floating-Point Exeception",
	"Virtualization Exception",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Security Exception",
	"Reserved",
	"Triple Fault",
	"Reserved"
};


void init_idt(void){
	encode_idt(ISR_BASE, (unsigned)isr0, 0x08, 0x8F);
	encode_idt(ISR_BASE + 1, (unsigned)isr1, 0x08, 0x8F);
	encode_idt(ISR_BASE + 2, (unsigned)isr2, 0x08, 0x8F);
	encode_idt(ISR_BASE + 3, (unsigned)isr3, 0x08, 0x8F);
	encode_idt(ISR_BASE + 4, (unsigned)isr4, 0x08, 0x8F);
	encode_idt(ISR_BASE + 5, (unsigned)isr5, 0x08, 0x8F);
	encode_idt(ISR_BASE + 6, (unsigned)isr6, 0x08, 0x8F);
	encode_idt(ISR_BASE + 7, (unsigned)isr7, 0x08, 0x8F);
	encode_idt(ISR_BASE + 8, (unsigned)isr8, 0x08, 0x8F);
	encode_idt(ISR_BASE + 9, (unsigned)isr9, 0x08, 0x8F);
	encode_idt(ISR_BASE + 10, (unsigned)isr10, 0x08, 0x8F);
	encode_idt(ISR_BASE + 11, (unsigned)isr11, 0x08, 0x8F);
	encode_idt(ISR_BASE + 12, (unsigned)isr12, 0x08, 0x8F);
	encode_idt(ISR_BASE + 13, (unsigned)isr13, 0x08, 0x8F);
	encode_idt(ISR_BASE + 14, (unsigned)isr14, 0x08, 0x8F);
	encode_idt(ISR_BASE + 15, (unsigned)isr15, 0x08, 0x8F);
	encode_idt(ISR_BASE + 16, (unsigned)isr16, 0x08, 0x8F);
	encode_idt(ISR_BASE + 17, (unsigned)isr17, 0x08, 0x8F);
	encode_idt(ISR_BASE + 18, (unsigned)isr18, 0x08, 0x8F);
	encode_idt(ISR_BASE + 19, (unsigned)isr19, 0x08, 0x8F);
	encode_idt(ISR_BASE + 20, (unsigned)isr20, 0x08, 0x8F);
	encode_idt(ISR_BASE + 21, (unsigned)isr21, 0x08, 0x8F);
	encode_idt(ISR_BASE + 22, (unsigned)isr22, 0x08, 0x8F);
	encode_idt(ISR_BASE + 23, (unsigned)isr23, 0x08, 0x8F);
	encode_idt(ISR_BASE + 24, (unsigned)isr24, 0x08, 0x8F);
	encode_idt(ISR_BASE + 25, (unsigned)isr25, 0x08, 0x8F);
	encode_idt(ISR_BASE + 26, (unsigned)isr26, 0x08, 0x8F);
	encode_idt(ISR_BASE + 27, (unsigned)isr27, 0x08, 0x8F);
	encode_idt(ISR_BASE + 28, (unsigned)isr28, 0x08, 0x8F);
	encode_idt(ISR_BASE + 29, (unsigned)isr29, 0x08, 0x8F);
	encode_idt(ISR_BASE + 30, (unsigned)isr30, 0x08, 0x8F);
	encode_idt(ISR_BASE + 31, (unsigned)isr31, 0x08, 0x8F);
	encode_idt(IRQ_BASE, (unsigned)irq0, 0x08, 0x8F);
	encode_idt(IRQ_BASE + 1, (unsigned)irq1, 0x08, 0x8F);
	encode_idt(IRQ_BASE + 2, (unsigned)irq2, 0x08, 0x8F);
	encode_idt(IRQ_BASE + 3, (unsigned)irq3, 0x08, 0x8F);
	encode_idt(IRQ_BASE + 4, (unsigned)irq4, 0x08, 0x8F);
	encode_idt(IRQ_BASE + 5, (unsigned)irq5, 0x08, 0x8F);
	encode_idt(IRQ_BASE + 6, (unsigned)irq6, 0x08, 0x8F);
	encode_idt(IRQ_BASE + 7, (unsigned)irq7, 0x08, 0x8F);
	encode_idt(IRQ_BASE + 8, (unsigned)irq8, 0x08, 0x8F);
	encode_idt(IRQ_BASE + 9, (unsigned)irq9, 0x08, 0x8F);
	encode_idt(IRQ_BASE + 10, (unsigned)irq10, 0x08, 0x8F);
	encode_idt(IRQ_BASE + 11, (unsigned)irq11, 0x08, 0x8F);
	encode_idt(IRQ_BASE + 12, (unsigned)irq12, 0x08, 0x8F);
	encode_idt(IRQ_BASE + 13, (unsigned)irq13, 0x08, 0x8F);
	encode_idt(IRQ_BASE + 14, (unsigned)irq14, 0x08, 0x8F);
	encode_idt(IRQ_BASE + 15, (unsigned)irq15, 0x08, 0x8F);
	
	p_idt.limit = (sizeof(struct idt_entry) * 256) - 1;
	p_idt.base = (uint32_t)&entry[0];

	FlushIDT();
	
	return;
}

static void encode_idt(uint8_t index, uint32_t address, uint8_t selector, uint8_t type){
	entry[index].offset_low = (address & 0xFFFF);
	entry[index].selector = selector;
	entry[index].zero = 0;
	entry[index].type = type;
	entry[index].offset_high = ((address >> 16) & 0xFFFF);
	
	return;
}

void isr_handler(struct interrupts_reg interrupts){
	
	if (interrupts.int_n == 8){
		os_halt();
		os_cli();
	}
	os_halt();
	os_cli();
}

void irq_handler(struct interrupts_reg interrupts){
	
	uint8_t interrupt = interrupts.int_n - 32;
	//spurious interrupts
	if ((GetISR() & interrupt) != interrupt){
		return;
	}
	irq_handler_t handler = irq_h[interrupt];
	
	if (handler){
		handler();
	}
	SendPicEOI(interrupt);
	return;
}
void install_irq(uint8_t index, irq_handler_t handler){
	irq_h[index] = handler;
}

void remove_irq(uint8_t index){
	irq_h[index] = 0;
}
