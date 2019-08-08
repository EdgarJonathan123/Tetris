#include "mensajeInicial.h"


mensajeinicial::mensajeinicial(){


}


 void mensajeinicial::inicializar(){
  lc.shutdown(0,false);
  lc.setIntensity(0,10);
  lc.clearDisplay(0); 

 // matriz.iniciarPuertos();

  }
 void mensajeinicial::actualizarMatriz(){

    /*if(tmpinicio==0)tmpinicio=128;
    if(tmpfin==7)tmpfin=136;*/

   if(tmpinicio==0)tmpinicio=120;
    if(tmpfin==7)tmpfin=136;

   for(int i=tmpinicio;i<tmpfin;i++){
      lc.setRow(0,tmp,mensaje[i]);

    // matriz.setRow(tmp,mensaje[i]);
      
      tmp=tmp+1;
    }
    tmp=0;
    tmpinicio--;
    tmpfin--;
    
   // delay(50);
  
  }
