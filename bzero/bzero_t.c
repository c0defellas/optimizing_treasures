/* 
 * bzero_t.c - test bzero functions
 * Joao Guilherme aka "pl4nkt0n"
 * jgvictorino1 [at] gmail [dot] com
 * 
 */

#include <stdio.h>
#include <string.h>
#include <x86intrin.h>

#define SSIZE	107
#define LSIZE	1000007

extern void bzero_longbuffer(void *, size_t len);

static void (*cf_bzero)(void *, size_t len) = bzero_longbuffer;


int main(void){
	char buf1[SSIZE];
	char buf2[LSIZE];
	
	register long long c;

	//test short buffer
	printf("Buffer size is: %d\n", SSIZE);
	c = _rdtsc();
	bzero(buf1, SSIZE);
	c = _rdtsc() - c;
	printf("bzero (libc):        %lld cicles\n", c);
	
	c = _rdtsc();
	cf_bzero(buf1, SSIZE);
	c = _rdtsc() - c;
	printf("bzero (c0defellas):  %lld cicles\n", c);
	
	puts("");
	
	//test long buffer
	printf("Buffer size is: %d\n", LSIZE);
	c = _rdtsc();
	bzero(buf2, LSIZE);
	c = _rdtsc() - c;
	printf("bzero (libc):        %lld cicles\n", c);
	
	c = _rdtsc();
	cf_bzero(buf2, LSIZE);
	c = _rdtsc() - c;
	printf("bzero (c0defellas):  %lld cicles\n", c);
	
	return 0;
}