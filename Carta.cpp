#include <sstream>
using std::stringstream;
#include "Carta.h"
#include <string>
using std::string;

Carta::Carta(string Simbolo,int Numero,string Color):Simbolo(Simbolo),Numero(Numero),Color(Color){

}

Carta::~Carta(){

}

string Carta::getSimbolo(){
	return this->Simbolo;
}

int Carta::getNumero(){
	return this->Numero;
}

string Carta::getColor(){
	return this->Color;
}

string Carta::toString(){
	stringstream ss;
	if(Numero==75){
		ss<<1<<"  "<<'J'<<" ";	
	}else if(Numero==81){
		ss<<2<<"  "<<'Q'<<" ";
	}else if(Numero==65){
		ss<<3<<"  "<<'A'<<" ";
	}else if(Numero==74){
		ss<<4<<"  "<<'K'<<" ";
	}else{
		ss<<5<<"  "<<Numero<<" ";
	}
	
	return ss.str();
}