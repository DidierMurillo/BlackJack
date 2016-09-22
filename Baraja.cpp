#include "Carta.h"
#include "Baraja.h"
#include <string>
#include <vector>
using std::string;
using namespace std;
#include <time.h>
#include <stdlib.h>

Baraja::Baraja(){
	string Simbolo;
	char Numero;
	string Color;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 1; j < 13; ++j)
		{
			if (i==0)
			{
				Simbolo="♠";
				Color="Negro";
			}else if (i==1)
			{
				Simbolo="♥";
				Color="Rojo";
			}else if (i==2)
			{
				Simbolo="♦";
				Color="Rojo";
			}else if (i==3)
			{
				Simbolo="♣";
				Color="Negro";
			}

			if (j==11)
			{
				Numero=74;
			}else if (j==12)
			{
				Numero=81;
			}else if (j==13)
			{
				Numero=75;
			}else if (j==1)
			{
				Numero=65;
			}else{
				Numero=j;
			}
			this->baraja.push_back(new Carta(Simbolo,Numero,Color));
		}
	}
}

Baraja::~Baraja(){

}

Carta* Baraja::getCarta(){
	//srand(time(NULL));
	int Temporal,Random;
	time_t t;
    srand((unsigned) time(&t));
    Random=(1 + rand() % 2);
    if(Random==1){
    	Temporal=(1+rand()%26);
    }else{
    	Temporal=(25 + rand() % 26);
    }
	this->baraja.erase(this->baraja.begin()+Temporal);
	return this->baraja.at(Temporal);
}


  
