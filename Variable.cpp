#include "Variable.h"
Variable::Variable()
{
	Pantalla = new int[16];
	for (int i = 0; i < 16; i++)
		Pantalla[i]=0;

		defecto();
		//imprimir();

}

void Variable::defecto() {


	for (int i = 0; i < 16; i++)
	{
		if(i<8){
			Pantalla[i]=4;
		}else if(i>7&&i<11){
			Pantalla[i]=1;
		}else if(i>10 && i<16){
			Pantalla[i]=128;
		}
	}
}

void Variable::imprimir(){



}