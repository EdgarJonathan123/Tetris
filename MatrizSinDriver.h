#ifndef MatrizSinDriver_H
#define MatrizSinDriver_H
#include "Arduino.h"


class MatrizSinDriver
{


public:



	MatrizSinDriver();

	//puertos
	void iniciarPuertos();
	void imprimirArreglo();

	//para pintar la variable
	void setRow(int fila,int coord);
	
	//es como el main para simular :v
	void menu();


private:


    int  ENTRADA=1;
	int  SALIDA = 0;
	int  UNO = 1;
	int  CERO = 0;
	//Puertos para la Matriz sin driver
	//-columnas
	int f0 = 22; int f1 = 24; int f2 = 26; int f3 = 28;
	int f4 = 30; int f5 = 32; int f6 = 34; int f7 = 36;

	//-filas
	int c0 = 23; int c1 = 25; int c2 = 27; int c3 = 29;
	int c4 = 31; int c5 = 33; int c6 = 35; int c7 = 37;

	int panatalla[8][8];


	void setRowPantalla(int fila,int coord, int tamanio);
	void initPort(int port, int state);
	void pintarPantalla();

	//para los pines
	void setPin(int port, int state);
	int getNumFila(int f);
	int getNumCol(int c);


};


#endif