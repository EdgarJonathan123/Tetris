#include <ControlMatrix.h>

Variable *var = new Variable();
ControlMatrix Matriz = ControlMatrix(var);


void setup()
{
  Serial.begin(9600);
  Matriz.iniciarPuertos();
}

void loop()
{
  Serial.print("\n-----------------Loop------------------\n");
  //Matriz.paintgame(var);
  Matriz.mensajeInicial();
}