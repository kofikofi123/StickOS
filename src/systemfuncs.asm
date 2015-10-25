BITS 32


section .text
	global FlushGDT
	global os_io_wait
	global FlushIDT

	extern p_idt
	;print_number(number, White, Blue)
	
os_io_wait:
	jmp .j1 
.j1:
	jmp .j2 
.j2:
	ret

FlushGDT:
	push ebp
	mov ebp, esp
	push eax 
	
	mov eax, [ebp + 8]
	
	lgdt [eax]
	
	jmp 0x08:.flush
.flush:
	mov ax, 0x10 
	mov ds, ax 
	mov ss, ax 
	mov gs, ax 
	mov es, ax 
	mov fs, ax
	mov esp, 0x90000
	jmp .done 
.done:
	pop eax 
	mov esp, ebp 
	pop ebp 
	ret
	
FlushIDT:
	lidt [p_idt]
	ret 
	
	
;string db "This is a string from int0", 0
;space db " ", 0
