#ifndef _SYSTEM_H
#define _SYSTEM_H 

#define OS_NAME "MyStickOS"
#define OS_VERSION 0.12


#include <stdint.h>

#include "Terminal.h" 
#include "Gdt.h"
#include "Idt.h"
#include "Pic.h"
#include "AsmFuncs.h"
#include "Timer.h"
#include "Memory.h"

//From asm 
extern void   os_io_wait(void);
extern void   int0test(void);
extern void   FlushGDT(gdt_pointer* pointer);
extern void   FlushIDT(void);

//From Terminal.h

//From Memory.h
extern void   init_page_tables(void);
extern void*  alloc_page_table(void);
extern void   delete_page(void* page);
extern void*  kmalloc(uint32_t size);
//from Gdt.h
extern void init_gdt(void);

//from Idt.h 
extern void init_idt(void);
extern void install_irq(uint8_t index, irq_handler_t handler);
extern void remove_irq(uint8_t index);

//From Pic.h
extern void init_pic();
extern void SendPicEOI(uint8_t irq);
extern uint16_t GetIRR(void);
extern uint16_t GetISR(void);

//From Keyboard.h
extern void Keyboard_handler(void);
extern void install_keyboard(void);

//From Timer.h
extern void timer_handler(void);
extern void install_timer(void);

//From memtools.h
extern void memset(void* buffer, uint8_t value, uint32_t size);
extern void memcpy(void* buffer, const void* buffer2, uint32_t size);
extern void memmove(void* buffer, void* buffer2, uint32_t size);

#endif
