#pragma once
#include "State.h" 
#include"Context.h"

class Amarillo: public State
{
public:
	Amarillo();
	Amarillo(Context* context);
	void Handle(int estado);
	~Amarillo();
private:
	Context* _context;
};

