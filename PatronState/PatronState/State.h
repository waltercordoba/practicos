#pragma once
class State
{
public:
	State();
	virtual void Handle(int estado) = 0;
};

