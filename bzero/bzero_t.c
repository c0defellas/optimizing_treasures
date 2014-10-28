/*
 * bzero_t.c - test bzero functions
 * Joao Guilherme aka "pl4nkt0n"
 * jgvictorino1 [at] gmail [dot] com
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <x86intrin.h>

#define SHORTBUF	107
#define LONGBUF		1000007
#define NSAMPLES	1000

extern void my_bzero(void *s, size_t n);

int main(void){
	/* stack buffers */
	char sbuf1[SHORTBUF];
	char sbuf2[LONGBUF];
	
	/* heap buffers */
	char *hbuf1 = NULL;
	char *hbuf2 = NULL;

	uint64_t cycles;
	int i;

	hbuf1 = (char *)malloc(SHORTBUF);
	hbuf2 = (char *)malloc(LONGBUF);

	if((!hbuf1) || (!hbuf2)){
		fprintf(stderr, "malloc failed\n");
		exit(EXIT_FAILURE);
	}
	
	//just for load libc addr
	bzero(sbuf1, SHORTBUF);
	
	/* ------ test short buffers ------ */
	cycles = _rdtsc();
	for(i = NSAMPLES; i > 0; i--){
		bzero(sbuf1, SHORTBUF);
	}
	cycles = _rdtsc() - cycles;
	printf("[STACK] [%d] bzero:     %" PRIu64 " cycles\n", SHORTBUF, cycles);
	
	cycles = _rdtsc();
	for(i = NSAMPLES; i > 0; i--){
		bzero(hbuf1, SHORTBUF);
	}
	cycles = _rdtsc() - cycles;
	printf("[HEAP]  [%d] bzero:     %" PRIu64 " cycles\n", SHORTBUF, cycles);
	
	cycles = _rdtsc();
	for(i = NSAMPLES; i > 0; i--){
		my_bzero(sbuf1, SHORTBUF);
	}
	cycles = _rdtsc() - cycles;
	printf("[STACK] [%d] my_bzero:  %" PRIu64 " cycles\n", SHORTBUF, cycles);
	
	cycles = _rdtsc();
	for(i = NSAMPLES; i > 0; i--){
		my_bzero(hbuf1, SHORTBUF);
	}
	cycles = _rdtsc() - cycles;
	printf("[HEAP]  [%d] my_bzero:  %" PRIu64 " cycles\n", SHORTBUF, cycles);
	
	puts("");
	
	/* ------ test long buffers ------ */
	cycles = _rdtsc();
	for(i = NSAMPLES; i > 0; i--){
		bzero(sbuf2, LONGBUF);
	}
	cycles = _rdtsc() - cycles;
	printf("[STACK] [%d] bzero:    %" PRIu64 " cycles\n", LONGBUF, cycles);
	
	cycles = _rdtsc();
	for(i = NSAMPLES; i > 0; i--){
		bzero(hbuf2, LONGBUF);
	}
	cycles = _rdtsc() - cycles;
	printf("[HEAP]  [%d] bzero:    %" PRIu64 " cycles\n", LONGBUF, cycles);
	
	cycles = _rdtsc();
	for(i = NSAMPLES; i > 0; i--){
		my_bzero(sbuf2, LONGBUF);
	}
	cycles = _rdtsc() - cycles;
	printf("[STACK] [%d] my_bzero: %" PRIu64 " cycles\n", LONGBUF, cycles);
	
	cycles = _rdtsc();
	for(i = NSAMPLES; i > 0; i--){
		my_bzero(hbuf2, LONGBUF);
	}
	cycles = _rdtsc() - cycles;
	printf("[HEAP]  [%d] my_bzero: %" PRIu64 " cycles\n", LONGBUF, cycles);
	
	free(hbuf1);
	free(hbuf2);

	hbuf1 = NULL;
	hbuf2 = NULL;

	return 0;
}
