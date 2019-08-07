#include <mensajeInicial.h>

//#include <MatrizSinDriver.h>


//creacion de objetos
mensajeinicial bienvenida= mensajeinicial();
 //MatrizSinDriver matriz = MatrizSinDriver();



void setup() {
  bienvenida.inicializar();
  Serial.begin(9600);
 // matriz.iniciarPuertos();
}

void loop() {
  bienvenida.actualizarMatriz();



 /*  matriz.setRow(1,4);
  matriz.setRow(0, 85);
	matriz.setRow(2, 255);
  matriz.setRow(4, 15);
*/

}
