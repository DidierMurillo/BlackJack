#include "Jugador.h"
#include "Carta.h"
#include <string>
using std::string;
#include <sstream>
using std::stringstream;
#include <vector>
using namespace std;

Jugador::Jugador(string Nombre,string Edad,string ID,string Lugar,string Apodo,int Dinero):Persona(Nombre,Edad,ID),
Lugar(Lugar),Apodo(Apodo),Dinero(Dinero){

}

Jugador::~Jugador(){

}

void Jugador::setLugar(string Lugar){
	this->Lugar=Lugar;
}

void Jugador::setApodo(string Apodo){
	this->Apodo=Apodo;
}

void Jugador::setDinero(int Dinero){
	this->Dinero+=Dinero;
}

string Jugador::toString(){
	stringstream ss;
	ss<<Persona::toString()<<"Lugar: "<<Lugar<<" Apodo:"<<Apodo<<" Total Dinero:"<<Dinero;
	return ss.str();
}

void Jugador::setMano(Carta* C){
 	this->Mano.push_back(C);
}

string Jugador::verMano(){
	stringstream ss;
	for (int i = 0; i < this->Mano.size(); ++i)
	{
		ss<<this->Mano.at(i)->toString();
	}
	
	return ss.str();
}

int Jugador::CalcularMano(){
	int Total=0,Temporal=0;
	for (int i = 0; i < this->Mano.size(); ++i)
	{
		if (Mano.at(i)->getNumero()==81)
		{
			Temporal=10;
		}else if(Mano.at(i)->getNumero()==74){
			Temporal=10;
		}else if(Mano.at(i)->getNumero()==75){
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