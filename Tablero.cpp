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
		tablero[i] = NULL;
	}
	delete[] tablero;
	cout<<"Bai"<<endl;
	
}

void Tablero::llenarTablero()
{
	for(int i = 0; i < 11; i++)
        {
                for(int j = 0; j < 11; j++)
                {
                        if(i==0&&j==0)
                                this->tablero[i][j]==1;
                        else
                        {
                                if(i==0&&j==10)
                                        this->tablero[i][j]==2;
                                else
                                        this->tablero[i][j]==0;
                        }
                }
        }

}

void Tablero::imprimirTablero()
{
	for(int i = 0; i < 11; i++)
	{
		for(int j = 0; j < 11; j++)
		{
			if(tablero[i][j]==0)
				cout<<"[-]   ";
			else if(tablero[i][j]==1)
				cout<<"[+]   ";
			else if(tablero[i][j]==2)
				cout<<"[#]   ";
		}
		cout<<endl;
	}
}
