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
	and	$0xfffffffffffffffc, %rcx
	sub	%rcx, %rsi			# %rsi = (len % 4)
	shr	$2, %rcx			# %rcx = (len - %rsi) / 4

	repnz	stosl

	mov	%rsi, %rcx
	repnz	stosb

	ret
