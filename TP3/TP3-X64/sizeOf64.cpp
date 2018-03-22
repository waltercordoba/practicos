#include "stdafx.h"
#include <stdio.h>


void showSize(short svar, int ivar, float fvar, double dvar, long lvar, long long llvar, size_t stvar)
{
	// ******************** PUNTO 1 ***********************
	printf("La longitud de SHORT es %zu\n", sizeof(svar));
	printf("La longitud de INTEGER es %zu\n", sizeof(ivar));
	printf("La longitud de FLOAT es %zu\n", sizeof(fvar));
	printf("La longitud de DOUBLE es %zu\n", sizeof(dvar));
	printf("La longitud de LONG es %zu\n", sizeof(lvar));
	printf("La longitud de LONG-LONG es %zu\n", sizeof(llvar));
	printf("La longitud de SIZE-T es %zu\n", sizeof(stvar));
}
