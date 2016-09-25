#include "Persona.h"
#include "Administrador.h"
#include "Repartidor.h"
#include "Jugador.h"
#include "Baraja.h"
#include "Carta.h"
#include <curses.h>
#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void crearMapaCorazon(char ,int);
void crearMapaEspada(char ,int);
void crearMapaDiamante(char ,int);
void crearMapaTrebol(char ,int);
void imprimirCarta(int, char, char[20][27] = NULL);
void drawCards(string, string, int, int);
void cleanScreen();
int main(){

	initscr();
	start_color();
	char Opcion[1];
	char Opcion2[1];
	char Apuesta[1];
	char Nombre[20],Edad[13];
	char Lugar[20],Dificultad[20],Rango[20],Sueldo[10],Apodo[20];
	char ID[4];
	char Dinero[5];
	int ContadorCerdo;
	vector<Persona*> ListaPersonas;
	Jugador* TemporalJugador=new Jugador("Juana","18","1234","Mexico","La mera mera",15000);
	Repartidor* TemporalRepartidor=new Repartidor("Juanito","23","4321","Dificil");
	Administrador* Admi=new Administrador("Juanote","23","1234","Medio-Tiempo","80");
	ListaPersonas.push_back(TemporalJugador);
	ListaPersonas.push_back(Admi);
	
	mvprintw(0, 0, "Ingrese su Nombre:\n");
	getstr(Nombre);
	cleanScreen();
	mvprintw(1, 0, "Ingrese su ID:""\n");
	getstr(ID);
	for (int i = 0; i < ListaPersonas.size(); ++i)
	{	
		if (ListaPersonas.at(i) -> getNombre() == Nombre && ListaPersonas.at(i) -> getID() == ID)
		{
			if (dynamic_cast<Administrador*>(ListaPersonas.at(i)))
			{
				do
				{
					mvprintw(0, 0, "------Bienvenido Administrador------\n");
					mvprintw(1, 0, "1. Agregar un Nuevo Administrador\n");
					mvprintw(2, 0, "2. Agregar un Jugador \n");
					mvprintw(3, 0, "3. Agregar un Repartidor \n");	
					mvprintw(4, 0, "4. Salir \n");
					getstr(Opcion);
					cleanScreen();
					if (Opcion[0]=='1')
					{
						mvprintw(0, 0, "Ingrese el Nombre del nuevo Administrador:");
						getstr(Nombre);
						cleanScreen();
						mvprintw(0, 0, "Ingrese la Edad del nuevo Administrador:");
						getstr(Edad);
						cleanScreen();
						mvprintw(0, 0, "Ingrese el ID del nuevo Administrador:");
						getstr(ID);
						cleanScreen();
						mvprintw(0, 0, "Ingrese el Rango que tendra el nuevo Administrador:");
						getstr(Rango);
						cleanScreen();
						mvprintw(0, 0, "Ingrese el sueldo que tendra el nuevo Administrador:");
						getstr(Sueldo);
						cleanScreen;
						ListaPersonas.push_back(new Administrador(Nombre,Edad,ID,Rango,Sueldo));
						mvprintw(0, 0, "Felicidades, ha creado un nuevo Administrador");
					}else if(Opcion[0]=='2'){
						mvprintw(0, 0, "Ingrese el Nombre del nuevo Jugador:");
						getstr(Nombre);
						cleanScreen();
						mvprintw(0, 0, "Ingrese la Edad del nuevo Jugador:");
						getstr(Edad);
						cleanScreen();
						mvprintw(0, 0, "Ingrese el ID del nuevo Jugador:");
						getstr(ID);
						cleanScreen();
						mvprintw(0, 0, "Ingrese el Lugar de origen del nuevo Jugador:");
						getstr(Lugar);
						cleanScreen();
						mvprintw(0, 0, "Ingrese el Apodo que tendra el nuevo Jugador:");
						getstr(Apodo);
						cleanScreen();
						mvprintw(0, 0, "Ingrese el Dinero que trae el nuevo Jugador:");
						getstr(Dinero);
						cleanScreen();
						ListaPersonas.push_back(new Jugador(Nombre,Edad,ID,Lugar,Apodo,atoi(Dinero)));
						mvprintw(0, 0, "Felicidades, ha creado un nuevo Jugador");
					}else if(Opcion[0]=='3'){
						mvprintw(0, 0, "Ingrese el Nombre del nuevo Repartidor:");
						getstr(Nombre);
						cleanScreen();
						mvprintw(0, 0, "Ingrese la Edad del nuevo Repartidor:");
						getstr(Edad);
						cleanScreen();
						mvprintw(0, 0, "Ingrese el ID del nuevo Repartidor:");
						getstr(ID);
						cleanScreen();
						mvprintw(0, 0, "Ingrese la Dificultad que tendra el nuevo Repartidor:");
						getstr(Dificultad);
						cleanScreen();
						ListaPersonas.push_back(new Repartidor(Nombre,Edad,ID,Dificultad));
						mvprintw(0, 0, "Felicidades, ha creado un nuevo Repartidor");
					}
				} while (Opcion[0] != '4');
			}else if(dynamic_cast<Jugador*>(ListaPersonas.at(i))) {
				
				TemporalJugador = dynamic_cast<Jugador*>(ListaPersonas.at(i));
				do
				{
					mvprintw(0, 0, "1. Empezar un nuevo juego de BlackJack \n");
					mvprintw(1, 0, "2. Ver Dinero. \n");
					mvprintw(2, 0, "3. Salir \n");
					ContadorCerdo=1;
					getstr(Opcion);
					if (Opcion[0]=='1')
					{
						cleanScreen();
						for (int i = 0; i < 2; ++i)
						{
							TemporalJugador->setMano(TemporalRepartidor->Repartir());
							TemporalRepartidor->setMano(TemporalRepartidor->Repartir());
						}
						do {
							mvprintw(6, 0, "1. Ver Cartas\n");
							mvprintw(7, 0, "2. Pedir Carta\n");
							mvprintw(8, 0, "3. Mostrar Cartas\n");
							mvprintw(9, 0, "4. Rendirse \n");
							mvprintw(10, 0, "Ingrese su opcion: \n");
							getstr(Opcion2);
							cleanScreen();
							if(Opcion2[0]=='1'){
								int y = 1;
								if (TemporalJugador -> getHandSize() == 0)
								{
									cout << "Pida cartas primero! \n";
								} else {

									for (int i = 0; i < TemporalJugador->getHandSize(); ++i)
									{
										drawCards(TemporalJugador->getCarta(i)->toString(), TemporalJugador->getCarta(i)->getSimbolo(),12, y+(i*23));
									}
									
								}
							}else if(Opcion2[0]=='2') {
								TemporalJugador -> setMano(TemporalRepartidor -> Repartir());
								mvprintw(13, 0, "Se repartieron cartas.\n");
								/*if(TemporalRepartidor -> CalcularMano(0) <= 15){
									TemporalRepartidor -> setMano(TemporalRepartidor -> Repartir());	
								}*/
								ContadorCerdo++;
							}else if(Opcion2[0]=='3'){
								int y = 5;
								mvprintw(11, 1, "Cartas jugador:\n");
								mvprintw(26, 1, "Cartas Repartidor:\n");
								for (int i = 0; i < TemporalJugador->getHandSize(); ++i)
									{
										drawCards(TemporalJugador->getCarta(i)->toString(), TemporalJugador->getCarta(i)->getSimbolo(),12, y+(i*23));
									}
								for (int i = 0; i < TemporalRepartidor->getHandSize(); ++i)
								{
									drawCards(TemporalRepartidor->getCarta(i)->toString(), TemporalJugador->getCarta(i)->getSimbolo(),27, y+(i*23));
								}
								int Resul1, Resul2;
								Resul2 = TemporalRepartidor -> CalcularMano();
								Resul1 = TemporalJugador -> CalcularMano(ContadorCerdo);
								//mvprintw(12, 0, Resul1 << "\n" << Resul2 << "\n");
								if(Resul2 <= Resul1 && Resul1 <= 21 && Resul2 <= 21){
									mvprintw(11,17,"Felicidades, ha ganado este juego! \n");
									TemporalJugador -> setDinero((double)Apuesta[1] * 2);
								}else{
									mvprintw(11,17,"Ha perdido este juego! \n");
									TemporalJugador -> setDinero((double)Apuesta[1] * -1);
								}
							}
							TemporalRepartidor -> setBaraja();
							//cleanScreen();
						} while(Opcion2[0] != '4'&&Opcion2[0] != '3');		
					} else if(Opcion[0] == '2') {
						string playerData = TemporalJugador -> toString();
						mvprintw(15, 0, playerData.c_str());
						cleanScreen();
					}
				} while (Opcion[0]!='5');
			}
		} else {
			mvprintw(4, 0, "Usted no esta en el registro. \n");
		}
	}	
	getch();
	endwin();
}

void cleanScreen(){
	for (int i = 0; i < 300; i++){
		for (int j = 0; j <300; j++){
			mvprintw(i,j,"     .    ");
		}
	}
}


void drawCards(string numero, string simbolo, int posisionx, int posisiony){
	
	init_pair(1,COLOR_RED,COLOR_WHITE);
	init_pair(2,COLOR_BLACK,COLOR_WHITE);
	    
    if (simbolo == "♥"){
    	attron(COLOR_PAIR(1));
    	mvprintw(posisionx,posisiony,  "**********************\n");
    	mvprintw(posisionx+1,posisiony,"**********************\n");
    	mvprintw(posisionx+2,posisiony,"*****    ***    ******\n");
    	mvprintw(posisionx+3,posisiony,"****      *       ****\n");
    	mvprintw(posisionx+4,posisiony,"***                ***\n");
    	mvprintw(posisionx+5,posisiony,"***      ***      ****\n");
    	mvprintw(posisionx+6,posisiony,numero.c_str());
    	mvprintw(posisionx+7,posisiony,"*****    ***    ******\n");
    	mvprintw(posisionx+8,posisiony,"******         *******\n");
    	mvprintw(posisionx+9,posisiony,"*******       ********\n");
    	mvprintw(posisionx+10,posisiony,"********     *********\n");
    	mvprintw(posisionx+11,posisiony,"*********   **********\n");
    	mvprintw(posisionx+12,posisiony,"********** ***********\n");
    	mvprintw(posisionx+13,posisiony,"**********************\n");
    	attroff(COLOR_PAIR(1));
    }else if (simbolo == "♠"){
    	attron(COLOR_PAIR(2));
    	mvprintw(posisionx,posisiony,  "**********************\n");
    	mvprintw(posisionx+1,posisiony, "**********************\n");
    	mvprintw(posisionx+2,posisiony, "*********    *********\n");
    	mvprintw(posisionx+3,posisiony, "********      ********\n");
    	mvprintw(posisionx+4,posisiony, "*******        *******\n");
    	mvprintw(posisionx+5,posisiony, "******          ******\n");
    	mvprintw(posisionx+6,posisiony, "*****    ===     *****\n");
    	mvprintw(posisionx+7,posisiony, numero.c_str());
    	mvprintw(posisionx+8,posisiony, "***      ===       ***\n");
    	mvprintw(posisionx+9,posisiony, "**     **    **     **\n");
    	mvprintw(posisionx+10,posisiony,"**    **** ****     **\n");
    	mvprintw(posisionx+11,posisiony,"*********   **********\n");
    	mvprintw(posisionx+12,posisiony,"********     *********\n");
    	mvprintw(posisionx+13,posisiony,"**********************\n");
    	attroff(COLOR_PAIR(2));
    }else if (simbolo == "♣"){
    	attron(COLOR_PAIR(2));
    	mvprintw(posisionx,posisiony,   "**********************\n");
    	mvprintw(posisionx+1,posisiony, "**********************\n");
    	mvprintw(posisionx+2,posisiony, "*******       ********\n");
    	mvprintw(posisionx+3,posisiony, "******         *******\n");
    	mvprintw(posisionx+4,posisiony, "*******       ********\n");
    	mvprintw(posisionx+5,posisiony, "********     *********\n");
    	mvprintw(posisionx+6,posisiony, "***      ===      ****\n");
    	mvprintw(posisionx+7,posisiony, numero.c_str());
    	mvprintw(posisionx+8,posisiony, "**      *===*      ***\n");
    	mvprintw(posisionx+9,posisiony, "***   **    **    ****\n");
    	mvprintw(posisionx+10,posisiony,"*******      *********\n");
    	mvprintw(posisionx+11,posisiony,"******        ********\n");
    	mvprintw(posisionx+12,posisiony,"**********************\n");
    	mvprintw(posisionx+13,posisiony,"**********************\n");
    	attroff(COLOR_PAIR(2));
    } else if (simbolo == "♦"){
    	attron(COLOR_PAIR(1));
    	mvprintw(posisionx,posisiony,   "**********************\n");
    	mvprintw(posisionx+1,posisiony, "**********************\n");
    	mvprintw(posisionx+2,posisiony, "**********   *********\n");
    	mvprintw(posisionx+3,posisiony, "*********     ********\n");
    	mvprintw(posisionx+4,posisiony, "********       *******\n");
    	mvprintw(posisionx+5,posisiony, "*******         ******\n");
    	mvprintw(posisionx+6,posisiony, "******    ===    *****\n");
    	mvprintw(posisionx+7,posisiony, numero.c_str());
    	mvprintw(posisionx+8,posisiony, "******    ===    *****\n");
    	mvprintw(posisionx+9,posisiony, "*******         ******\n");
    	mvprintw(posisionx+10,posisiony,"********       *******\n");
    	mvprintw(posisionx+11,posisiony,"*********     ********\n");
    	mvprintw(posisionx+12,posisiony,"**********   *********\n");
    	mvprintw(posisionx+13,posisiony,"**********************\n");
    	attroff(COLOR_PAIR(1));
    }
}
