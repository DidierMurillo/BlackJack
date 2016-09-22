#include <string>
#include "Persona.h"
using std::string;
#include <sstream>
using std::stringstream;


Persona::Persona(string Nombre,string Edad,string ID):Nombre(Nombre),Edad(Edad),ID(ID){

}

Persona::~Persona(){

}

void Persona::setNombre(string Nombre){
	this->Nombre=Nombre;
}

void Persona::setEdad(string Edad){
	this->Edad=Edad;
}

void Persona::setID(string ID){
	this->ID=ID;
}

string Persona::toString(){
 	stringstream ss;
 	ss<<"Nombre:"<<Nombre<<" Edad:"<<Edad<<" ID:"<<ID;
 	return ss.str();
}

string Persona::getNombre(){
	return this->Nombre;
}

string Persona::getID(){
	return this->ID;
}

