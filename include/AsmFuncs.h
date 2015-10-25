#ifndef _ASMFUNC_H
#define _ASMFUNC_H

#include <stdint.h>
extern void os_cli(void);
extern void os_sti(void);
extern void os_halt(void);
extern void os_outb(uint16_t port, uint16_t data);
extern uint16_t os_inb(uint16_t port);
extern void os_io_wait(void);
#endif