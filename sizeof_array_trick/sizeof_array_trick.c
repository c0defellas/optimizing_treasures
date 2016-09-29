/*
 * This is simple trick you can discovery size of array without sizeof...
 *
 * Github: CoolerVoid
 * contact: coolerlair@gmail.com
 * */

#include <stdio.h>

int main()
{
	char str[]="just another test";
	int len0 = (&str)[1] - str;
	int len1 = *(&str+1) - str;

	printf("char %d\n char %d\n", len0,len1);

	return 0;


}
