#include <iostream>
#include "Tablero.h"

int main()
{
	Tablero* tablero = new Tablero();
	tablero->llenarTablero();
	tablero->imprimirTablero();
	delete tablero;


	return 0;
}
