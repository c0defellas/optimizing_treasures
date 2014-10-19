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
#include <unistd.h>
#include <sched.h>
#include <x86intrin.h>

#define SSIZE	107
#define LSIZE	1000007

extern void bzero_longbuffer(void *, size_t len);

static void (*cf_bzero)(void *, size_t len) = bzero_longbuffer;

static int setonlyonecpu(void){
	cpu_set_t cpuset;
	CPU_ZERO(&cpuset);
	CPU_SET(0, &cpuset);

	return sched_setaffinity(getpid(), sizeof(cpu_set_t), &cpuset);
}


int main(void){
	char buf1[SSIZE];
	char buf2[LSIZE];

	register long long c;

	if(setonlyonecpu() < 0){
		perror("Error when setting only one cpu");
		exit(1);
	}

	//test short buffer
	printf("Buffer size is: %d\n", SSIZE);
	c = _rdtsc();
	bzero(buf1, SSIZE);
	c = _rdtsc() - c;
	printf("bzero (libc):        %lld cycles\n", c);

	c = _rdtsc();
	cf_bzero(buf1, SSIZE);
	c = _rdtsc() - c;
	printf("bzero (c0defellas):  %lld cycles\n", c);
	
	puts("");

	//test long buffer
	printf("Buffer size is: %d\n", LSIZE);
	c = _rdtsc();
	bzero(buf2, LSIZE);
	c = _rdtsc() - c;
	printf("bzero (libc):        %lld cycles\n", c);

	c = _rdtsc();
	cf_bzero(buf2, LSIZE);
	c = _rdtsc() - c;
	printf("bzero (c0defellas):  %lld cycles\n", c);

	return 0;
}
