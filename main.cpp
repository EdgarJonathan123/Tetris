#include <ControlMatrix.h>
#include "matriz.h"
Variable *var = new Variable();
ControlMatrix Matriz = ControlMatrix(var);
int btn_derecha = 3;
int btn_izquierda = 5;
int btn_rotar = 6;
long valor;

int *matrizz = new int[16];
matriz m = matriz(matrizz, 16, var);

void setup()
{
  Serial.begin(9600);
  Matriz.iniciarPuertos();
  pinMode(btn_derecha, INPUT);
  pinMode(btn_izquierda, INPUT);
  pinMode(btn_rotar, INPUT);

  for (int i = 0; i < 16; i++)
    matrizz[i] = 0;
}

void loop()
{ /* 
  Serial.print("\n-----------------Loop------------------\n");
  
  Matriz.mensajeInicial();*/

  valor = analogRead(A0);
  m.toInt();
  if (digitalRead(btn_derecha) == HIGH)
  {
    m.toInt();
    m.moverFiguritaDerecha();
    m.toInt();

    //delay(250);
  }
  m.toInt();
  if (digitalRead(btn_izquierda) == HIGH)
  {
    m.toInt();
    m.moverFiguritaIzquierda();
    m.toInt();

    //delay(250);
  }
  m.toInt();
  if (digitalRead(btn_rotar) == HIGH)
  {
    m.toInt();
    m.moverFiguritaRotar();
    m.toInt();

    //delay(250);
  }
  m.toInt();

  m.moverFiguritaAbajo(); //siempre baja por defecto
  m.toInt();
  Matriz.paintgame(); //pintar la matriz

  m.verigicarlinea();
  m.toInt(); //verificar si una linea esta completa, aumenta el score(incompleto)

  delay(valor / 2);
}