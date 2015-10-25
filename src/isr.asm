BITS 32

section .text
	global isr0
	global isr1
	global isr2
	global isr3
	global isr4
	global isr5
	global isr6
	global isr7
	global isr8
	global isr9
	global isr10
	global isr11
	global isr12
	global isr13
	global isr14
	global isr15
	global isr16
	global isr17
	global isr18
	global isr19
	global isr20
	global isr21
	global isr22
	global isr23
	global isr24
	global isr25
	global isr26
	global isr27
	global isr28
	global isr29
	global isr30
	global isr31
	global irq0
	global irq1
	global irq2
	global irq3
	global irq4
	global irq5
	global irq6
	global irq7
	global irq8
	global irq9
	global irq10 
	global irq11
	global irq12 
	global irq13 
	global irq14 
	global irq15
	
	extern isr_handler
	extern irq_handler
	extern SendPicEOI
	
isr0:
	cli
	push byte 0 
	
	push byte 0 
	
	jmp isr_pusher

isr1:
	cli 
	push byte 0 
	
	push byte 1
	
	jmp isr_pusher 
	
isr2:
	cli
	push byte 0 
	
	push byte 2 
	
	jmp isr_pusher 
	
isr3:
	cli 
	push byte 0 
	
	push byte 3 
	
	jmp isr_pusher
isr4:
	cli 
	push byte 0 
	
	push byte 4 

	jmp isr_pusher
isr5:
	cli 
	push byte 0 
	
	push byte 5 
	
	jmp isr_pusher
isr6:
	cli 
	push byte 0 
	
	push byte 6
	
	jmp isr_pusher
isr7:
	cli 
	push byte 0 
	
	push byte 7
	
	jmp isr_pusher
isr8:
	cli
	push byte 8 
	jmp isr_pusher
	
isr9:
	cli 
	push byte 0 
	push byte 9 
	jmp isr_pusher 
	
isr10:
	cli 
	push byte 10 
	jmp isr_pusher 
	
isr11:
	cli 
	push byte 11 
	jmp isr_pusher
	
isr12:
	cli 
	push byte 12 
	jmp isr_pusher 
	
isr13:
	cli 
	push byte 13 
	jmp isr_pusher 
	
isr14:
	cli 
	push byte 14 
	jmp isr_pusher 
	
isr15:
	cli 
	push byte 0 
	push byte 15
	jmp isr_pusher
	
isr16:
	cli
	push byte 0 
	push byte 16 
	jmp isr_pusher 
isr17:
	cli 
	push byte 17 
	jmp isr_pusher 
	
isr18:
	cli 
	push byte 0 
	push byte 18 
	jmp isr_pusher 
isr19:
	cli 
	push byte 0 
	push byte 19 
	jmp isr_pusher 
	
isr20: 
	cli 
	push byte 0 
	push byte 20 
	jmp isr_pusher
	
isr21: 
	cli 
	push byte 0 
	push byte 21
	jmp isr_pusher
	
isr22: 
	cli 
	push byte 0 
	push byte 22
	jmp isr_pusher
	
isr23: 
	cli 
	push byte 0 
	push byte 23
	jmp isr_pusher
	
isr24: 
	cli 
	push byte 0 
	push byte 24
	jmp isr_pusher
	
isr25: 
	cli 
	push byte 0 
	push byte 25
	jmp isr_pusher
	
isr26: 
	cli 
	push byte 0 
	push byte 26
	jmp isr_pusher
	
isr27: 
	cli 
	push byte 0 
	push byte 27
	jmp isr_pusher
	
isr28: 
	cli 
	push byte 0 
	push byte 28
	jmp isr_pusher
	
isr29: 
	cli 
	push byte 0 
	push byte 29
	jmp isr_pusher
	
isr30:
	cli
	push byte 30 
	jmp isr_pusher
	
isr31:
	cli 
	push byte 0 
	push byte 31
	jmp isr_pusher 

irq0:
	cli 
	push byte 0 
	push byte 32 
	jmp irq_pusher
irq1:
	cli
	push byte 0 
	push byte 33 
	jmp irq_pusher
irq2:
	cli 
	push byte 0 
	push byte 34
	jmp irq_pusher 
irq3:
	cli 
	push byte 0 
	push byte 35 
	jmp irq_pusher 
irq4:
	cli 
	push byte 0 
	push byte 36 
	jmp irq_pusher 
irq5:
	cli 
	push byte 0 
	push byte 37 
	jmp irq_pusher 
irq6:
	cli 
	push byte 0 
	push byte 38
	jmp irq_pusher
irq7:
	cli 
	push byte 0 
	push byte 39
	jmp irq_pusher
irq8:
	cli 
	push byte 0 
	push byte 40
	jmp irq_pusher
irq9:
	cli 
	push byte 0 
	push byte 41
	jmp irq_pusher
irq10:
	cli 
	push byte 0 
	push byte 42
	jmp irq_pusher
irq11:
	cli 
	push byte 0 
	push byte 43
	jmp irq_pusher
irq12:
	cli 
	push byte 0 
	push byte 44
	jmp irq_pusher
irq13:
	cli 
	push byte 0 
	push byte 45
	jmp irq_pusher
irq14:
	cli 
	push byte 0 
	push byte 46
	jmp irq_pusher
irq15:
	cli 
	push byte 0 
	push byte 47
	jmp irq_pusher
	

;(ss, fs, gs, es, ds, edi, esi, ebp, esp, ebx, edx, ecx, eax, 33, 0)
isr_pusher:
	pushad
	push ds 
	push es 
	push gs 
	push fs 
	push ss 
	mov ax, 0x10
	mov ds, ax 
	mov es, ax 
	mov ss, ax  
	mov gs, ax 
	mov fs, ax
	cld
	call isr_handler
	pop ss 
	pop fs 
	pop gs 
	pop es 
	pop ds
	popad
	add esp, 8
	sti
	iret
	
irq_pusher:
	pushad
	push ds 
	push es 
	push gs 
	push fs 
	push ss 
	mov ax, 0x10
	mov ds, ax 
	mov es, ax 
	mov ss, ax  
	mov gs, ax 
	mov fs, ax
	cld
	call irq_handler
	pop ss 
	pop fs 
	pop gs 
	pop es 
	pop ds
	popad
	add esp, 8 
	sti
	iret
string db "Omg irq get rek", 0
