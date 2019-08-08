#ifndef MATRIZ_H
#define MATRIZ_H
#include <stdlib.h>
//#include "iostream"
#include "figura.h"
#include "Variable.h"
#include <math.h>
using namespace std;

class matriz
{
public:
   //atributos

    int xy[16][8]={};
    int binarioo[50]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    figura figurita=figura(0,0);
    int id=1;
    int score=0;
    Variable  *var;

   //metodos
    matriz(int *matriz,int tam,Variable  *& _var);
    void imprimir();
    void decimalBinario(int);
    void simular(int [4], int[4]);
    void choque(int[4], int[4]);
    void crearFigura();
    void moverFiguritaAbajo();
    void moverFiguritaIzquierda();
    void moverFiguritaDerecha();
    void verigicarlinea();
    void moverFiguritaRotar();
    void toInt();
};
#endif
