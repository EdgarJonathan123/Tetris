#include "Variable.h"
Variable::Variable()
{
    Pantalla = new int[16];

    for (int i = 0; i < 16; i++)
        Pantalla[i] = 0;
}

void Variable::setScore(int num)
{

    switch (num)
    {
    case 0:
        for (size_t i = 0; i < 8; i++)
        {
            score[i] = cero[i];
        }

        break;
    case 1:

        for (size_t i = 0; i < 8; i++)
        {
            score[i] = uno[i];
        }
        break;
    case 2:
        for (size_t i = 0; i < 8; i++)
        {
            score[i] = dos[i];
        }

        break;
    case 3:
        for (size_t i = 0; i < 8; i++)
        {
            score[i] = tres[i];
        }
        break;
    case 4:
        for (size_t i = 0; i < 8; i++)
        {
            score[i] = cuatro[i];
        }
        break;
    case 5:
        for (size_t i = 0; i < 8; i++)
        {
            score[i] = cinco[i];
        }
        break;
    case 6:
        for (size_t i = 0; i < 8; i++)
        {
            score[i] = seis[i];
        }
        break;
    case 7:
        for (size_t i = 0; i < 8; i++)
        {
            score[i] = siete[i];
        }

        break;
    case 8:
        for (size_t i = 0; i < 8; i++)
        {
            score[i] = ocho[i];
        }
        break;
    case 9:
        for (size_t i = 0; i < 8; i++)
        {
            score[i] = nueve[i];
        }
        break;
    case 10:
        for (size_t i = 0; i < 8; i++)
        {
            score[i] =diez[i];
        }
        break;
    default:
        break;
    }
}