#include <mensajeInicial.h>

mensajeinicial bienvenida= mensajeinicial();

void setup() {
  bienvenida.inicializar();
  Serial.begin(9600);

}

void loop() {
  bienvenida.actualizarMatriz();
  Serial.println("termine el loop");
}