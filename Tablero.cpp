#include <iostream>
#include "Tablero.h"

Tablero::Tablero()
{
	this->tablero = new int*[11];
	for(int i = 0; i < 11; i++)
	{
		this->tablero[i] = new int[11];
	}
}

Tablero::~Tablero()
{
	cout<<"Borrando tablero."<<endl;
	for(int i = 0; i < 11; i++)
	{
		delete[] tablero[i];
		this->tablero[i] = NULL;
	}
	delete[] this->tablero;
	cout<<"Bai"<<endl;
	
}

void menu()
{
	int cont = 0;
	int op = 0;
	int direccion;
	int pieza = 0;
	int x = 0;
	int y = 0;
	do
	{
		
		if(cont%2==0)
			pieza = 1;
		else
			pieza = 2;

		cout<<"Jugador "<<pieza<<" ingrese coordenadas de la pieza que quiere mover: "<<endl;
		cout<<"X: ";
		cin>>x;
		cout<<"Y: ";
		cin>>y;
		if((x<11&&x>-1)&&(y<11&&y>-1))
		{
			if(tablero[x][y]==pieza)
			{
				
			}
			else
				cout<<"Posición inválida."<<endl;
		}
		else
			cout<<"Se salió."<<endl;
	}while(op == 0);

}

void moverPieza(int p1, int p2)
{
	int direccion = 0;
	int cuadros=0;
	cout<<"Escoja una dirección: "<<endl<<"1-Arriba"<<endl<<"2-Abajo"<<endl<<"3-Izquierda"<<endl<<"4-Derecha"<<endl<<"5-Diagonal arriba a la derecha"<<endl<<"6-Diagonal arriba a la izquierda"<<endl<<"7-Diagonal abajo a la izquierda"<<endl<<"8-Diagonal abajo a la derecha";
	cin>>direccion;
	cout<<"Escoja la cantidad de cuadros que se va a mover: ";
	cin>>cuadros;
	if((direccion <1||direccion>8)||(cuadros>2||cuadros<1))
		cout<<"Invalido"<<endl;
	else
	{
		switch(direccion)
		{
			case 1:
			{
				if(cuadros==1)
				{
					if(y+1<11)
						tablero[x][y+1]=pieza;
					else
						cout<<"Posición invalida."<<endl;
				}
				else
				{
					if(y+2<11)
						tablero[x][y+2]=pieza;
					else
						cout<<"Posición invalida."<<endl;
				}
				break;
			}
			case 2:
			{
				break;
			}
			case 3:
			{
				break;
			}
                        case 4:
                        {
                                break;
                        }
                        case 5:
                        {
                                break;
                        }
                        case 6:
                        {
                                break;
                        }
                        case 7:
                        {
                                break;
                        }
                        case 8:
                        {
                                break;
                        }
		}
	}
}

int validarMovimiento(int x, int y)
{
	int validacion=0;
	if(x==2||y==2)
	return validacion;
}

void Tablero::llenarTablero()
{
	tablero[0][0]=1;
	tablero[10][10]=1;
	tablero[0][10]=2;
	tablero[10][0]=2;
}

void Tablero::imprimirTablero()
{
	for(int i = 0; i < 11; i++)
	{
		for(int j = 0; j < 11; j++)
		{
			if(tablero[i][j]==0)
				cout<<"-   ";
			else if(tablero[i][j]==1)
				cout<<"+   ";
			else if(tablero[i][j]==2)
				cout<<"#   ";
		}
		cout<<endl;
	}
}

int espaciosVacios()
{
	int count=0;
	for(int i = 0; i < 11; i++)
        {
                for(int j = 0; j < 11; j++)
                {
                        if(tablero[i][j]==0)
				count++;
                }
        }
	return count;

}

int espaciosA()
{
        int count=0;
        for(int i = 0; i < 11; i++)
        {
                for(int j = 0; j < 11; j++)
                {
                        if(tablero[i][j]==1)
                                count++;
                }
        }
        return count;

}

int espaciosB()
{
        int count=0;
        for(int i = 0; i < 11; i++)
        {
                for(int j = 0; j < 11; j++)
                {
                        if(tablero[i][j]==2)
                                count++;
                }
        }
        return count;

}

