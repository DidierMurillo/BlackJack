#include "Persona.h"
#include "Administrador.h"
#include "Repartidor.h"
#include "Jugador.h"
#include "Baraja.h"
#include "Carta.h"
#include <curses.h>
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
	Jugador* TemporalJugador=new Jugador("Juana","18","1234","Mexico","La mera mera",15000);
	Repartidor* TemporalRepartidor=new Repartidor("Juanito","23","4321","Dificil",0,1000);
	do
	{
		mvprintw(6,111,"1. Throwing dice\n");
		do
		{
			mvprintw(4,111,"1-Empezar un nuevo juego de BlackJack\n2-Ver Dinero\n3-Salir");
			getstr(Opcion);
			if (Opcion[0]=='1')
			{
				mvprintw(5,111,"Ingrese su apuesta para este juego:");
				getstr(Apuesta);
			for (int i = 0; i < 2; ++i)
			{
				TemporalJugador->setMano(TemporalRepartidor->Repartir());
				TemporalRepartidor->setMano(TemporalRepartidor->Repartir());
			}	
			do{
				mvprintw(6,111,"1-Ver Cartas\n2-Pedir Carta\n3-Mostrar Cartas\nIngrese su opcion:");
				getstr(Opcion);
				cleanScreen();
				if(Opcion[0]=='1'){
					//mvprintw(7,111,TemporalJugador->verMano());
					//mvprintw(8,111,TemporalRepartidor->verMano());
				}else if(Opcion[0]=='2'){
					TemporalJugador->setMano(TemporalRepartidor->Repartir());
				if(TemporalRepartidor->CalcularMano(0)<=15){
					TemporalRepartidor->setMano(TemporalRepartidor->Repartir());	
				}
				}else if(Opcion[0]=='3'){
					//mvprintw(7,111,TemporalJugador->verMano());
					//mvprintw(8,111,TemporalRepartidor->verMano());
					int Resul1,Resul2;
					Resul2=TemporalRepartidor->CalcularMano();
					Resul1=TemporalJugador->CalcularMano();
					//mvprintw(9,111,Resul1<<"\n"<<Resul2<<"\n");
					if(Resul2<=Resul1&&Resul1<=21&&Resul2<=21){
						mvprintw(10,111,"Felicidaddes Haz Ganado este Juego!");
						TemporalJugador->setDinero(Apuesta[1]*2);
					}else{
						mvprintw(10,11,"Haz Perdido este Juego!");
						TemporalJugador->setDinero(Apuesta[1]*-1);
					}
				}
				TemporalRepartidor->setBaraja();
		}while(Opcion[0]=='3');		
			}else if(Opcion[0]=='2'){
				TemporalJugador->toString();
			} 
	} while (Opcion[0]!='3');
		getch();
	} while (Opcion[0]!=1);

	endwin();
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
