#include "stdafx.h"
#include<iostream>
using namespace std;
bool isPrime(int num, int divisor)
{
	if (num < 4) return true;
	if (divisor == 1) return true;
	else
		if (num % divisor == 0)	return false;
		else return isPrime(num, divisor - 1);
}