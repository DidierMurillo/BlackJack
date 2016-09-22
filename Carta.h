#include <string>
using std::string;
#pragma once

class Carta
{
private:
	string Simbolo;
	int Numero;
	string Color;

public:
	Carta(string,int,string);
	~Carta();
	string toString();
	int getNumero();
	string getSimbolo();
	string getColor();
};