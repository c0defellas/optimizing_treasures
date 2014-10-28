#
# bzero_32.s
# Trying to optimize the function bzero - this seems better to long buffers
# by Joao Guilherme aka "pl4nkt0n"
#
# jgvictorino1 [at] gmail [dot] com

.section .text

.global my_bzero

.type my_bzero, @function

my_bzero:
	push	%ebp
	mov	%esp, %ebp
	xor	%eax, %eax
	
	mov	8(%ebp), %edi
	mov	12(%ebp), %edx
	
	mov	%edx, %ecx
	and	$0xfffffffc, %ecx
	sub	%ecx, %edx		# %edx = (len % 4)
	shr	$2, %ecx		# %ecx = (len - %edx) / 4

	repnz	stosl

	mov	%edx, %ecx
	repnz	stosb

	mov	%ebp, %esp
	pop	%ebp
	ret
