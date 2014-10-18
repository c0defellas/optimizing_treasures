#
# bzero_32.s
# Attempting optimizing bzero function
# by Joao Guilherme aka "pl4nkt0n"
#
# jgvictorino1 [at] gmail [dot] com

.section .text

.global bzero_longbuffer

.type bzero_longbuffer, @function

bzero_longbuffer:
	xor	%eax, %eax
	
	mov	8(%ebp), %ecx
	and	$0xfffffffb, %ecx
	sub	%ecx, 8(%ebp)		# 8(%ebp) = (len % 8)
	shr	$2, %ecx		# %ecx = (len - (8(%ebp))) / 8
	
	repnz	stosw
	
	mov	8(%ebp), %ecx
	repnz	stosb
	
	ret
	