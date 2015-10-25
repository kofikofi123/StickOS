#ifndef _PIC_H
#define _PIC_H 

#define PIC1_COMMAND 0x20 
#define PIC1_DATA 0x21 
#define PIC2_COMMAND 0xA0 
#define PIC2_DATA 0xA1 
#define PIC_IRR 0x0A 
#define PIC_ISR 0x0B
#define PIC_EOI 0x20

#include <stdint.h>
//void Pic_remap(uint8_t offset, uint8_t offset2);
void init_pic();
void SendPicEOI(uint8_t irq);
uint16_t GetIRR(void);
uint16_t GetISR(void);


#endif