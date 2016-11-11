#ifndef TABLERO_H
#define TABLERO_H

using namespace std;

class Tablero
{
	private:
		int** tablero;		


	public:
		Tablero();
		void menu();
		void llenarTablero();
		void imprimirTablero();
		int espaciosVacios();
		int espaciosA();
		int espaciosB();
		int moverPieza(int,int,int);
		void conversionPiezas(int,int,int);

		~Tablero();


};

#endif
