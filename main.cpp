#include <ControlMatrix.h>

ControlMatrix Matriz = ControlMatrix();
Variable *var = new Variable();

void setup()
{
  Serial.begin(9600);
  Matriz.iniciarPuertos();
}

void loop()
{
  Serial.print("\n-----------------Loop------------------\n");
  //Matriz.paintgame(var);
  Matriz.mensajeInicial(var);
}