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

}