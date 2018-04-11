#pragma once
#include<string>
class Singleword{
public:
	// Constructor:
	Singleword::Singleword();
	Singleword(std::string w);
	~Singleword();
	const std::string getWord();
	Singleword * getSiguiente();
	void setWord(std::string);
	void setSiguiente(Singleword *);
private:
	// Miembros:
	std::string word;
	Singleword *siguiente;
};

