#include <string>
#include <vector>
#include "Carta.h"
using namespace std;

using std::string;
#pragma once

class Baraja
{
private:
	vector<Carta*> baraja;

public:
	Baraja();
	~Baraja();
	Carta* getCarta();
	
	
};