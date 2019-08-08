#include "ControlMatrix.h"

ControlMatrix::ControlMatrix()
{

    lc.shutdown(0, false);
    lc.setIntensity(0, 10);
    lc.clearDisplay(0);

}

void ControlMatrix::mensajeInicial()
{

    if (tmpinicio == 0)
        tmpinicio = 121;
    if (tmpfin == 15)
        tmpfin = 136;

    for (int i = tmpinicio; i <= tmpfin; i++)
    {

        if (tmp < 8)
        {
        }
        else
        {
        }

        tmp = tmp + 1;
    }
    tmp = 0;
    tmpinicio--;
    tmpfin--;
}