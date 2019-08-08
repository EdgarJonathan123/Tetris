#include "figura.h"


figura::figura(int posiciony, int posicionx)
{
    y=posiciony;
    x=posicionx;
    //  x x x
    //    x
}

int figura::mov_bajar(){
    int enviar=1;
    if(lim1Y<15){
        enviar=0;
        y++;
        lim1Y++;
        //cout<<lim1X<<","<<lim2X<<","<<lim1Y<<"->baja"<<endl;

        arrayY[0]=arrayY[0]+1;
        arrayY[1]=arrayY[1]+1;
        arrayY[2]=arrayY[2]+1;
        arrayY[3]=arrayY[3]+1;

        return enviar;

    }
    else
    {
        return enviar;

    }
}
void figura::mov_derecha(){
    if(lim2X<7){
        x++;
        lim2X++;
        lim1X++;
        //cout<<lim1X<<","<<lim2X<<","<<lim1Y<<"->derecha"<<endl;

        arrayX[0]= arrayX[0]+1;
        arrayX[1]= arrayX[1]+1;
        arrayX[2]= arrayX[2]+1;
        arrayX[3]= arrayX[3]+1;

    }else{//cout<<"llego al limite"<<endl;
    }

}
void figura::mov_izquierda(){
    if(lim1X>0){
        x=x-1;
        lim1X--;
        lim2X--;
      //  cout<<lim1X<<","<<lim2X<<","<<lim1Y<<"->izquierda"<<endl;
        arrayX[0]= arrayX[0]-1;
        arrayX[1]= arrayX[1]-1;
        arrayX[2]= arrayX[2]-1;
        arrayX[3]= arrayX[3]-1;

    }else
    {
       // cout<<"llego al limite"<<endl;
    }
}

void figura::mov_rotar(int numero){
    rotacion++;

    if(numero==1){

    if(rotacion==2){
        arrayY[1]=y+1;  arrayX[1]=x;
        arrayY[2]=y+2;  arrayX[2]=x;
        arrayY[3]=y+1;  arrayX[3]=x-1;

    }
    if(rotacion==3){

        arrayY[1]=y;    arrayX[1]=x-1;
        arrayY[2]=y;    arrayX[2]=x-2;
        arrayY[3]=y-1;  arrayX[3]=x-1;
    }
    if(rotacion==4){
        arrayY[1]=y-1;   arrayX[1]=x;
        arrayY[2]=y-2;   arrayX[2]=x;
        arrayY[3]=y-1;   arrayX[3]=x+1;
    }
    if(rotacion==5){
        arrayY[1]=y;   arrayX[1]=x+1;
        arrayY[2]=y;   arrayX[2]=x+2;
        arrayY[3]=y+1; arrayX[3]=x+1;
        rotacion=1;
    }

}

    if(numero==2){

    if(rotacion==2){
        arrayY[1]=y;  arrayX[1]=x-1;
        arrayY[2]=y;  arrayX[2]=x-2;
        arrayY[3]=y+1;  arrayX[3]=x;

    }
    if(rotacion==3){

        arrayY[1]=y;    arrayX[1]=x-1;
        arrayY[2]=y-1;    arrayX[2]=x;
        arrayY[3]=y-2;  arrayX[3]=x;
    }
    if(rotacion==4){
        arrayY[1]=y-1;   arrayX[1]=x;
        arrayY[2]=y;   arrayX[2]=x+1;
        arrayY[3]=y;   arrayX[3]=x+2;
    }
    if(rotacion==5){
        arrayY[1]=y;   arrayX[1]=x+1;
        arrayY[2]=y+1;   arrayX[2]=x;
        arrayY[3]=y+2; arrayX[3]=x;
        rotacion=1;
    }

}

    if(numero==3){

    if(rotacion==2){
        arrayY[1]=y;  arrayX[1]=x-1;
        arrayY[2]=y;  arrayX[2]=x-2;
        arrayY[3]=y;  arrayX[3]=x-3;

    }
    if(rotacion==3){

        arrayY[1]=y-1;    arrayX[1]=x;
        arrayY[2]=y-2;    arrayX[2]=x;
        arrayY[3]=y-3;    arrayX[3]=x;
    }
    if(rotacion==4){
        arrayY[1]=y;   arrayX[1]=x+1;
        arrayY[2]=y;   arrayX[2]=x+2;
        arrayY[3]=y;   arrayX[3]=x+3;
    }
    if(rotacion==5){
        arrayY[1]=y+1;   arrayX[1]=x;
        arrayY[2]=y+2;   arrayX[2]=x;
        arrayY[3]=y+3; arrayX[3]=x;
        rotacion=1;
    }



}
    if(numero==5){

    if(rotacion==2){
        //cout<<"entra aqui"<<endl;
        arrayY[1]=y+1;  arrayX[1]=x;
        arrayY[2]=y+1;  arrayX[2]=x-1;
        arrayY[3]=y+2;  arrayX[3]=x-1;

    }
    if(rotacion==3){

        arrayY[1]=y;    arrayX[1]=x-1;
        arrayY[2]=y-1;    arrayX[2]=x-1;
        arrayY[3]=y-1;    arrayX[3]=x-2;
    }
    if(rotacion==4){
        arrayY[1]=y-1;   arrayX[1]=x;
        arrayY[2]=y-1;   arrayX[2]=x+1;
        arrayY[3]=y-2;   arrayX[3]=x+1;
    }
    if(rotacion==5){
        arrayY[1]=y;   arrayX[1]=x+1;
        arrayY[2]=y+1;   arrayX[2]=x+1;
        arrayY[3]=y+1; arrayX[3]=x+2;
        rotacion=1;
    }
    }
    int minimum = arrayX[0];
            for (int c = 1; c < 4; c++){
                 if (arrayX[c] < minimum) minimum = arrayX[c];
             }
     //cout<<"minimo x->"<<minimum<<endl;
     lim1X= minimum;



    int mayimo = arrayX[0];
            for (int c = 1; c < 4; c++){
                if (arrayX[c]>mayimo )mayimo = arrayX[c];
            }
     //cout<<"mayimo x->"<<mayimo<<endl;
     lim2X=mayimo;


     int minimum1 = arrayY[0];
            for (int c = 1; c < 4; c++)
                {
                    if (arrayY[c] > minimum1)minimum1 = arrayY[c];
                }
      lim1Y=minimum1;
     // cout<<"mayimo y->"<<minimum1<<endl;


}















