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

int match_test(char *string, char *expression)
{

	regex_t regex;
	int reti;

	reti = regcomp(&regex, expression, REG_EXTENDED);

	if(reti) 
	{
		puts("Could not compile regex ! \n");
		return 0;
	}
	reti = regexec(&regex, string, 0, NULL, 0);

	regfree(&regex);

	if( !reti )
		return 1;
	else 
		return 0;

}

int matchs=0;

const char *text[]= {"1234-1234","batman","1234 4321","abcd-1234","macaco","sopa-4321","1337-7331","chaves","kiko","florinda","chiquinha","madruga","senhor barriga","girafales","inhonho","thundercats","he-man","dragon ball","naruto","3311-2399","sub-zero","raiden","ryu","power rangers","ranger-1337","1337-1337","007","hulk","spider-man","darth vader","super-man","0071-1212","dragonite","mumia","fredy kruger","jason","golun","nozes","3135-9921","chupa-cabra","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves","abcd-1234","macaco","sopa-4321","1337-7331","chaves"};


void call_count()
{
	int result=0,count=0;

	while(count != array_elements(text))
	{	 
   //		fprintf(stdout,"String to test: %s \n",text[count]);
		result = match_test( (char *)text[count],"[0-9]{4}(-| )[0-9]{4}");
		if (result)
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
 
	printf("::: Posix regex: %ld  cicles\n", y);
	fprintf(stdout,"Array size of words is: %ld \n",array_elements(text));	
	fprintf(stdout,"Benchmark match posix regex [0-9]{4}(-| )[0-9]{4} - total matches : %d \n",matchs);

 exit(0);
}

