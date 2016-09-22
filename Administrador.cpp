#include "Administrador.h"
#include "Persona.h"
#include <string>
using std::string;
#include <sstream>
using std::stringstream;


Administrador::Administrador(string Nombre,string Edad,string ID,string RangoAdministrador,string ExperienciaLaboral,string Sueldo):
Persona(Nombre,Edad,ID),RangoAdministrador(RangoAdministrador),ExperienciaLaboral(ExperienciaLaboral),Sueldo(Sueldo){

}

Administrador::~Administrador(){

}

void Administrador::setSueldo(string Sueldo){
	this->Sueldo=Sueldo;
}

void Administrador::setExperienciaLaboral(string ExperienciaLaboral){
	this->ExperienciaLaboral=ExperienciaLaboral;
}

void Administrador::setRangoAdministrador(string RangoAdministrador){
	this->RangoAdministrador=RangoAdministrador;
}

string Administrador::toString(){
	stringstream ss;
	ss<<Persona::toString()<<" Rango Administrador:"<<RangoAdministrador<<" ExperienciaLaboral: "<<ExperienciaLaboral<<" Sueldo :"<<Sueldo;
}