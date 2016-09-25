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

void cleanScreen();
int main(){

	initscr();
	start_color();
	char Opcion[1];
	char Apuesta[1];
	char Nombre[20],Edad[13];
	char Lugar[20],Dificultad[20],Rango[20],Sueldo[10],Apodo[20];
	char ID[4];
	char Dinero[5];
	vector<Persona*> ListaPersonas;
	Jugador* TemporalJugador=new Jugador("Juana","18","1234","Mexico","La mera mera",15000);
	Repartidor* TemporalRepartidor=new Repartidor("Juanito","23","4321","Dificil");
	Administrador* Admi=new Administrador("Juanote","23","1234","Medio-Tiempo","80");
	ListaPersonas.push_back(TemporalJugador);
	ListaPersonas.push_back(Admi);
	do
	{
		mvprintw(0, 0, "Ingrese su Nombre:\n");
		getstr(Nombre);
		cleanScreen();
		mvprintw(1, 0, "Ingrese su ID:""\n");
		getstr(ID);
		for (int i = 0; i < ListaPersonas.size(); ++i)
		{	
			if (ListaPersonas.at(i)->getNombre()==Nombre&&ListaPersonas.at(i)->getID()==ID)
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
							mvprintw(0, 0, "Felicidaddes a creado un nuevo Administrador");
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
							mvprintw(0, 0, "Ingrese el Lugar de donde vino el nuevo Jugador:");
							getstr(Lugar);
							cleanScreen();
							mvprintw(0, 0, "Ingrese el Apodo que tendra el nuevo Jugador:");
							getstr(Apodo);
							cleanScreen();
							mvprintw(0, 0, "Ingrese el Dinero que trae el nuevo Jugador:");
							getstr(Dinero);
							cleanScreen();
							ListaPersonas.push_back(new Jugador(Nombre,Edad,ID,Lugar,Apodo,atoi(Dinero)));
							mvprintw(0, 0, "Felicidaddes a creado un nuevo Jugador");
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
							mvprintw(0, 0, "Felicidaddes a creado un nuevo Repartidor");
						}
					} while (Opcion[0]!='4');		
				}else if(dynamic_cast<Jugador*>(ListaPersonas.at(i))){
					TemporalJugador=dynamic_cast<Jugador*>(ListaPersonas.at(i));
					do
					{
						mvprintw(0, 0, "1. Empezar un nuevo juego de BlackJack \n");
						mvprintw(1, 0, "2. Ver Dinero. \n");
						mvprintw(2, 0, "4. Salir \n");
						getstr(Opcion);
						if (Opcion[0]=='1')
						{
							mvprintw(4, 0,"Ingrese su apuesta para este juego: \n");
							getstr(Apuesta);
						for (int i = 0; i < 2; ++i)
						{
							TemporalJugador->setMano(TemporalRepartidor->Repartir());
							TemporalRepartidor->setMano(TemporalRepartidor->Repartir());
						}	
						do{
							mvprintw(6, 0, "1. Ver Cartas\n");
							mvprintw(7, 0, "2. Pedir Carta\n");
							mvprintw(8, 0, "3. Mostrar Cartas\n");
							mvprintw(9, 0, "Ingrese su opcion: \n");
							getstr(Opcion);
							cleanScreen();
							if(Opcion[0]=='1'){
								mvprintw(10, 0, TemporalJugador->verMano().c_str());
								mvprintw(11, 0, TemporalJugador->verMano().c_str());
							}else if(Opcion[0]=='2'){
								TemporalJugador -> setMano(TemporalRepartidor -> Repartir());
								mvprintw(9, 0, "Algo paso. \n");
							if(TemporalRepartidor -> CalcularMano(0) <= 15){
								TemporalRepartidor -> setMano(TemporalRepartidor -> Repartir());	
							}
							}else if(Opcion[0]=='3'){
								mvprintw(10, 0, TemporalJugador->verMano().c_str());
								mvprintw(11, 0, TemporalJugador->verMano().c_str());
								cleanScreen();
								int Resul1, Resul2;
								Resul2 = TemporalRepartidor -> CalcularMano();
								Resul1 = TemporalJugador -> CalcularMano();
								//mvprintw(12, 0, Resul1 << "\n" << Resul2 << "\n");
								if(Resul2 <= Resul1 && Resul1 <= 21 && Resul2 <= 21){
									mvprintw(10,111,"Felicidaddes Haz Ganado este Juego! \n");
									TemporalJugador -> setDinero(Apuesta[1] * 2);
								}else{
									mvprintw(10,11,"Haz Perdido este Juego! \n");
									TemporalJugador -> setDinero(Apuesta[1] * -1);
								}
							}
							TemporalRepartidor -> setBaraja();
					} while(Opcion[0]!='3');	
						cleanScreen();	
						} else if(Opcion[0]=='2'){
							TemporalJugador->toString();
						}
					} while (Opcion[0]!='4');
					cleanScreen();
				}
			}	
		}	
		getch();
		endwin();
	}while(true==true);	
}

void cleanScreen(){
	for (int i = 0; i < 300; i++){
		for (int j = 0; j <300; j++){
			mvprintw(i,j,"     .    ");
		}
	}
}

void crearMapaCorazon(char numeroCarta, int posicion){
	char corazon[20][27] = {
		"--------------------------",
		"-|     |----------|     |-",
		"-|  N  |----------|  N  |-",
		"-|     |----------|     |-",	
		"--------------------------",
		"----       ---      ------",
		"---         -         ----",
		"--                     ---",
		"--         ---        ----",
		"---       | N |      -----",
		"----       ---      ------",
		"-----              -------",
		"------            --------",
		"-------          ---------",
		"--------        ----------",
		"---------      -----------",
		"-|     |--    ----|     |-",
		"-|  N  |---  -----|  N  |-",
		"-|     |----------|     |-",
		"--------------------------"
	};
	attrset (COLOR_PAIR(1));
	imprimirCarta(posicion, numeroCarta, corazon);
}
void crearMapaEspada(char numeroCarta, int posicion){
	char palo[20][27] = {
		"**************************",
		"*     *------------*     *",
		"*  N  *------------*  N  *",
		"*     *---     ----*     *",
		"*******--       ---*******",
		"*-------         --------*",
		"*------           -------*",
		"*-----             ------*",
		"*----      ===      -----*",
		"*---      | N |      ----*",
		"*--        ===        ---*",
		"*-      --     --      --*",
		"*-     ----  ----      --*",
		"*---------    -----------*",	
		"*--------      ----------*",
		"*******------------*******",
		"*     *------------*     *",
		"*  N  *------------*  N  *",
		"*     *------------*     *",
		"**************************"
		// "-------------------------"
	};
	attrset (COLOR_PAIR(2));
	imprimirCarta(posicion, numeroCarta, palo);
}
void crearMapaTrebol(char numeroCarta, int posicion){
	char palo[20][27] = {
		"**************************",
		"*     *------------*     *",
		"*  N  *------------*  N  *",
		"*     *-          -*     *",
		"*******            *******",
		"*------           -------*",
		"*-------         --------*",
		"*---------      ---------*",
		"*---        ===       ---*",
		"*--        | N |       --*",
		"*--        -===-       --*",
		"*---     --    --     ---*",
		"*---------      ---------*",
		"*--------        --------*",	
		"*-------          -------*",
		"*******------------*******",
		"*     *------------*     *",
		"*  N  *------------*  N  *",
		"*     *------------*     *",
		"**************************"
		// "-------------------------"
	};
	attrset (COLOR_PAIR(2));
	imprimirCarta(posicion, numeroCarta, palo);
}
void crearMapaDiamante(char numeroCarta, int posicion){
	char diamante[20][27] = {
		"**************************",
		"*     *------------*     *",
		"*  N  *----   -----*  N  *",
		"*     *---     ----*     *",
		"*******--       ---*******",
		"*-------         --------*",
		"*------           -------*",
		"*-----      ===    ------*",
		"*-----     | N |    -----*",
		"*------     ===    ------*",
		"*-------          -------*",
		"*--------        --------*",
		"*---------      ---------*",
		"*----------    ----------*",	
		"*-----------  -----------*",
		"*******------------*******",
		"*     *------------*     *",
		"*  N  *------------*  N  *",
		"*     *------------*     *",
		"**************************"
		// "-------------------------"
	};
	attrset (COLOR_PAIR(1));
	imprimirCarta(posicion, numeroCarta, diamante);
}

void imprimirCarta(int posicion, char numeroCarta, char mapa[20][27]){
	for(int i = 0; i < 20; i++){
		for(int j = 0; j < 27; j++){
			if((i == 0 || i == 4) && j < 26){
				move(i + 8,j + 15 + (27 * posicion));
				printw("-");
			}
			if((j == 0 || j == 25) && (i >0 && i < 4)){
				move(i + 8,j + 15 + (27 * posicion));
				printw("|");	
			}
			if(i == 2 && j == 12){
				move(i + 8,j + 15 + (27 * posicion));
				printw("%d", posicion + 1);					
			}
			move(i + 13,j + 15 + (27 * posicion));
			if(mapa == NULL){
				if(j % 2 == 0){
					printw("|");
				}else{
					printw("-");
				}
			}else{
				if(mapa[i][j] == 'N'){
					if(numeroCarta == 'D'){
						move(i + 13,j + 14 + (27 * posicion));
						// j++;
						printw("10");
					}else{
						printw("%c", numeroCarta);
					}
				}else{
					printw("%c", mapa[i][j]);
				}
			}
		}
		// printw(" | ");
	}
}
