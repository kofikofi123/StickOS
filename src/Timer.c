#include "../include/Timer.h"
#include "../include/Idt.h"
void timer_handler(void){
  return;
}

void install_timer(void){
  install_irq(0x20, timer_handler);
}
