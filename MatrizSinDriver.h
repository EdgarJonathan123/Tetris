#ifndef MatrizSinDriver_H
#define MatrizSinDriver_H

#include "Arduino.h"

#include "VARIABLE.h"


class MatrizSinDriver
{

public:

	MatrizSinDriver();

	//puertos
	void iniciarPuertos();
	void imprimirArreglo();

	//para pintar la variable
	void setRow(int fila, int coord);

	void setMatriz(Variable* &var);

	//es como el main para simular :v
	void menu();


private:

	int  ENTRADA = 1;
	int  SALIDA = 0;
	int  UNO = 1;
	int  CERO = 0;

	//Puertos para la Matriz sin driver
	//-filas
	int f0 = 22; int f1 = 24; int f2 = 26; int f3 = 28;
	int f4 = 30; int f5 = 32; int f6 = 34; int f7 = 36;

	//-columnaas
	int c7 = 23; int c6 = 25; int c5 = 27; int c4 = 29;
	int c3 = 31; int c2 = 33; int c1 = 35; int c0 = 37;

	Variable* var;
	int linea[8] ={0,0,0,0,0,0,0,0};


	void setRowPantalla(int coord);
	void initPort(int port, int state);
	void pintarPantalla();

	//para los pines
	void setPin(int port, int state);
	int getNumFila(int f);
	int getNumCol(int c);


};


#endif