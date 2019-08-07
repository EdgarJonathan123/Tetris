#include "Variable.h"
Variable::Variable()
{
	Pantalla = new int[16];
	for (int i = 0; i < 16; i++)
		Pantalla[i]=0;

		//defecto();
		//imprimir();

}

void Variable::defecto() {
	for (int i = 0; i < 16; i++)
	{
		if (i%2==0) {
			Pantalla[i] = 4;
		}
		else {
			Pantalla[i] = 4;
		}
	}
}

void Variable::imprimir(){
/*
for (int i = 0; i < 16; i++)
{

	Serial.Print(Pantalla[i]);
	Serial.Print(",");
}
*/

}