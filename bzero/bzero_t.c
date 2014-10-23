/* 
 * bzero_t.c - test bzero functions
 * Joao Guilherme aka "pl4nkt0n"
 * jgvictorino1 [at] gmail [dot] com
 * 
 */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <unistd.h>
#include <math.h>
#include <sched.h>
#include <x86intrin.h>

#define SHORTBUF	107
#define LONGBUF		1000007
#define NSAMPLES	1000

extern void bzero_longbuffer(void *, size_t len);

static void (*cf_bzero)(void *, size_t len) = bzero_longbuffer;

static int setonlyonecpu(void){
	cpu_set_t cpuset;
	CPU_ZERO(&cpuset);
	CPU_SET(0, &cpuset);

	return sched_setaffinity(getpid(), sizeof(cpu_set_t), &cpuset);
}


int main(void){
	char buf1[SHORTBUF];
	char buf2[LONGBUF];
	char *hbuf1 = NULL;
	char *hbuf2 = NULL;
	
	uint64_t sum = 0;
	register uint64_t temp = 0;
	int i;
	
	hbuf1 = (char *)malloc(SHORTBUF);
	hbuf2 = (char *)malloc(LONGBUF);
	
	if((!hbuf1) || (!hbuf2)){
		fprintf(stderr, "malloc fail\n");
		exit(EXIT_FAILURE);
	}
	
	
	if(setonlyonecpu() < 0){
		perror("Error when setting only one cpu");
		exit(EXIT_FAILURE);
	}

	/* ----------------- test short buffer -------------------------------- */
	printf("STACK BUFFER [%d]\n", SHORTBUF);
	
	for(i = 0; i < NSAMPLES; i++){
		temp = _rdtsc();
		bzero(buf1, SHORTBUF);
		temp = _rdtsc() - temp;
		
		sum += temp;
	}
	printf("bzero (libc):       %" PRIu64 " cycles\n", sum);
	
	sum = 0;
	for(i = 0; i < NSAMPLES; i++){
		temp = _rdtsc();
		cf_bzero(buf1, SHORTBUF);
		temp = _rdtsc() - temp;
		
		sum += temp;
	}
	printf("bzero (c0defellas): %" PRIu64 " cycles\n", sum);

	puts("");
	
	
	printf("HEAP BUFFER [%d]\n", SHORTBUF);
	sum = 0;
	for(i = 0; i < NSAMPLES; i++){
		temp = _rdtsc();
		bzero(hbuf1, SHORTBUF);
		temp = _rdtsc() - temp;
		
		sum += temp;
	}
	printf("bzero (libc):       %" PRIu64 " cycles\n", sum);
	
	sum = 0;
	for(i = 0; i < NSAMPLES; i++){
		temp = _rdtsc();
		cf_bzero(hbuf1, SHORTBUF);
		temp = _rdtsc() - temp;
		
		sum += temp;
	}
	printf("bzero (c0defellas): %" PRIu64 " cycles\n", sum);
	
	puts("");
	
	/* ----------------- test long buffer -------------------------------- */
	printf("STACK BUFFER [%d]\n", LONGBUF);
	sum = 0;
	for(i = 0; i < NSAMPLES; i++){
		temp = _rdtsc();
		bzero(buf2, LONGBUF);
		temp = _rdtsc() - temp;
		
		sum += temp;
	}
	printf("bzero (libc):       %" PRIu64 " cycles\n", sum);
	
	sum = 0;
	for(i = 0; i < NSAMPLES; i++){
		temp = _rdtsc();
		cf_bzero(buf2, LONGBUF);
		temp = _rdtsc() - temp;
		
		sum += temp;
	}
	printf("bzero (c0defellas): %" PRIu64 " cycles\n", sum);
	
	puts("");
	
	printf("HEAP BUFFER [%d]\n", LONGBUF);
	sum = 0;
	for(i = 0; i < NSAMPLES; i++){
		temp = _rdtsc();
		bzero(hbuf2, LONGBUF);
		temp = _rdtsc() - temp;
		
		sum += temp;
	}
	printf("bzero (libc):       %" PRIu64 " cycles\n", sum);
	
	sum = 0;
	for(i = 0; i < NSAMPLES; i++){
		temp = _rdtsc();
		cf_bzero(hbuf2, LONGBUF);
		temp = _rdtsc() - temp;
		
		sum += temp;
	}
	printf("bzero (c0defellas): %" PRIu64 " cycles\n", sum);
	
	free(hbuf1);
	free(hbuf2);

	return 0;
}
