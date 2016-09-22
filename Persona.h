#include <string>
using std::string;

#pragma once

class Persona
{
private:
	string Nombre;
	string Edad;
	string ID;

public:
	Persona(string,string,string);
	~Persona();
	virtual string toString();
	void setNombre(string);
	void setEdad(string);
	void setID(string);
	string getNombre();
	string getID();
	
};