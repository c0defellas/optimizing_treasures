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
#include <stdint.h>
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

static double mean(const uint64_t *v, size_t len){
	size_t i;
	double temp = 0;
	
	if(len > 0){
		for(i = 0; i < len; i++){
			temp += v[i];
		}
		
		temp /= len;
	}
	
	return temp;
}

int main(void){
	char buf1[SHORTBUF];
	char buf2[LONGBUF];
	uint64_t samples[NSAMPLES];
	register long long temp = 0;
	int i;

	if(setonlyonecpu() < 0){
		perror("Error when setting only one cpu");
		exit(1);
	}
	
	printf("Testing with [%d] samples\n", NSAMPLES);

	/* ----------------- test short buffer -------------------------------- */
	printf("Buffer size [%d]\n", SHORTBUF);
	
	for(i = 0; i < NSAMPLES; i++){
		temp = _rdtsc();
		bzero(buf1, SHORTBUF);
		temp = _rdtsc() - temp;
		
		samples[i] = temp;
	}
	printf("bzero (libc):       %.4f [mean]\n", mean(samples, NSAMPLES));
	
	for(i = 0; i < NSAMPLES; i++){
		temp = _rdtsc();
		cf_bzero(buf1, SHORTBUF);
		temp = _rdtsc() - temp;
		
		samples[i] = temp;
	}
	printf("bzero (c0defellas): %.4f [mean]\n", mean(samples, NSAMPLES));

	puts("");
	temp = 0;
	
	/* ----------------- test long buffer -------------------------------- */
	printf("Buffer size [%d]\n", LONGBUF);
	
	for(i = 0; i < NSAMPLES; i++){
		temp = _rdtsc();
		bzero(buf2, LONGBUF);
		temp = _rdtsc() - temp;
		
		samples[i] = temp;
	}
	printf("bzero (libc):       %.4f [mean]\n", mean(samples, NSAMPLES));
	
	temp = 0;
	
	for(i = 0; i < NSAMPLES; i++){
		temp = _rdtsc();
		cf_bzero(buf2, LONGBUF);
		temp = _rdtsc() - temp;
		
		samples[i] = temp;
	}
	printf("bzero (c0defellas): %.4f [average]\n", mean(samples, NSAMPLES));

	return 0;
}
