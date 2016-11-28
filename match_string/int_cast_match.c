/*
  Curious match with casting
  undefined behavior but runs
 

  */
#include <stdio.h>
#include <stdint.h>

int main()
{
	uint64_t x=*(uint64_t *)"action =";
	char *var="action =gijoe command test";
	uint64_t z=*(uint64_t *)var;
 
	if(x==z)
        	puts("OK");
 	else
        	puts("NOT MATCH");
// what is it ?
// http://en.wikipedia.org/wiki/Magic_number_%28programming%29#Unnamed_numerical_constants﻿

	return 0;
}
