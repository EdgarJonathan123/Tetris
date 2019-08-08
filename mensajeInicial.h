#ifndef MENSAJEINICIAL_H
#define MENSAJEINICIAL_H
#include "LedControl.h"
#include "Arduino.h"
#include <MatrizSinDriver.h>

class mensajeinicial
{
public:

//MatrizSinDriver matriz = MatrizSinDriver();

const int mensaje[136] = {                           
                        B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
                        B00000000,B01111000,B01000100,B01000100,B01111000,B01000100,B01000100,B01111000,//b 
                        B00000000,B00111000,B01000100,B01000000,B01111000,B01000100,B01000100,B00111000,//6
                        B00000000,B00000000,B00000000,B00000000,B00111000,B00000000,B00000000,B00000000,//-
                        B00000000,B00111000,B01000100,B01000100,B01000100,B01000100,B01000100,B00111000,//o
                        B00000000,B01111000,B01000100,B01000100,B01111000,B01000000,B01000000,B01000000,//p
                        B00000000,B01000100,B01000100,B01000100,B01000100,B01000100,B01000100,B00111000,//u
                        B00000000,B01111000,B01000100,B01000100,B01111000,B01000100,B01000100,B01000100,//r
                        B00000000,B00111000,B01000100,B01000000,B01011100,B01000100,B01000100,B00111000,//G
                        B00000000,B00000000,B00000000,B00000000,B00111000,B00000000,B00000000,B00000000,//-
                        B00000000,B00010000,B00110000,B00010000,B00010000,B00010000,B00010000,B00111000,//1
                        B00000000,B01000100,B01000100,B01000100,B01000100,B01000100,B01000100,B00111000,//u 
                        B00000000,B00111000,B01000100,B01000100,B01000100,B01010100,B01001100,B00111100,//q
                        B00000000,B01111000,B01000100,B01000100,B01111000,B01000100,B01000100,B01000100,//r
                        B00000000,B00111000,B01000100,B01000100,B01111100,B01000100,B01000100,B01000100,//a  
                        B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000//nada 
};

int tmpinicio=128;
int tmpfin=136;
int tmp=0;

LedControl lc= LedControl(12,10,11,1);//el ultimo parametro es el numero de modulos

mensajeinicial();
void inicializar();
void actualizarMatriz();
    


};

#endif
