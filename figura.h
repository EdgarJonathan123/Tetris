#ifndef FIGURA_H
#define FIGURA_H
#include "Arduino.h"

using namespace std;
class figura
{
public:
    int lim1X=0;
    int lim2X=2;
    int lim1Y=1;
    int arrayY[4]={0,0,0,1};
    int arrayX[4]={0,1,2,1};
    int x;
    int y;
    int rotacion=1;
    int moises=0;   //por defecto 

    figura(int,int);
    int mov_bajar();
    void mov_derecha();
    void mov_izquierda();
    void mov_rotar(int);
};

#endif // FIGURA_H
