/*
Author: Cooler_
Contact: c00f3r[at]gmail[dot]com

Compares arithmetic division with bitwise and  without... 
test CPU cycles...

$ gcc -o code code.c; ./code 
*/
#include <stdio.h>
#include <stdlib.h>
#include <x86intrin.h>
#include <cpuid.h>
#include <inttypes.h>
 
#define LAST "\033[0m"
#define RED "\033[22;31m"
 
void mul()
{
 int x=50,y=0;
 while(x)
 {
  y=x*2;
  x--;
 }
}
 
 
void leftshift()
{
 register int x=50,y=0;
 while(x)
 {
  y=x<<1;
  x--;
 }
}
 
unsigned div7(unsigned n)
{
 return n/7;
}
 
unsigned bit_div7(unsigned num)
{   
 register unsigned x,y;
 
 x=(num>>1)+(num>>4);
 x+=x>>6;
 x+=(x>>12)+(x>>24);
 x>>=2;
 y=num-((x<<3)-x);
 
 return x+((y+1)>>3);
}  
 
 
unsigned div3(unsigned n)
{
 return n/3;
}
 
// 
unsigned bit_div3(unsigned num)
{
 register unsigned x,y;
  
 x=(num>>2)+(num>>4);
 x+=x>>4;
 x+=x>>8;
 x+=x>>16;
 y=num-((x<<2)-x);
// ficou ruim , return x+( ((y<<3)+(y<<2)-y)>>5);
// ruim  return x+( (y+5+(y<<2)) >>4);
 return x+( (((y+1)<<2)+(y+1)) >>4);
 
}
 
 
 
int main(void)
{
  int x=0;
  uint32_t a=0, b=0, c=0, d=0;
  register uint64_t y=0;
 
  x = 0;
  do {
    __cpuid(0, a, b, c, d);
    y = _rdtsc();
    leftshift();
    y = _rdtsc() - y;
  } while (++x < 2);
 
  printf("::: left shift: %s  %lld %s cicles\n",RED, y,LAST);
 
 
  x = 0;
  do {
    __cpuid(0, a, b, c, d);
    y = _rdtsc();
    mul();
    y = _rdtsc() - y;
  } while (++x < 2);
 
  printf("::: mul: %s %lld %s cicles\n", RED,y,LAST);
 
 
  unsigned int z=0;
 
  x = 0;
  do {
    __cpuid(0, a, b, c, d);
    y = _rdtsc();
    z=div7(560000*x);
    printf("result: %d\n",z);
    y = _rdtsc() - y;
  } while (++x < 2);
 
  printf("::: div7: %s %lld %s cicles\n", RED,y,LAST);
 
  z=0;
  x = 0;
 
  do {
    __cpuid(0, a, b, c, d);
    y = _rdtsc();
    z=bit_div7(560000*x);
    printf("result: %d\n",z);
    y = _rdtsc() - y;
  } while (++x < 2);
 
  printf("::: bit_div7:  %s %lld %s cicles\n",RED, y,LAST);
 
 
  x = 0;
  do {
    __cpuid(0, a, b, c, d);
    y = _rdtsc();
    z=div3(560000*x);
    printf("result: %d\n",z);
    y = _rdtsc() - y;
  } while (++x < 2);
 
  printf("::: div3:  %s %lld %s cicles\n",RED, y,LAST);
 
  z=0;
  x = 0;
 
  do {
    __cpuid(0, a, b, c, d);
    y = _rdtsc();
    z=bit_div3(560000*x);
    printf("result: %d\n",z);
    y = _rdtsc() - y;
  } while (++x < 2);
 
  printf("::: bit_div3:  %s %lld %s cicles\n", RED,y,LAST);
 
 
 
  exit(0);
}
