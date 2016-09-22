Casino: Main.o Persona.o Baraja.o Carta.o Repartidor.o Administrador.o Jugador.o 
	g++ Main.o Persona.o Baraja.o Carta.o Repartidor.o Administrador.o Jugador.o  -o Casino

Main.o:		Main.cpp Persona.h Baraja.h Carta.h Repartidor.h Administrador.h Jugador.h 
	g++ -c Main.cpp

Persona.o:	Persona.cpp Persona.h
	g++ -c Persona.cpp

Repartidor.o:	Repartidor.h Persona.h Repartidor.cpp
	g++ -c Repartidor.cpp

Administrador.o:	Administrador.h Persona.h Administrador.cpp
	g++ -c Administrador.cpp

Jugador.o:	Jugador.h Persona.h Jugador.cpp
	g++ -c Jugador.cpp

Baraja.o:	Baraja.h Baraja.cpp
	g++ -c Baraja.cpp

Carta.o:	Carta.h Carta.cpp
	g++ -c Carta.cpp

clean:
	rm *.o Casino


