#
# bzero_32.s
# Attempt to optimize the function bzero
# by Joao Guilherme aka "pl4nkt0n"
#
# jgvictorino1 [at] gmail [dot] com

.section .text

.global bzero_longbuffer

.type bzero_longbuffer, @function

bzero_longbuffer:
	xor	%eax, %eax

	mov	8(%ebp), %ecx
	and	$0xfffffffc, %ecx
	sub	%ecx, 8(%ebp)		# 8(%ebp) = (len % 8)
	shr	$2, %ecx		# %ecx = (len - (8(%ebp))) / 8

	repnz	stosl

	mov	8(%ebp), %ecx
	repnz	stosb

	ret

