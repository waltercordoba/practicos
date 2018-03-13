#include "StdAfx.h"
#include <string.h>
#define ENTRECOMILLAS(x,y) #x #y

void muestroParametros(char a, char b)
{
	printf("%s\n", ENTRECOMILLAS(a, b));
}
