#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include<float.h>
#include<iostream>
#include<inttypes.h>


void numericLimits(short svar, int ivar, float fvar, double dvar, long lvar, long long llvar, size_t stvar) {
	// ************* PUNTO 3 *************
	//
	svar = SHRT_MIN;
	printf("SHORT MINIMO es %d\n", svar);
	svar = SHRT_MAX;
	printf("SHORT MAXIMO es %d\n\n\n", svar);

	// INTEGER
	ivar = INT_MIN;
	printf("INT MINIMO es %d\n", ivar);
	ivar = INT_MAX;
	printf("INT MAXIMO es %d\n\n\n", ivar);

	// FLOAT
	fvar = -FLT_MAX;
	printf("FLOAT MINIMO es %f\n", fvar);
	fvar = FLT_MAX;
	printf("FLOAT MAXIMO es %f\n\n\n", fvar);

	// DOUBLE
	dvar = -DBL_MAX;
	printf("DOUBLE MINIMO es  %f\n\n\n", dvar);
	dvar = DBL_MAX;
	printf("DOUBLE MAXIMO es  %f\n\n\n", dvar);

	// LONG
	lvar = LONG_MIN;
	printf("LONG MINIMO es %ld\n", lvar);
	lvar = LONG_MAX;
	printf("LONG MAXIMO es %ld\n\n\n", lvar);

	// LONG-LONG
	llvar = LLONG_MIN;
	printf("LONG-LONG MINIMO es %lld\n", llvar);
	llvar = LLONG_MAX;
	printf("LONG-LONG MAXIMO es %lld\n", llvar);

}