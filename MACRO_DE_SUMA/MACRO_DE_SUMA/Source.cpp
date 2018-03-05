//************************************************************************************
// Programa ID: Macro de Suma 
// Autor: Walter Córdoba - cbawalter@gmail.com
// Fecha Creacion: 05/03/2018
// Version Inicial.
//************************************************************************************
#include <iostream>
#include <stdlib.h>
//************************************************************************************
// Estas MACROS de funcion estan definidas correctamente
//************************************************************************************
#define SUMAR_OK(a, b)  ((a) + (b)) 
#define rnd_ok(min, max) ((rand()%(int)(((max) + 1)-(min)))+ (min))  
//
//
//************************************************************************************
// Estas MACROS de funcion estan definidas sin los parentesis.
// Esto puede causar diferencias en el orden de evaluacion de la expresion.
//************************************************************************************
#define SUMAR_NOOK(a, b)   a + b 
#define rnd_nook(min, max) rand()%(int)  max + 1 - min + min      
//************************************************************************************
//
using namespace std;

int main() {
	string a = "Hola ";
	string b = "Mundo";
	float arg1 = 125.33;
	float arg2 = 24.44;

	cout << "Resultados de las funciones definidas CORRECTAMENTE";
	cout << "\nSuma = " << SUMAR_OK(arg1, arg2);
	cout << "\nRandom = " << rnd_ok(arg1, arg2);

	cout << "\n";
	cout << "\n";
	cout << "\n";

	cout << "Resultados de las funciones definidas INCORRECTAMENTE";
	cout << "\nSuma = " << SUMAR_NOOK(arg1, arg2);
	cout << "\nRandom = " << rnd_nook(arg1, arg2);

	cin >> arg1;
	return 0;
}
