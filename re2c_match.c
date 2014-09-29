/*
 *
 * Fast Match test
 * by Cooler_
 * c00f3r@gmail.com
 *
 * $ re2c thiscode.c > new_code.c; gcc -o new_code new_code.c; ./new_code
re2c is a tool for writing very fast and very flexible scanners. Unlike any other such tool, re2c focuses on generating high efficient code for regular expression matching. As a result this allows a much broader range of use than any traditional lexer offers. And Last but not least re2c generates warning free code that is equal to hand-written code in terms of size, speed and quality. 

 * */

#include <stdio.h>
#include <stdlib.h>

int test_cell(const char* p)
{
    const unsigned char* marker; // marker=NULL;
/*!re2c
    re2c:define:YYCTYPE  = "unsigned char";
    re2c:define:YYCURSOR = p;
    re2c:yyfill:enable = 0;
    re2c:define:YYMARKER = marker;
    re2c:yych:conversion = 1;
    ([0-9]{4}[-| ][0-9]{4}) { return 0; }
    "" { return 1; }
*/
}

const char *text[]= {"1234-1234","1234 4321","abcd-1234","macaco","sopa-4321","1337-7331"};

int main()
{
 int result=0;
 short count=0;


	puts("test validator of celphones with 8 digits");

	while(count != 6)
	{	 
   		fprintf(stdout,"String to test: %s \n",text[count]);
		result = test_cell(text[count]);

		if (!result)
			puts("Matched !\n");
		else
			puts("Not Match\n");

		count++;

	}

 exit(0);
}
