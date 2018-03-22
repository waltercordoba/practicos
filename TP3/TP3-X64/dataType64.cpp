#include "stdafx.h"
#include <stdio.h>
void showDataType(char cvar)
{
	// ************* PUNTO 2 *************
	// Decimal
	printf("Valor en Decimal:\%d\n", cvar);
	// Hexadecimal
	printf("Valor en Hexadecimal:\%#x\n", cvar);
	// Octal
	printf("Valor en Octal:\%#o\n", cvar);
	// Caracter
	printf("Caracter:\%c\n", cvar);

}