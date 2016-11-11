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

void Tablero::menu()
{
	int cont = 0;
	int op = 0;
	int direccion;
	int pieza = 0;
	int x = 0;
	int y = 0;
	do
	{
		imprimirTablero();
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
				if(moverPieza(x,y,pieza)!=0)
				{
					conversionPiezas(x,y,pieza);
					cont++;
				}

				if(espaciosA()==0)
				{
					cout<<"Jugador 2 gana"<<endl;
					op++;
				}

				if(espaciosB()==0)
				{
					cout<<"Jugador 1 gana"<<endl;
					op++;
				}

				if(espaciosVacios()==0)
				{
					if(espaciosA()>espaciosB())
						cout<<"Jugador 1 gana"<<endl;
					else if(espaciosB()>espaciosA())
						cout<<"Jugador 2 gana"<<endl;
					else if(espaciosA()==espaciosB())
						cout<<"Empate"<<endl;
					op++;
				}

			}
			else
				cout<<"Posición inválida."<<endl;
		}
		else
			cout<<"Se salió."<<endl;
	}while(op == 0);

}

int Tablero::moverPieza(int p1, int p2,int pieza)
{
	int cont = 0;
	int direccion = 0;
	int cuadros=0;
	cout<<"Escoja una dirección: "<<endl<<"1-Arriba"<<endl<<"2-Abajo"<<endl<<"3-Izquierda"<<endl<<"4-Derecha"<<endl<<"5-Diagonal arriba a la derecha"<<endl<<"6-Diagonal arriba a la izquierda"<<endl<<"7-Diagonal abajo a la izquierda"<<endl<<"8-Diagonal abajo a la derecha"<<endl;
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
					if(p1-1>-1&&tablero[p1-1][p2]==0)
					{
						tablero[p1-1][p2]=pieza;
						cont++;
					}
					else
						cout<<"Posición invalida."<<endl;
				}
				else
				{
					if(p1-2>-1&&(tablero[p1-2][p2]==0&&tablero[p1-1][p2]==0))
					{
						tablero[p1-2][p2]=pieza;
						cont++;
					}
					else
						cout<<"Posición invalida."<<endl;
				}
				break;
			}
			case 2:
			{
				if(cuadros==1)
				{
					if(p1+1<11&&tablero[p1+1][p2]==0)
					{
						tablero[p1+1][p2]=pieza;
						cont++;
					}
					else
						cout<<"Posición invalida."<<endl;
				}
				else
				{
					if(p1+2<11&&(tablero[p1+2][p2]==0&&tablero[p1+1][p2]==0))
					{
						tablero[p1+2][p2]=pieza;
						cont++;
					}
					else
						cout<<"Posición invalida."<<endl;
				}
				break;
			}
			case 3:
			{
				if(cuadros==1)
				{
					if(p2-1>-1&&tablero[p1][p2-1]==0)
					{
						tablero[p1][p2-1]=pieza;
						cont++;
					}
					else
						cout<<"Posición invalida."<<endl;
				}
				else
				{
					if(p2-2>-1&&(tablero[p1][p2-2]==0&&tablero[p1][p2-1]==0))
					{
						tablero[p1][p2-2]=pieza;
						cont++;
					}
					else
						cout<<"Posición invalida."<<endl;
				}
				break;
			}
                        case 4:
                        {
                                if(cuadros==1)
                                {
                                        if(p2+1<11&&tablero[p1][p2+1]==0)
                                        {
                                                tablero[p1][p2+1]=pieza;
                                                cont++;
                                        }
                                        else
                                                cout<<"Posición invalida."<<endl;
                                }
                                else
                                {
                                        if(p2+2<11&&(tablero[p1][p2+2]==0&&tablero[p1][p2+1]==0))
                                        {
                                                tablero[p1][p2+2]=pieza;
                                                cont++;
                                        }
                                        else
                                                cout<<"Posición invalida."<<endl;
                                }

                                break;
                        }
                        case 5:
                        {
				if(cuadros == 1)
				{
					if((p1+1<11&&p2+1<11)&&tablero[p1+1][p2+1]==0)
					{
						tablero[p1+1][p2+1]=pieza;
						cont++;
					}
					else
						cout<<"Posición invalida."<<endl;
				}
				else
				{
                                        if((p1+2<11&&p2+2<11)&&(tablero[p1+2][p2+2]==0&&tablero[p1+1][p2+1]))
                                        {
                                                tablero[p1+2][p2+2]=pieza;
                                                cont++;
                                        }
                                        else
                                                cout<<"Posición invalida."<<endl;

				}
                                break;
                        }
                        case 6:
                        {
                                if(cuadros == 1)
                                {
                                        if((p1+1<11&&p2-1>-1)&&tablero[p1+1][p2-1]==0)
                                        {
                                                tablero[p1+1][p2-1]=pieza;
                                                cont++;
                                        }
                                        else
                                                cout<<"Posición invalida."<<endl;
                                }
                                else
                                {
                                        if((p1+2<11&&p2-2>-1)&&(tablero[p1+2][p2-2]==0&&tablero[p1+1][p2-1]==0))
                                        {
                                                tablero[p1+2][p2+2]=pieza;
                                                cont++;
                                        }
                                        else
                                                cout<<"Posición invalida."<<endl;

                                }

                                break;
                        }
                        case 7:
                        {
                                if(cuadros == 1)
                                {
                                        if((p1-1>-1&&p2-1>-1)&&tablero[p1-1][p2-1]==0)
                                        {
                                                tablero[p1-1][p2-1]=pieza;
                                                cont++;
                                        }
                                        else
                                                cout<<"Posición invalida."<<endl;
                                }
                                else
                                {
                                        if((p1-2>-1&&p2-2>-1)&&tablero[p1-2][p2-2]==0)
                                        {
                                                tablero[p1-2][p2-2]=pieza;
                                                cont++;
                                        }
                                        else
                                                cout<<"Posición invalida."<<endl;

                                }

                                break;
                        }
                        case 8:
                        {
                                if(cuadros == 1)
                                {
                                        if((p1-1>-1&&p2+1<11)&&tablero[p1-1][p2+1]==0)
                                        {
                                                tablero[p1+1][p2+1]=pieza;
                                                cont++;
                                        }
                                        else
                                                cout<<"Posición invalida."<<endl;
                                }
                                else
                                {
                                        if((p1-2>-1&&p2+2<11)&&tablero[p1-2][p2+2]==0)
                                        {
                                                tablero[p1-2][p2+2]=pieza;
                                                cont++;
                                        }
                                        else
                                                cout<<"Posición invalida."<<endl;

                                }

                                break;
                        }
		}
	}
	return cont;
}

void Tablero::conversionPiezas(int p1, int p2, int pieza)
{
	int pieza2;

	if(pieza==1)
	{
		pieza2=2;
	}
	else
	{
		pieza2=1;
	}

	//Diagonal abajo, derecha
	if((p1+1<11&&p2+1<11)&&(tablero[p1+1][p2+1]==pieza2))
		tablero[p1+1][p2+1]=pieza;
	
	//Diagonal abajo, izquierda
	if((p1+1<11&&p2-1>-1)&&(tablero[p1+1][p2-1]==pieza2))
                tablero[p1+1][p2-1]=pieza;
	
	//Diagonal arriba, izquierda
	if((p1-1>-1&&p2-1>-1)&&(tablero[p1-1][p2-1]==pieza2))
                tablero[p1-1][p2-1]=pieza;
	
	//Diagonal arriba, derecha
	if((p1-1>-1&&p2+1<11)&&(tablero[p1-1][p2+1]==pieza2))
                tablero[p1-1][p2+1]=pieza;

	//Derecha
	if(p2+1<11&&tablero[p1][p2+1]==pieza2)
		tablero[p1+1][p2+1]=pieza;
	
	//Abajo
	if(p2+1<11&&tablero[p1][p2+1]==pieza2)
                tablero[p1+1][p2]=pieza;
	
	//Arriba
	if(p1-1>-1&&tablero[p1-1][p2]==pieza2)
                tablero[p1-1][p2]=pieza;
	
	//Izquierda
	if(p2-1>-1&&tablero[p1][p2-1]==pieza2)
                tablero[p1][p2-1]=pieza;


}

void Tablero::llenarTablero()
{
	tablero[0][0]=1;
	tablero[10][10]=1;
	tablero[0][10]=2;
	tablero[10][0]=2;
	cout<<"BOOP"<<endl;
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

int Tablero::espaciosVacios()
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

int Tablero::espaciosA()
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

int Tablero::espaciosB()
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

