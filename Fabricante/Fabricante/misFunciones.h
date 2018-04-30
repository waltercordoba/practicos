#pragma once
#include "stdafx.h"
#include "misFunciones.h"
#include <iostream>
#include<string>
#include <sstream>
#include <fstream>
#include <deque>

const int fabricante(const int P, const int precioVenta, const int cantidadVenta, int* precioCompra, int* cantidadCompra, const int F);
void load(int precioVenta, int cantidadVenta, int* precioCompra, int* cantidadCompra, int F);
void splintIn(const std::string entrada, int &P, int &precioVenta, int &cantidadVenta, int &F);
const int lookingBestOption(const int precioVenta, const int cantidadVenta, const int* precioCompra, const int* cantidadCompra, const int F);