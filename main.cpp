#include <ControlMatrix.h>
#include "matriz.h"

Variable *var = new Variable();
ControlMatrix Matriz = ControlMatrix(var);

int btn_pausa = 4;
int btn_inicio = 2;
int btn_derecha = 3;
int btn_izquierda = 5;
int btn_rotar = 6;
long valor;

int *matrizz = new int[16];
matriz m = matriz(matrizz, 16, var);

bool msginicio = true;
bool pause = false;
bool gamewin = false;
bool endgame = false;

void setup()
{
  Serial.begin(9600);
  Matriz.iniciarPuertos();
  pinMode(btn_inicio, INPUT);
  pinMode(btn_pausa, INPUT);
  pinMode(btn_derecha, INPUT);
  pinMode(btn_izquierda, INPUT);
  pinMode(btn_rotar, INPUT);

  for (int i = 0; i < 16; i++)
    matrizz[i] = 0;
}

void loop()
{

  //implementamos el mensaje de inicio
  if (msginicio)

  {
    valor = analogRead(A0);
    Matriz.mensajeInicial();
    delay(valor / 2);
    while (digitalRead(btn_inicio) == HIGH)
    {
      delay(3000);
      if (digitalRead(btn_inicio) == HIGH)
      {
        msginicio = false;
        break;
      }
    }
  }

  //inicia el juego
  if (!pause && !msginicio && !gamewin && !endgame)
  {
    Serial.println(" si entor alv inciando juego o no se-----------------------------------------------");

    valor = analogRead(A0);

    if (digitalRead(btn_derecha) == HIGH)
    {
      m.moverFiguritaDerecha();
    }

    if (digitalRead(btn_izquierda) == HIGH)
    {
      m.moverFiguritaIzquierda();
    }

    if (digitalRead(btn_rotar) == HIGH)
    {
      m.moverFiguritaRotar();
    }

    if (digitalRead(btn_pausa) == HIGH)
    {
      var->setScore(m.score);
      pause = true;
    }

    m.moverFiguritaAbajo(); //siempre baja por defecto
    m.verigicarlinea();

    int gameOver = m.verificarFin(); //1->verdadero             0->falso
    if (gameOver == 1)
    {
      endgame = true;
    }
    if (m.score == 1)
    {
      gamewin = true;
    }

    //verificar si una linea esta completa, aumenta el score(incompleto)

    m.toInt();
    delay(valor / 2);
  }

  //si termino el juego
  if (endgame)
  {
    Serial.println(" estmos en derrota--");
    valor = analogRead(A0);

    Matriz.setmsg(&(var->msderrota[0]), 72);
    /* while (digitalRead(btn_inicio) == HIGH)
    {
      delay(3000);
      if (digitalRead(btn_inicio) == HIGH)
      {
        //ingresar codigo para limpiar
        for (int i = 0; i < 16; i++)
          matrizz[i] = 0;
        m = matriz(matrizz, 16, var);
        m.fin = 0;
        m.score = 0;
        m.id = 1;
        endgame = false;
        msginicio = true;
        break;
      }
    }*/
    delay(valor / 2);
  }

  //si ganamos el juego
  if (gamewin)
  {

    Serial.println(" estamos en vistoria-----------------------------");
    valor = analogRead(A0);

    Matriz.setmsg(&(var->msvictoria[0]), 80);
    /*while (digitalRead(btn_inicio) == HIGH)
    {
      delay(3000);
      if (digitalRead(btn_inicio) == HIGH)
      { //ingresar codigo para limpiar
        for (int i = 0; i < 16; i++)
          matrizz[i] = 0;
        m = matriz(matrizz, 16, var);
        m.fin = 0;
        m.score = 0;
        m.id = 1;

        gamewin = false;
        msginicio = true;

        break;
      }
    }*/
    delay(valor / 2);
  }

  //si el juego esta pausado
  if (pause)
  {
    valor = analogRead(A0);

    Matriz.setmsg(&(var->score[0]), 72);

    if (digitalRead(btn_pausa) == HIGH)
    {
      pause = false;
    }
    delay(valor / 2);
  }

  Matriz.paintgame(); //pintar la matriz
}