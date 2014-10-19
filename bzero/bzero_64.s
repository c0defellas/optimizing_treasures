#
# bzero_64.s
# Attempt to optimize the function bzero
# by Joao Guilherme aka "pl4nkt0n"
#
# jgvictorino1 [at] gmail [dot] com

.section .text

.global bzero_longbuffer

.type bzero_longbuffer, @function

bzero_longbuffer:
	xor	%rax, %rax

	mov	%rsi, %rcx
	and	$0xfffffffffffffffb, %rcx
	sub	%rcx, %rsi			# %rsi = (len % 8)
	shr	$2, %rcx			# %rcx = (len - %rsi) / 8

	repnz	stosw

	mov	%rsi, %rcx
	repnz	stosb

	ret
