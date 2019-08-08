#include "MatrizSinDriver.h"

#include "MatrizSinDriver.h"

MatrizSinDriver::MatrizSinDriver()
{
	var = nullptr;
}

void MatrizSinDriver::imprimirArreglo()
{

	//cout << "\n-------------actualizacion-----------\n";
	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			//int num = panatalla[i][j];
			//cout << "[" << num << "]";
		}
		//cout << "\n";
	}
}

void MatrizSinDriver::iniciarPuertos()
{

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

	setPin(f0, UNO);
	setPin(f1, UNO);
	setPin(f2, UNO);
	setPin(f3, UNO);
	setPin(f4, UNO);
	setPin(f5, UNO);
	setPin(f6, UNO);
	setPin(f7, UNO);

	setPin(c0, CERO);
	setPin(c1, CERO);
	setPin(c2, CERO);
	setPin(c3, CERO);
	setPin(c4, CERO);
	setPin(c5, CERO);
	setPin(c6, CERO);
	setPin(c7, CERO);
}

void MatrizSinDriver::initPort(int port, int state)
{

	if (state == ENTRADA)
	{
		pinMode(port, INPUT);
	}
	else if (state == SALIDA)
	{
		pinMode(port, OUTPUT);
	}
}

void MatrizSinDriver::setPin(int port, int state)
{

	if (state == UNO)
	{
		digitalWrite(port, HIGH);
	}
	else if (state == CERO)
	{
		digitalWrite(port, LOW);
	}
}

void MatrizSinDriver::pintarPantalla()
{

	for (size_t i = 8; i < 16; i++)
	{
		setRowPantalla(var->Pantalla[i]);
		for (size_t j = 0; j < 8; j++)
		{
			//Serial.print(linea[j]);
			//Serial.print(",");
			switch (linea[j])
			{
			case 1:
				setPin(getNumCol(j), UNO);
				break;
			case 0:
				setPin(getNumCol(j), CERO);
				break;
			}
		}
		//Serial.print("\n");
		setPin(getNumFila(i), CERO);
		delay(6);
		setPin(getNumFila(i), UNO);
	}
}

void MatrizSinDriver::setRow(int fila, int coord)
{

	//imprimirArreglo();
	//int tamanio = 8;
	//setRowPantalla(fila, coord, tamanio);
	pintarPantalla();
}

void MatrizSinDriver::setRowPantalla(int coord)
{

	for (size_t i = 0; i < 8; i++)
	{
		linea[i]=0;
	}
	

		
	int col = 0;
	int divs = 2;	 //Este sera nuestro divisor
	int divd = coord; //Este nuestro dividendo
	int cociente = -1;
	int resid = -1;

	while (cociente != 0)
	{
		cociente = divd / divs; //Aqui realizamos la operacion de la división
		resid = divd % divs;	//Y aqui determinamos el modulo

		linea[col] = resid;

		divd = cociente;
		col++;
	}
}

void MatrizSinDriver::menu()
{

	/*
	setRow(0, 85);
	setRow(1, 4);
	setRow(2, 255);
	setRow(4, 15);
	*/

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

	system("pause");
	*/
}

int MatrizSinDriver::getNumFila(int f)
{
	switch (f)
	{
	case 8:
		return f0;
		break;
	case 9:
		return f1;
		break;
	case 10:
		return f2;
		;
		break;
	case 11:
		return f3;
		break;
	case 12:
		return f4;
		break;
	case 13:
		return f5;
		break;
	case 14:
		return f6;
		break;
	case 15:
		return f7;
		break;
	}

	return 0;
}

int MatrizSinDriver::getNumCol(int c)
{

	switch (c)
	{
	case 0:
		return c0;
		break;
	case 1:
		return c1;
		break;
	case 2:
		return c2;
		break;
	case 3:
		return c3;
		break;
	case 4:
		return c4;
		break;
	case 5:
		return c5;
		break;
	case 6:
		return c6;
		break;
	case 7:
		return c7;
		break;
	}

	return 0;
}

void MatrizSinDriver::setMatriz(Variable* &_var)
{
	var = _var;
	pintarPantalla();
}