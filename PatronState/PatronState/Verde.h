#pragma once
#include "State.h" 
#include"Context.h"

class Verde: public State
{
public:
	Verde();
	Verde(Context* context);
	void Handle(int estado);
	~Verde();
private:
	Context* _context;
};

