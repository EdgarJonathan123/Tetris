#include "matriz.h"

matriz::matriz(int *matriz,int tam, Variable *& _var){
    figurita= figura(0,0);
    for(int x=0; x<tam; x++){
        decimalBinario(matriz[x]);
        xy[x][0]=binarioo[7];
        xy[x][1]=binarioo[6];
        xy[x][2]=binarioo[5];
        xy[x][3]=binarioo[4];
        xy[x][4]=binarioo[3];
        xy[x][5]=binarioo[2];
        xy[x][6]=binarioo[1];
        xy[x][7]=binarioo[0];
    }
    var=_var;



}
void matriz::decimalBinario(int n){
    int z,x,numero=n,n2=0;
    int binario[50];
    binario[0]=0;
    for (x=0;x<50;x++) {
    binario[x]=numero%2;
    numero=numero/2;
    if(numero==0)break;
    }

    for(z=x;z>=0;z--) {
        binarioo[z]=binario[z];
    }

}
void matriz::imprimir(){
  

}
void matriz::simular(int y[4], int x[4]) {
    //cout<<"simulando"<<endl;
    int xy2[16][8]={};

    for(int tmp=0; tmp<16;tmp++) //for para clonar la matriz original, esta es la que se muestra
    {
        xy2[tmp][0]=xy[tmp][0];xy2[tmp][1]=xy[tmp][1];xy2[tmp][2]=xy[tmp][2];xy2[tmp][3]=xy[tmp][3];xy2[tmp][4]=xy[tmp][4];xy2[tmp][5]=xy[tmp][5];xy2[tmp][6]=xy[tmp][6];xy2[tmp][7]=xy[tmp][7];
    }

    xy2[(y[0])][(x[0])]=1;     //se dibuja la figura
    xy2[(y[1])][(x[1])]=1;
    xy2[(y[2])][(x[2])]=1;
    xy2[(y[3])][(x[3])]=1;

  for (int vari = 0; vari < 16; ++vari) {
    
            int entero=
            xy2[vari][0]*pow(2,7)+
            xy2[vari][1]*pow(2,6)+
            xy2[vari][2]*pow(2,5)+
            xy2[vari][3]*pow(2,4)+
            xy2[vari][4]*pow(2,3)+
            xy2[vari][5]*pow(2,2)+
            xy2[vari][6]*pow(2,1)+
            xy2[vari][7]*pow(2,0);
             var->Pantalla[vari]= entero;

    }

}
void matriz::choque(int y[4], int x[4]){
   // cout<<"haciendo choque"<<endl;
    xy[y[0]][x[0]]=1;
   // cout<<y[0]<<","<<x[0]<<endl;
    xy[y[1]][x[1]]=1;
   // cout<<y[1]<<","<<x[1]<<endl;
    xy[y[2]][x[2]]=1;
   // cout<<y[2]<<","<<x[2]<<endl;
    xy[y[3]][x[3]]=1;
    //cout<<y[3]<<","<<x[3]<<endl;
}
void matriz::crearFigura(){
    figurita= figura(0,0);
    id++;

if(id==2){
            figurita.arrayY[0]=0; figurita.arrayX[0]=0;
            figurita.arrayY[1]=0; figurita.arrayX[1]=1;
            figurita.arrayY[2]=1; figurita.arrayX[2]=0;
            figurita.arrayY[3]=2; figurita.arrayX[3]=0;
            figurita.lim1X=0;
            figurita.lim2X=1;
            figurita.lim1Y=2;
}
if(id==3){

            figurita.arrayY[0]=0;  figurita.arrayX[0]=0;//*
            figurita.arrayY[1]=1;  figurita.arrayX[1]=0;//*
            figurita.arrayY[2]=2;  figurita.arrayX[2]=0;//*
            figurita.arrayY[3]=3;  figurita.arrayX[3]=0;//*
            figurita.lim1X=0;
            figurita.lim2X=0;
            figurita.lim1Y=3;
}
if(id==4){
            figurita.arrayY[0]=0;  figurita.arrayX[0]=0;
            figurita.arrayY[1]=0;  figurita.arrayX[1]=1;
            figurita.arrayY[2]=1;  figurita.arrayX[2]=0;
            figurita.arrayY[3]=1;  figurita.arrayX[3]=1;
            figurita.lim1X=0;
            figurita.lim2X=1;
            figurita.lim1Y=1;
}
if(id==5){
            figurita.arrayY[0]=0;  figurita.arrayX[0]=0;
            figurita.arrayY[1]=0;  figurita.arrayX[1]=1;
            figurita.arrayY[2]=1;  figurita.arrayX[2]=1;
            figurita.arrayY[3]=1;  figurita.arrayX[3]=2;
            figurita.lim1X=0;
            figurita.lim2X=2;
            figurita.lim1Y=1;
            id=1;

}

    simular(figurita.arrayY,figurita.arrayX);
}

void matriz::moverFiguritaAbajo(){
        int choque=figurita.mov_bajar();
        if(xy[figurita.arrayY[0]+1][figurita.arrayX[0]]==1)choque=1;
        if(xy[figurita.arrayY[1]+1][figurita.arrayX[1]]==1)choque=1;
        if(xy[figurita.arrayY[2]+1][figurita.arrayX[2]]==1)choque=1;
        if(xy[figurita.arrayY[3]+1][figurita.arrayX[3]]==1)choque=1;
    if(figurita.lim1Y==15)choque=1;
        if(choque==1){
        //cout<<"topo con un objeto"<<endl;
        xy[figurita.arrayY[0]][figurita.arrayX[0]]=1;
        xy[figurita.arrayY[1]][figurita.arrayX[1]]=1;
        xy[figurita.arrayY[2]][figurita.arrayX[2]]=1;
        xy[figurita.arrayY[3]][figurita.arrayX[3]]=1;
        //cout<<"mostrando la matriz"<<endl;
        //imprimir();
        crearFigura();
    }else {
        simular(figurita.arrayY,figurita.arrayX);
    }
}
void matriz::moverFiguritaDerecha(){
    figurita.mov_derecha();
    simular(figurita.arrayY,figurita.arrayX);

}
void matriz::moverFiguritaIzquierda(){
    figurita.mov_izquierda();
    simular(figurita.arrayY,figurita.arrayX);

}

void matriz::verigicarlinea(){
    int tmp2=-1;
    for(int tmp=0; tmp<16; tmp++){
        tmp2=-1;
             if(xy[tmp][0]==1&&
                xy[tmp][1]==1&&
                xy[tmp][2]==1&&
                xy[tmp][3]==1&&
                xy[tmp][4]==1&&
                xy[tmp][5]==1&&
                xy[tmp][6]==1&&
                xy[tmp][7]==1
                )
        {
            xy[tmp][0]=0;
            xy[tmp][1]=0;
            xy[tmp][2]=0;
            xy[tmp][3]=0;
            xy[tmp][4]=0;
            xy[tmp][5]=0;
            xy[tmp][6]=0;
            xy[tmp][7]=0;
            //aqui el codigo para aumentar score
            score++;
            tmp2=tmp;
           // cout<<"hay una linea completa!!!!!!!!! aumenta tu score"<<endl;
        }
        if(tmp2!=-1){
            for(int x=tmp2; x>-1; x--){
            xy[tmp][0]=xy[tmp-1][0];
            xy[tmp][1]=xy[tmp-1][1];
            xy[tmp][2]=xy[tmp-1][2];
            xy[tmp][3]=xy[tmp-1][3];
            xy[tmp][4]=xy[tmp-1][4];
            xy[tmp][5]=xy[tmp-1][5];
            xy[tmp][6]=xy[tmp-1][6];
            xy[tmp][7]=xy[tmp-1][7];

            }
            xy[0][0]=0;
            xy[0][1]=0;
            xy[0][2]=0;
            xy[0][3]=0;
            xy[0][4]=0;
            xy[0][5]=0;
            xy[0][6]=0;
            xy[0][7]=0;
        }


    }

}
void matriz::moverFiguritaRotar(){
    figurita.mov_rotar(id);
    simular(figurita.arrayY,figurita.arrayX);
}
void matriz::toInt(){
    simular(figurita.arrayY,figurita.arrayX);
}
