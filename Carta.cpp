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
		if (Simbolo == "♥"){
			ss<<"****    | J |    *****\n";
		}else if (Simbolo == "♠"){
			ss<<"****    | J |     ****\n";
		}else if (Simbolo == "♣"){
			ss<<"**      | J |      ***\n";
		}else if (Simbolo == "♦"){
			ss<<"*****    | J |    ****\n";
		}		
	}else if(Numero==81){
		if (Simbolo == "♥"){
			ss<<"****    | Q |    *****\n";
		}else if (Simbolo == "♠"){
			ss<<"****    | Q |     ****\n";
		}else if (Simbolo == "♣"){
			ss<<"**      | Q |      ***\n";
		}else if (Simbolo == "♦"){
			ss<<"*****    | Q |    ****\n";
		}	
	}else if(Numero==65){
		if (Simbolo == "♥"){
			ss<<"****    | A |    *****\n";
		}else if (Simbolo == "♠"){
			ss<<"****    | A |     ****\n";
		}else if (Simbolo == "♣"){
			ss<<"**      | A |      ***\n";
		}else if (Simbolo == "♦"){
			ss<<"*****    | A |    ****\n";
		}	
	}else if(Numero==74){
		if (Simbolo == "♥"){
			ss<<"****    | K |    *****\n";
		}else if (Simbolo == "♠"){
			ss<<"****    | K |     ****\n";
		}else if (Simbolo == "♣"){
			ss<<"**      | K |      ***\n";
		}else if (Simbolo == "♦"){
			ss<<"*****    | K |    ****\n";
		}	
	}else if(Numero == 10){
		if (Simbolo == "♥"){
			ss<<"****    | "<<Numero<<"|    *****\n";
		}else if (Simbolo == "♠"){
			ss<<"****    | "<<Numero<<"|     ****\n";
		}else if (Simbolo == "♣"){
			ss<<"**      | "<<Numero<<"|      ***\n";
		}else if (Simbolo == "♦"){
			ss<<"*****    | "<<Numero<<"|    ****\n";
		}	
	}else{
		if (Simbolo == "♥"){
			ss<<"****    | "<<Numero<<" |    *****\n";
		}else if (Simbolo == "♠"){
			ss<<"****    | "<<Numero<<" |     ****\n";
		}else if (Simbolo == "♣"){
			ss<<"**      | "<<Numero<<" |      ***\n";
		}else if (Simbolo == "♦"){
			ss<<"*****    | "<<Numero<<" |    ****\n";
		}	
	}
	
	return ss.str();
}
