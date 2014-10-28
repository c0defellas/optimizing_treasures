#
# bzero_64.s
# Trying to optimize the function bzero - this seems better to long buffers
# by Joao Guilherme aka "pl4nkt0n"
#
# jgvictorino1 [at] gmail [dot] com

.section .text

.global my_bzero

.type my_bzero, @function

my_bzero:
	xor	%rax, %rax

	mov	%rsi, %rcx
	and	$0xfffffffffffffffc, %rcx
	sub	%rcx, %rsi			# %rsi = (len % 4)
	shr	$2, %rcx			# %rcx = (len - %rsi) / 4

	repnz	stosl

	mov	%rsi, %rcx
	repnz	stosb

	ret
