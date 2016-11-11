#ifndef TABLERO_H
#define TABLERO_H

using namespace std;

class Tablero
{
	private:
		int** tablero;		


	public:
		Tablero();
		void llenarTablero();
		void imprimirTablero();
		int espaciosVacios();
		int espaciosA();
		int espaciosB();
		void moverPieza();

		~Tablero();


};

#endif
