#include "MatrizSinDriver.h"

MatrizSinDriver::MatrizSinDriver()
{

}

void MatrizSinDriver::imprimirArreglo(int* matriz, int n) {

	for (int j = 0; j < n; ++j, ++matriz) {
//		int lol = *matriz;
	//	cout << lol << '\t';
	}
//	cout << '\n';

}

void MatrizSinDriver::iniciarPuertos() {

		initPort(f0, SALIDA);
	initPort(f1, SALIDA);
	initPort(f2, SALIDA);
	initPort(f3, SALIDA);
	initPort(f4, SALIDA);
	initPort(f5, SALIDA);
	initPort(f6, SALIDA);
	initPort(f7, SALIDA);

	initPort(c0, SALIDA);
	initPort(c1, SALIDA);
	initPort(c2, SALIDA);
	initPort(c3, SALIDA);
	initPort(c4, SALIDA);
	initPort(c5, SALIDA);
	initPort(c6, SALIDA);
	initPort(c7, SALIDA);

	setPin(f0, CERO);
	setPin(f1, CERO);
	setPin(f2, CERO);
	setPin(f3, CERO);
	setPin(f4, CERO);
	setPin(f5, CERO);
	setPin(f6, CERO);
	setPin(f7, CERO);

	setPin(c0, UNO);
	setPin(c1, UNO);
	setPin(c2, UNO);
	setPin(c3, UNO);
	setPin(c4, UNO);
	setPin(c5, UNO);
	setPin(c6, UNO);
	setPin(c7, UNO);


}

void MatrizSinDriver::initPort(int port, int state) {
	if (state == ENTRADA) {
		pinMode(port, INPUT);
	}
	else if (state == SALIDA) {
		pinMode(port, OUTPUT);
	}
}

void MatrizSinDriver::setPin(int port, int state) {

	if (state == UNO) {
		digitalWrite(port, HIGH);
	}
	else if (state == CERO) {
		digitalWrite(port, LOW);
	}
}

void  MatrizSinDriver::setRow(int fila, int coord) {

	int tamanio = 8;
	int* Fila = new int[tamanio];
	Fila = getRow(coord, tamanio);

	for (int i = 0; i < tamanio; i++) {
			if (Fila[i] == UNO) {
				setPin(getNumCol(i), CERO);
			}
			else if (Fila[i] == CERO) {
				setPin(getNumCol(i), UNO);
			}

		}

	for (size_t h = 0; h < 20; h++)
	{

		setPin(getNumFila(fila), CERO);
		// delay(100);
		setPin(getNumFila(fila), UNO);
	    //delay(100);
		setPin(getNumFila(fila), CERO);
	
	}



	delete[] Fila;
}


int* MatrizSinDriver::getRow(int coord, int tamanio) {

	int* linea = new int[tamanio];

	for (int j = 0; j < tamanio; j++)
		linea[j] = 0;

	int i = 0;
	int divs = 2;                  //Este sera nuestro divisor
	int divd = coord;              //Este nuestro dividendo
	int cociente = -1;
	int resid = -1;

	while (cociente != 0) {
		cociente = divd / divs;    //Aqui realizamos la operacion de la división
		resid = divd % divs;       //Y aqui determinamos el modulo

		linea[i] = resid;

		divd = cociente;
		i++;
	}

	return linea;
}

void MatrizSinDriver::menu() {

	/*	int tamanio = 16;
		int* matriz = new int[tamanio];

		matriz[0] = 0;
		matriz[1] = 0;
		matriz[2] = 0;
		matriz[3] = 0;
		matriz[4] = 1;
		matriz[5] = 0;
		matriz[6] = 0;
		matriz[7] = 0;
		matriz[8] = 0;
		matriz[9] = 0;
		matriz[10] = 0;
		matriz[11] = 0;
		matriz[12] = 0;
		matriz[13] = 0;
		matriz[14] = 0;
		matriz[15] = 0;

		imprimirArreglo(matriz, tamanio);
		delete[] matriz;
	

	int tamanio = 8;
	imprimirArreglo(getRow(2, tamanio), tamanio);
	*/



	system("pause");

}



int MatrizSinDriver::getNumFila(int f) {
	int result = 0;
	switch (f)
	{
	case 0:
		result = f0;
		break;
	case 1:
		result = f1;
		break;
	case 2:
		result = f2;
		break;
	case 3:
		result = f3;
		break;
	case 4:
		result = f4;
		break;
	case 5:
		result = f5;
		break;
	case 6:
		result = f6;
		break;
	case 7:
		result = f7;
		break;
	}

	return result;
}


int MatrizSinDriver::getNumCol(int c) {
	int result = 0;
	switch (c)
	{
	case 0:
		result = c0;
		break;
	case 1:
		result = c1;
		break;
	case 2:
		result = c2;
		break;
	case 3:
		result = c3;
		break;
	case 4:
		result = c4;
		break;
	case 5:
		result = c5;
		break;
	case 6:
		result = c6;
		break;
	case 7:
		result = c7;
		break;
	}

	return result;
}