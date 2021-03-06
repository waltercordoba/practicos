// MiTP2.cpp : Defines the entry point for the console application.
//
#include "StdAfx.h"
#include "Operaciones_matematicas.h"
#include "Operaciones_preprocesador.h"
#include "Operaciones_String.h"
#include "Operaciones_logicas.h"
#include "Operaciones_binarias.h"
#include <iostream>
#include <stdio.h> 
#include <string.h>
#define VAR "HOLA"

using std::cout;
using std::cin;
using std::endl;

int main() {
	int opc = 0;
	float fvar1 = 0;
	float fvar2 = 0;
	int ivar1 = 0;
	int ivar2 = 0;
	float frespuesta = 0;
	char cadena1[20];
	char cadena2[20];
	do {
		system("cls");
		cout << "Seleccione la opcion (0-Salir) :" << endl;
		cout << "1-Cuadrado." << endl;
		cout << "2-Suma." << endl;
		cout << "3-Superificie Circulo." << endl;
		cout << "4-Mayor." << endl;
		cout << "5-Concatenar." << endl;
		cout << "6-Imprimir Literal." << endl;
		cout << "7-Comparar." << endl;
		cout << "8-Intercambiar." << endl;
		cout << "9-AND." << endl;
		cout << "10-OR." << endl;
		cout << "11->>." << endl;
		cout << "12-<<." << endl;

		cin >> opc;
		system("cls");
		cin.ignore();

		switch (opc) {
				case 0: //Salida
					cout << "Adios!" << endl;
					break;

				case 1: // Funcion cuadrado
						cout << "Ingrese el numero :" << endl;
						cin >> fvar1;
						cout << "\nEl cuadrado es: " << cuadrado(fvar1) << endl;
						system("pause");
						break;

					case 2: // Funcion Suma
						cout << "Ingrese el primer operando :" << endl;
						cin >> fvar1;
						cout << "Ingrese el segundo operando :" << endl;
						cin >> fvar2;
						cout << "La suma es :" << suma(fvar1, fvar2) << endl;
						system("pause");
						break;

					case 3: //Perimetro de la circunsferencia
						cout << "Ingrese el radio del circulo :" << endl;
						cin >> fvar1;
						cout << "La superficio del circulo es :" << areaCirculo(fvar1) << endl;
						system("pause");
						break;

					case 4: // Comparacion de valores
						cout << "Ingrese el primer operando :" << endl;
						cin >> fvar1;
						cout << "Ingrese el segundo operando :" << endl;
						cin >> fvar2;
						cout << "El mayor es :" << max(fvar1, fvar2) << endl;
						system("pause");
						break;

					case 5: // Cadena de variables
						cout << "Se envian los valores 'l' y 'm' pero se imprime el nombre de los parametros :";
						muestroParametros('l', 'm'); // Imprime el valor de las variables usadas, no su contenido
						system("pause");
						break;

					case 6: // Impresion del literal
						cout << "Se imprime el literal :" << endl;
						printf("%s", VAR);
						cout << "\n";
						system("pause");
						break;

					case 7: // Comparacion de cadenas
						cout << "Introduzca frase 1: " << endl;
						cin.getline(cadena1, sizeof(cadena1));
						cout << "Introduzca frase 2: " << endl;
						cin.getline(cadena2, sizeof(cadena2));

						frespuesta = comparacionCadena(cadena1, cadena2);

						if (frespuesta < 0)
						{
							cout << "La cadena uno es menor que la dos" << endl;
						}
						else if (frespuesta > 0) {
							cout << "La cadena dos es menor que la uno" << endl;
						}
						else {
							cout << "Las cadenas son iguales" << endl;
						}
						system("pause");
						break;

					case 8: // Intercambio de valores
						cout << "Ingrese el primer operando :" << endl;
						cin >> fvar1;
						cout << "Ingrese el segundo operando :" << endl;
						cin >> fvar2;

						intercambiar(&fvar1, &fvar2);

						cout << "El valor del primer operando  ahora es :" << fvar1 << endl;
						cout << "El valor del segundo operando ahora es :" << fvar2 << endl;
						system("pause");
						break;

					case 9: // AND binario
						cout << "Ingrese el primer operando en decimal :" << endl;
						cin >> ivar1;
						cout << "Ingrese el segundo operando en decimal :" << endl;
						cin >> ivar2;
						aBinario(ivar1);
						cout << "\n";
						aBinario(ivar2);
						cout << "\n";
						aBinario(andBinario(ivar1, ivar2));
						cout << "\n";
						system("pause");
						break;

					case 10: // OR binario
						cout << "Ingrese el primer operando en decimal :" << endl;
						cin >> ivar1;
						cout << "Ingrese el segundo operando en decimal :" << endl;
						cin >> ivar2;
						aBinario(ivar1);
						cout << "\n";
						aBinario(ivar2);
						cout << "\n";
						aBinario(orBinario(ivar1, ivar2));
						cout << "\n";
						system("pause");
						break;

					case 11: // Desplazamiento binario DERECHA
						cout << "Ingrese el operando en decimal :" << endl;
						cin >> ivar1;
						aBinario(ivar1);
						cout << "\n";
						aBinario( derechaBinario(ivar1) );
						cout << "\n";
						system("pause");
						break;

					case 12: // Desplazamiento binario IZQUIERDA
						cout << "Ingrese el operando en decimal :" << endl;
						cin >> ivar1;
						aBinario(ivar1);
						cout << "\n";
						aBinario(izquierdaBinario(ivar1));
						cout << "\n";
						system("pause");
						break;
		}
	} while (opc != 0);
	return 0;
}


