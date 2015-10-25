#ifndef _MEMORY_H
#define _MEMORY_H

#include <stdint.h>

void  init_page_tables(void);

void* alloc_page_table(void);
void  delete_page(void* page);

void* kmalloc(uint32_t size);
void  kfree(void* p);

#endif
