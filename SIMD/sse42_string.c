#include <stdio.h>
#include <stdlib.h>
/*

+----------------+------------------------------------------------------------------------------------------+
|     Header     |                                         Purpose                                          |
+----------------+------------------------------------------------------------------------------------------+
| x86intrin.h    | Everything, including non-vector x86 instructions like _rdtsc().                         |
| mmintrin.h     | MMX (Pentium MMX!)                                                                       |
| mm3dnow.h      | 3dnow! (K6-2) (deprecated)                                                               |
| xmmintrin.h    | SSE + MMX (Pentium 3, Athlon XP)                                                         |
| emmintrin.h    | SSE2 + SSE + MMX (Pentium 4, Athlon 64)                                                  |
| pmmintrin.h    | SSE3 + SSE2 + SSE + MMX (Pentium 4 Prescott, Athlon 64 San Diego)                        |
| tmmintrin.h    | SSSE3 + SSE3 + SSE2 + SSE + MMX (Core 2, Bulldozer)                                      |
| popcntintrin.h | POPCNT (Nehalem (Core i7), Phenom)                                                       |
| ammintrin.h    | SSE4A + SSE3 + SSE2 + SSE + MMX (AMD-only, starting with Phenom)                         |
| smmintrin.h    | SSE4_1 + SSSE3 + SSE3 + SSE2 + SSE + MMX (Penryn, Bulldozer)                             |
| nmmintrin.h    | SSE4_2 + SSE4_1 + SSSE3 + SSE3 + SSE2 + SSE + MMX (Nehalem (aka Core i7), Bulldozer)     |
| wmmintrin.h    | AES (Core i7 Westmere, Bulldozer)                                                        |
| immintrin.h    | AVX, AVX2, AVX512, all SSE+MMX (except SSE4A and XOP), popcnt, BMI/BMI2, FMA             |
+----------------+------------------------------------------------------------------------------------------+

*/
#include <smmintrin.h>
#include <nmmintrin.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>

inline size_t strnlen_sse42(const char* str, size_t size) 
{

	size_t result = 0;

	__m128i* buf = (__m128i *)(const char*)(str);
	const __m128i zeros = _mm_setzero_si128();

	size--; // to jmp nullbyte

	while(size) 
	{

		const __m128i data = _mm_loadu_si128(buf);

		const int mode = _SIDD_UBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_LEAST_SIGNIFICANT;


		if(_mm_cmpistrc(data, zeros, mode)) 
		{
			const int idx = _mm_cmpistri(data, zeros, mode);
			return result + idx;
        	}

		buf++; 
		result+=16;
		size--;
	}

	return 0;
}

inline int strncmp_sse42(const char* str1, const char* str2, size_t size) 
{

	if(str1 == str2) 
        	return 0;
	
	__m128i* ptr1 = (__m128i *)((const char *)str1);
	__m128i* ptr2 = (__m128i *)((const char *)str2);

	size--; // to jmp nullbyte

	while (size) 
	{
		const __m128i x = _mm_loadu_si128(ptr1);
		const __m128i y = _mm_loadu_si128(ptr2);
		const uint8_t mode = _SIDD_UBYTE_OPS | _SIDD_CMP_EQUAL_EACH | _SIDD_NEGATIVE_POLARITY | _SIDD_LEAST_SIGNIFICANT;
       
		if (_mm_cmpistrc(x, y, mode)) 
		{
			const int idx = _mm_cmpistri(x, y, mode);
			const uint8_t a = ((char *)ptr1)[idx];
			const uint8_t b = ((char *)ptr2)[idx];

			if (a < b) 
				return -1;
			else if (a > b) 
				return +1;
			else 
				return 0;
           
		} else if (_mm_cmpistrz(x, y, mode)) 
			break;
        
		ptr1++; 
		ptr2++;
		size--;
	}

	return 0;
}


inline int strnchr_sse42(const char* str, size_t c, size_t size) 
{
    	assert(c >= 0);
    	assert(c < 256);

    	__m128i* bits = (__m128i *)str;

    	const __m128i buf = _mm_setr_epi8(c, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    	const uint8_t mode = _SIDD_UBYTE_OPS | _SIDD_CMP_EQUAL_ANY | _SIDD_LEAST_SIGNIFICANT;

	size--; // to don't follow nullbyte        

	while(size) 
	{

        	const __m128i chunk = _mm_loadu_si128(bits);

        	if(_mm_cmpistrc(buf, chunk, mode)) 
		{
            		const int idx = _mm_cmpistri(buf, chunk, mode);
			return (int)( ((char *)bits+idx)-str-2);
			break;

        	} else if (_mm_cmpistrz(buf, chunk, mode)) 
            		break;
       		bits++; 
		size--;
    	}

	return 0;
}

int strstr_sse42(const char *str, size_t strsize, const char *str2cmp, size_t size2cmp)
{
		

	

	return 0;
}



int main() 
{
	char *test="babaca babaca cara\n";

	printf("%s\n",test);	


}

