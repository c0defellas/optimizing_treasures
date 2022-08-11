/*
 *
 * Fast Match test with posix regex
 * by Cooler_
 * c00f3r@gmail.com
 *
 * 
 * */

#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <x86intrin.h>
#include <cpuid.h>
#include <inttypes.h>

#define array_elements(array) (sizeof(array) / sizeof *(array))




int match_test( const char* p)
{
    const unsigned char* marker;

	unsigned char yych;

	yych = (unsigned char)*(marker = p);
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy3;
	default:	goto yy2;
	}
yy2:
	{ return 1; }
yy3:
	yych = (unsigned char)*++p;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy5;
	default:	goto yy4;
	}
yy4:
	p = marker;
	goto yy2;
yy5:
	yych = (unsigned char)*++p;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy6;
	default:	goto yy4;
	}
yy6:
	yych = (unsigned char)*++p;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy7;
	default:	goto yy4;
	}
yy7:
	yych = (unsigned char)*++p;
	switch (yych) {
	case ' ':
	case '-':
	case '|':	goto yy8;
	default:	goto yy4;
	}
yy8:
	yych = (unsigned char)*++p;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy9;
	default:	goto yy4;
	}
yy9:
	yych = (unsigned char)*++p;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy10;
	default:	goto yy4;
	}
yy10:
	yych = (unsigned char)*++p;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy11;
	default:	goto yy4;
	}
yy11:
	yych = (unsigned char)*++p;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy12;
	default:	goto yy4;
	}
yy12:
	++p;
	{ return 0; }

}








int matchs=0;

const char *text[]= {"1234-1234","batman","1234 4321","abcd-1234","macaco","sopa-4321","1337-7331","chaves","kiko","florinda","chiquinha","madruga","senhor barriga","girafales","inhonho","thundercats","he-man","dragon ball","naruto","3311-2399","sub-zero","raiden","ryu","power rangers","ranger-1337","1337-1337","007","hulk","spider-man","darth vader","super-man","0071-1212","dragonite","mumia","fredy kruger","jason","golun","nozes","3135-9921","chupa-cabra","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves"};


void call_count()
{
	int result=0,count=0;

	while(count != array_elements(text))
	{	 
   //		fprintf(stdout,"String to test: %s \n",text[count]);
		result = match_test( text[count]);
		if (!result)
			matchs++;

		result=0;
		count++;

	}


}

int main()
{
	long int x=0;
	uint32_t a=0, b=0, c=0, d=0;
	register uint64_t y=0;

  	x = 0;
  	do {
		__cpuid(0, a, b, c, d);
		y = _rdtsc();
		call_count();
		y = _rdtsc() - y;

	} while (++x < 2);
 
	printf("::: Re2c : %ld  cicles\n", y);
	fprintf(stdout,"Array size of words is: %ld \n",array_elements(text));	
	fprintf(stdout,"Benchmark match posix regex [0-9]{4}(-| )[0-9]{4} - total matches : %d \n",matchs);

 exit(0);
}

