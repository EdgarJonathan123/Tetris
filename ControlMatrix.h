#ifndef ControlMatrix_H
#define ControlMatrix_H

#include "VARIABLE.h"
#include "LedControl.h"
#include "MatrizSinDriver.h"
#include "Arduino.h"

class ControlMatrix
{
public:
    bool state = true;
    int tmpinicio = 120;
    int tmpfin = 135;
    int tmp = 0;

    const int mensaje[136] = {
        B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, //nada
        B00000000, B01111000, B01000100, B01000100, B01111000, B01000100, B01000100, B01111000, //b
        B00000000, B00111000, B01000100, B01000000, B01111000, B01000100, B01000100, B00111000, //6
        B00000000, B00000000, B00000000, B00000000, B00111000, B00000000, B00000000, B00000000, //-
        B00000000, B00111000, B01000100, B01000100, B01000100, B01000100, B01000100, B00111000, //o
        B00000000, B01111000, B01000100, B01000100, B01111000, B01000000, B01000000, B01000000, //p
        B00000000, B01000100, B01000100, B01000100, B01000100, B01000100, B01000100, B00111000, //u
        B00000000, B01111000, B01000100, B01000100, B01111000, B01000100, B01000100, B01000100, //r
        B00000000, B00111000, B01000100, B01000000, B01011100, B01000100, B01000100, B00111000, //G
        B00000000, B00000000, B00000000, B00000000, B00111000, B00000000, B00000000, B00000000, //-
        B00000000, B00010000, B00110000, B00010000, B00010000, B00010000, B00010000, B00111000, //1
        B00000000, B00111000, B00010000, B00010000, B00010000, B00010000, B00010000, B00111000, //I
        B00000000, B01000100, B01000100, B01000100, B01000100, B01000100, B01000100, B00111000, //u
        B00000000, B00111000, B01000100, B01000100, B01000100, B01010100, B01001100, B00111100, //q
        B00000000, B01111000, B01000100, B01000100, B01111000, B01000100, B01000100, B01000100, //r
        B00000000, B00111000, B01000100, B01000100, B01111100, B01000100, B01000100, B01000100, //a
        B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000  //nada
    };

    LedControl lc = LedControl(12, 10, 11, 1); //el ultimo parametro es el numero de modulos

    Variable *var;
    MatrizSinDriver matriz = MatrizSinDriver();

    

    ControlMatrix(Variable *&_var);
    void iniciarPuertos();
    void mensajeInicial();
    void setmsg(int *msg, int tamanio);
    void paintgame();
    void editgame();
   
    

};

#endif