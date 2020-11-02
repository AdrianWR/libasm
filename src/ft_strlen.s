# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strlen.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/02 19:58:11 by aroque            #+#    #+#              #
#    Updated: 2020/11/02 19:58:44 by aroque           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

; first argument:	rdi
; second argument:	rsi
; third argument:	rdx
; fourth argument:	rcx
; fifth argument:	r8
; sixth argument:	r9

global		ft_strlen

section		.text

ft_strlen:
			mov		rax, rdi

comparison:
			cmp		byte [rax], 0
			je		finish
			inc		rax
			jne		comparison

finish:
			sub		rax, rdi
			ret
