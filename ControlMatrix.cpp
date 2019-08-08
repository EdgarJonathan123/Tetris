#include "ControlMatrix.h"

ControlMatrix::ControlMatrix(Variable *&_var)
{
    var = _var;
}

void ControlMatrix::iniciarPuertos()
{
    lc.shutdown(0, false);
    lc.setIntensity(0, 1);
    lc.clearDisplay(0);

    matriz.iniciarPuertos();
}
void ControlMatrix::setmsg(int *msg, int tamanio)
{

    if (state)
    {
        tmpinicio = (tamanio - 16);
        tmpfin = tamanio;
        tmp = 0;

        state = false;
    }

    if (tmpinicio == 0)
        tmpinicio = (tamanio - 16);
    if (tmpfin == 15)
        tmpfin = tamanio;

    for (int i = tmpinicio; i < tmpfin; i++)
    {

        var->Pantalla[tmp] = msg[i];

        tmp = tmp + 1;
    }

    Serial.print(";\n");

    tmp = 0;
    tmpinicio--;
    tmpfin--;

    matriz.setMatriz(var);
}

void ControlMatrix::mensajeInicial()
{

    if (tmpinicio == 0)
        tmpinicio = 120;
    if (tmpfin == 15)
        tmpfin = 136;

    for (int i = tmpinicio; i <= tmpfin; i++)
    {

        if (tmp < 8)
        {
            lc.setRow(0, tmp, mensaje[i]);
        }
        else if (tmp > 7 && tmp < 16)
        {
            var->Pantalla[tmp] = mensaje[i];
        }

        tmp = tmp + 1;
    }

    //Serial.print(";\n");

    tmp = 0;
    tmpinicio--;
    tmpfin--;

    matriz.setMatriz(var);
}

void ControlMatrix::paintgame()
{

    //editgame();

    for (int i = 0; i < 8; i++)
    {
        lc.setRow(0, i, var->Pantalla[i]);
        Serial.print("codigo recibe");
        Serial.print(var->Pantalla[i]);
    }
    Serial.println();

    matriz.setMatriz(var);
}
void ControlMatrix::editgame()
{
}

