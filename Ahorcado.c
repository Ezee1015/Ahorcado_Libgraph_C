#include <stdio.h>
#include <graphics.h>


void Poste_Ahorcado (int Fallidos, int PosX, int PosY) {
    
    rectangle(PosX,PosY+150,PosX+60,PosY+125);
    line(PosX+30,PosY+125,PosX+30,PosY);
    line(PosX+30,PosY,PosX+120,PosY);
    line(PosX+120,PosY,PosX+120,PosY+15);
    
    
    if (Fallidos>=1) {
        circle(PosX+120,PosY+30,15);
    }
    if (Fallidos>=2) {
        line(PosX+120,PosY+45,PosX+120,PosY+100);
    }
    if (Fallidos>=3) {
        line(PosX+120,PosY+55,PosX+110,PosY+80);
        line(PosX+120,PosY+55,PosX+130,PosY+80);
    }
    if (Fallidos>=4) {
        line(PosX+120,PosY+100,PosX+110,PosY+125);
        line(PosX+120,PosY+100,PosX+130,PosY+125);
    }
    
    
    
}


void Lineas_Palabras(PosX, PosY, TotalX, Cantidad) {
 
    int Largo_Cada_Linea=(TotalX/Cantidad), 
        i,
        Espacio_por_cada_Linea=Largo_Cada_Linea*20/100;
    Largo_Cada_Linea=Largo_Cada_Linea-Espacio_por_cada_Linea;
 
//     line(PosX,PosY,TotalX,PosY);
    
//     printf("\n\n        %i  -  %i", PosX, PosX+Largo_Cada_Linea);
    line(PosX,PosY,PosX+Largo_Cada_Linea,PosY);
    
    for(i=1;i<Cantidad;i++) {
//     printf("\n\n        %i  -  %i", PosX+Largo_Cada_Linea*i+Espacio_por_cada_Linea*i, PosX+Largo_Cada_Linea*(i+1)+Espacio_por_cada_Linea*i);
        line(PosX+Largo_Cada_Linea*i+Espacio_por_cada_Linea*i,PosY,PosX+Largo_Cada_Linea*(i+1)+Espacio_por_cada_Linea*i,PosY);
    }

    
}



int main () {
    int gdriver=DETECT, gmode;
    initgraph(&gdriver,&gmode,NULL);

    Poste_Ahorcado(60,20,120);
    
    Lineas_Palabras(100,350,525,5);
    
    
    
    delay(3000);
    closegraph();
}
