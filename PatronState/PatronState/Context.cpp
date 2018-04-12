#include "stdafx.h"
#include "Context.h"
#include"Intermitente.h"
#include"State.h"
#include"Amarillo.h"

Context::Context()
{
	_state = new Amarillo(this);
}
Context::~Context(){}

void Context::setState(State * newState)
{
	_state = newState;
}
State * Context::getState()
{
	return _state;
}
void Context::Handle(int estado)
{
	_state->Handle(estado);
}
