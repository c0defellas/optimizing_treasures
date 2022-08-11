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
#include <string.h>
#include <pcre.h>
#include <x86intrin.h>
#include <cpuid.h>
#include <inttypes.h>

#define array_elements(array) (sizeof(array) / sizeof *(array))

int match_test(const char *string,const char *expression)
{
	const char *err;
	int errofs=0,offset=0;
	int ovector[100];

	pcre *re = pcre_compile(expression, 0, &err, &errofs, NULL);
	if (re == NULL) 
	{
		fprintf(stderr, " regex compilation failed\n");
		exit(EXIT_FAILURE);
	}
	const int rc = pcre_exec(re, NULL, string, strlen(string), offset, 0, ovector, array_elements(ovector));
	pcre_free(re);

	return rc > 0;

}

int matchs=0;

const char *text[]= {"1234-1234","batman","1234 4321","abcd-1234","macaco","sopa-4321","1337-7331","chaves","kiko","florinda","chiquinha","madruga","senhor barriga","girafales","inhonho","thundercats","he-man","dragon ball","naruto","3311-2399","sub-zero","raiden","ryu","power rangers","ranger-1337","1337-1337","007","hulk","spider-man","darth vader","super-man","0071-1212","dragonite","mumia","fredy kruger","jason","golun","nozes","3135-9921","chupa-cabra","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves"};


void call_count()
{
	int result=0,count=0;
	char *exp="\\d{4}( |-)\\d{4}";

	while(count != array_elements(text))
	{	 
//   		fprintf(stdout,"String to test: %s \n",text[count]);
		result = match_test( text[count],exp);
		if (result)
			matchs++;
/*		else
			puts("Not Match\n");
*/
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
 
	printf("::: PCRE regex: %ld  cicles\n",y);
	fprintf(stdout,"Array size of words is: %ld \n",array_elements(text));	
	fprintf(stdout,"Benchmark PCRE \\d{4}( |-){1}\\d{4} matchs is: %d \n\n",matchs);

 exit(0);
}

