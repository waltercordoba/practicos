#pragma once
#include "State.h" 
#include"Context.h"

class Rojo: public State
{
public:
	Rojo();
	Rojo(Context* context);
	void Handle(int estado);
	~Rojo();
private:
	Context* _context;
};

