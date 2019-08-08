#include "ControlMatrix.h"

ControlMatrix::ControlMatrix()
{
    var = nullptr;
}

void ControlMatrix::iniciarPuertos()
{
    lc.shutdown(0, false);
    lc.setIntensity(0, 10);
    lc.clearDisplay(0);

    matriz.iniciarPuertos();
}

void ControlMatrix::mensajeInicial(Variable *&_var)
{

    var = _var;

    if (tmpinicio == 0)
        tmpinicio = 121;
    if (tmpfin == 15)
        tmpfin = 136;

    for (int i = tmpinicio; i <= tmpfin; i++)
    {

        if (tmp < 8)
        {
            lc.setRow(0, tmp, mensaje[i]);

            Serial.print("[");
            Serial.print(tmp);
            //Serial.print(",");
            //Serial.print(mensaje[i]);
            Serial.print("]");
        }
        else if (tmp > 7 && tmp < 16)
        {
            var->Pantalla[tmp] = mensaje[i];

            Serial.print("[");
            Serial.print(tmp);
            //Serial.print(",");
            //  Serial.print(mensaje[i]);
            Serial.print("]");
        }
        else
        {
            Serial.print("[");
            Serial.print(tmp);
            //Serial.print(",");
            //Serial.print(mensaje[i]);
            Serial.print("]");
        }

        tmp = tmp + 1;
    }

    Serial.print(";\n");

    tmp = 0;
    tmpinicio--;
    tmpfin--;

    matriz.setMatriz(var);
    delay(100);
}

void ControlMatrix::paintgame(Variable *&_var)
{

    var = _var;

    for (int i = 0; i < 8; i++)
    {
            lc.setRow(0, i, var->Pantalla[i]);
        
    }

    matriz.setMatriz(var);
    delay(100);
}