#pragma once
#include"Intermitente.h"
#include"State.h"
class Context
{
public:
	Context();
	~Context();
	void setState(State * newState);
	State * getState();
	void Handle(int estado);
private:
	State* _state;
};

