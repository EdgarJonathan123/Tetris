#include <mensajeInicial.h>


//creacion de objetos
mensajeinicial bienvenida= mensajeinicial();
 MatrizSinDriver matriz = MatrizSinDriver();



void setup() {
  bienvenida.inicializar();
  Serial.begin(9600);
 // matriz.iniciarPuertos();
}

void loop() {
  bienvenida.actualizarMatriz();
 // matriz.setRow(1,4);


}
