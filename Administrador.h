#include "Persona.h"
#include <string>
using std::string;
#pragma once

class Administrador:public Persona
{
private:
	string RangoAdministrador;
	string ExperienciaLaboral;
	string Sueldo;

public:
	Administrador(string,string,string,string,string,string);
	~Administrador();
	void setRangoAdministrador(string);
	void setExperienciaLaboral(string);
	void setSueldo(string);
	string toString();

};