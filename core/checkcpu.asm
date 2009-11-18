; ==============================================================
;               SPRAWDZAMY CPU CZY NIE GORSZY NIZ 386
; ==============================================================
CheckCPU:
	push	si
	push	eax
	push	ebx
	
	mov	si,0
	call	print
	mov	si,m_cpu
	call	print

	pushf
	pushf
	pop bx				; stare flagi do BX
	mov ax,bx
	xor ah,70h			; proba zmiany bitu 14 (NT)...
	push ax				; ...lub b13:b12 (IOPL)
	popf
	pushf
	pop ax				; nowe FLAGS w AX
	popf
	xor ah,bh			; jesli zmieniono b14 lub b13:b12 mamy 32Bit CPU
	and ah,70h
	jne	.ok
	mov	ax,ERR_NO386
	call	Error
.ok	
	pop	ebx
	pop	eax
	pop	si
	ret
