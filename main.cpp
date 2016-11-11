#include <iostream>
#include "Tablero.h"

int main()
{
	Tablero* tablero = new Tablero();
	tablero->llenarTablero();
	tablero->menu();
	delete tablero;


	return 0;
}
