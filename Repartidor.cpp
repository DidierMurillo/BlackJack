#include <string>
#include <vector>
#include "Baraja.h"
#include "Repartidor.h"
#include <time.h>
#include <stdlib.h>
using std::string;
using namespace std;
#include <sstream>
using std::stringstream;

Repartidor::Repartidor(string Nombre,string Edad,string ID,string Dificultad,int ConteoJuegos,int MontoMaximo):Persona(Nombre,Edad,ID),Dificultad(Dificultad)
,ConteoJuegos(ConteoJuegos),MontoMaximo(MontoMaximo){
	this->BarajaTexas=new Baraja();
}

Repartidor::~Repartidor(){

}

void Repartidor::setDificultad(string Dificultad){
	this->Dificultad=Dificultad;
}

void Repartidor::setConteoJuegos(int ConteoJuegos){
	this->ConteoJuegos=ConteoJuegos;
}

void Repartidor::setMontoMaximo(int MontoMaximo){
	this->MontoMaximo=MontoMaximo;
}

string Repartidor::toString(){
	stringstream ss;
	ss<<Persona::toString()<<"Dificultad:"<<Dificultad<<" Conteo de Juegos: "<<ConteoJuegos<<" Monto Maximo: "<<MontoMaximo;
	return ss.str();
}

void Repartidor::setMano(Carta* C){
 	this->Mano.push_back(C);
}

string Repartidor::verMano(){
	stringstream ss;
	for (int i = 0; i < this->Mano.size(); ++i)
	{
		ss<<this->Mano.at(i)->toString();
	}
	
	return ss.str();
}

int Repartidor::CalcularMano(){
	int Total=0,Temporal=0;
	for (int i = 0; i <this->Mano.size() ; ++i)
	{
		if (Mano.at(i)->getNumero()==74)
		{
			Temporal=10;
		}else if(Mano.at(i)->getNumero()==75){
			Temporal=10;
		}else if(Mano.at(i)->getNumero()==81){
			Temporal=10;
		}else if(Mano.at(i)->getNumero()==65){
			Temporal=11;
		}else{
			Temporal=Mano.at(i)->getNumero();
		}
		Total+=Temporal;
		
	}
	for (int i = 0; i <this->Mano.size()+3 ; ++i)
	{
		Mano.pop_back();
	}
	return Total;

}

int Repartidor::CalcularMano(int SobreCarga){
	int Total=0,Temporal=0;
	for (int i = 0; i <this->Mano.size() ; ++i)
	{
		if (Mano.at(i)->getNumero()==74)
		{
			Temporal=10;
		}else if(Mano.at(i)->getNumero()==75){
			Temporal=10;
		}else if(Mano.at(i)->getNumero()==81){
			Temporal=10;
		}else if(Mano.at(i)->getNumero()==65){
			Temporal=11;
		}else{
			Temporal=Mano.at(i)->getNumero();
		}
		Total+=Temporal;
		
	}
	return Total;

}


Carta* Repartidor::Repartir(){
	return BarajaTexas->getCarta();

}

void Repartidor::setBaraja(){
	this->BarajaTexas=new Baraja();
}