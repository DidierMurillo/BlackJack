#include "Carta.h"
#include "Persona.h"
#include <string>
#include <vector>
using namespace std;
#pragma once

class Jugador: public Persona
{
private:
	int Dinero;
	int Apuesta;
	string Lugar;
	string Apodo;
	vector<Carta*> Mano;

public:
	Jugador(string,string,string,string,string,int);
	~Jugador();
	int getHandSize();
	void setCartas(Carta*);
	void setLugar(string);
	void setApodo(string);
	void setDinero(int);
	string toString();
	void setMano(Carta*);
	int CalcularMano(int);
	string verMano();
	Carta* getCarta(int);
};
