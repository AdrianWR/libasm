# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strdup.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroque </var/spool/mail/aroque>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/02 20:02:16 by aroque            #+#    #+#              #
#    Updated: 2020/11/02 20:02:20 by aroque           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

extern	malloc
extern	ft_strlen
extern	ft_strcpy

global	ft_strdup

section	.text

ft_strdup:
	xor		rax, rax

mem_alloc:
	call	ft_strlen	; ft_strlen(rdi)
	push	rdi			; save input address on stack
	mov		rdi, rax	; copy result of ft_strlen to counter
	inc		rdi			; increment counter (\0 allocation)
	call	malloc		; malloc(rdi)
	pop		rdi			; remove input addres from stack
	cmp		rax, 0x0	; protect malloc
	jne		copy
	ret

copy:
	mov		rsi, rdi	; copy destination to source
	mov 	rdi, rax	; copy malloc return address to rdi
	call	ft_strcpy	; ft_strcpy(rdi, rsi)
	ret
