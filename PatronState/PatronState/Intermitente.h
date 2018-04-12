#pragma once
#include "State.h" 
class Intermitente : public State
{
public:
	Intermitente();
	~Intermitente();
	void setTipo(int t) // 0 Intermitente - 1 Verde - 2 Amarillo - 3 Rojo
	{
		tipo = t;
	}
	int getTipo() { return tipo; }

private :
	int tipo;
};

