#include <mensajeInicial.h>


//#include <MatrizSinDriver.h>


//creacion de objetos
mensajeinicial bienvenida= mensajeinicial();
 MatrizSinDriver matriz = MatrizSinDriver();
 Variable* var = new  Variable();



void setup() {
  bienvenida.inicializar();
  Serial.begin(9600);
  matriz.iniciarPuertos();
  
}

void loop() {

  bienvenida.actualizarMatriz();
  matriz.setMatriz(var);
	 Serial.begin(9600);

Serial.print("\n");
for (int i  = 0; i < 16; i++)
{
	Serial.print(var->Pantalla[i]);
	Serial.print(",");
}

 var->Pantalla[13]=16;
 var->Pantalla[14]=16;
  var->Pantalla[15]=16;
  //delay(100);

}