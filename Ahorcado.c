#include <stdio.h>
#include <stdlib.h>
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


void Lineas_Palabras(int PosX, int PosY, int TotalX, int Cantidad, int *Largo_Cada_Linea, int *Espacio_por_cada_Linea) {
    int  i;
    *Largo_Cada_Linea=(TotalX/Cantidad); 
    *Espacio_por_cada_Linea=(*Largo_Cada_Linea)*20/100;
    *Largo_Cada_Linea=(*Largo_Cada_Linea)-(*Espacio_por_cada_Linea);
 
//     line(PosX,PosY,TotalX,PosY);
    
//     printf("\n\n        %i  -  %i", PosX, PosX+Largo_Cada_Linea);
    line(PosX,PosY,PosX+(*Largo_Cada_Linea),PosY);
    
    for(i=1;i<Cantidad;i++) {
//     printf("\n\n        %i  -  %i", PosX+Largo_Cada_Linea*i+Espacio_por_cada_Linea*i, PosX+Largo_Cada_Linea*(i+1)+Espacio_por_cada_Linea*i);
        line(PosX+(*Largo_Cada_Linea)*i+(*Espacio_por_cada_Linea)*i,PosY,PosX+(*Largo_Cada_Linea)*(i+1)+(*Espacio_por_cada_Linea)*i,PosY);
    }

    
}



void Menu_Inicial () {
    outtextxy(120,80,"Bienvenido al AHORCADO en Modo Grafico con C");
    outtextxy(20,120,"CREADOR: Leonardo Da Silva");
    outtextxy(20,140,"CURSO: 4 Computacion");
    outtextxy(20,160,"FECHA: 2021");
    delay(4000);
    cleardevice();
}


void Pregunta (char *Palabra, int *Cantidad_de_Letras) {
    int i;
    
    outtextxy(20,215,"Ingrese la Palabra del Ahorcado=> ");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                       ");
    fflush(stdin);
    scanf("%s",Palabra);
    fflush(stdin);
    cleardevice();
    
    for(i=0;i<99;i++) {
//         printf("%c", Palabra[i]);
        if((Palabra[i])!='~') (*Cantidad_de_Letras)++;
    }
    (*Cantidad_de_Letras)--;
    
//     printf("\n\n\n\n            Cantidad de letras: %i", *Cantidad_de_Letras);
    
}


void Lee_Letra (char *Letra_Ingresada) {
    outtextxy(20,395,"Ingrese la Letra a Adivinar=>");
    fflush(stdin);
    scanf("%c", Letra_Ingresada);
    fflush(stdin);
    fflush(stdin);    
    
}


void Comprobar_y_Colocar_Letra (char Letra_Ingresada, char *Palabra, int Cantidad_de_Letras, int Largo_Cada_Linea, int Espacio_por_cada_Linea, int *Total_Encontradas, int *Fallos, int PosX_Ahorcado, int PosY_Ahorcado) {

    int Cant_Letras_Encontradas=0, i, r, z;
    
    for(i=0;i<=Cantidad_de_Letras;i++) {
    
            if(Palabra[i]==Letra_Ingresada) {
                Cant_Letras_Encontradas++;
                
                Imprimir_Letras (Palabra, i, Letra_Ingresada, Largo_Cada_Linea, Espacio_por_cada_Linea, PosX_Ahorcado, PosY_Ahorcado); //COMPLETAR ESTE LLAMADO DE FUNCION
            }
        
        
    }
        if (Cant_Letras_Encontradas==0) (*Fallos)++;
        
        *Total_Encontradas=(*Total_Encontradas)+Cant_Letras_Encontradas;
        //printf("%i",Cant_Letras_Encontradas);
        
}


void Imprimir_Letras (char *Palabra, int Posicion, char Letra_Ingresada, int Largo_Cada_Linea, int Espacio_por_cada_Linea, int PosX_Ahorcado, int PosY_Ahorcado) {
    //ACÁ TENDRÍA QUE IMPRIMIR LA LETRA QUE SE ENCONTRO SEGUN LA POSICION EN EL STRING DE 'PALABRA'. LA POSICION EN EL MAPA SE PUEDE SABER CON EL VALOR DE 'LARGO_DE_LINEA' QUE SE DIVIDE A LA MITAD Y LOS ESPACIO_POR_cada_Linea PARA CALCULAR EL ESPACIO JUSTO DONDE LLEGA (PORQUE SINO NO VA A CONTAR LOS ESPACIO Y VA A TERMINAL MAL)
    char Letra[120];

            sprintf(Letra,"%c",Palabra[Posicion]); //COLOCA EN LA VARIABLE 'Letra' EL FORMATO CORRECTO PARA QUE OUTTEXTXY PUEDA IMPRIMIR CORRECTAMENTE 'Letra_Ingresada'
            
        //     printf("%i", PosX_Ahorcado + (Largo_Cada_Linea/2) + ((Largo_Cada_Linea + Espacio_por_cada_Linea)*Posicion) );
            
            
            outtextxy( (PosX_Ahorcado + Largo_Cada_Linea/2 + Largo_Cada_Linea*Posicion + Espacio_por_cada_Linea*Posicion) - 1 , PosY_Ahorcado-30 ,   Letra   );

}



    
int main () {
    int gdriver=DETECT, gmode, i, Cantidad_de_Letras=0,Largo_Cada_Linea,Espacio_por_cada_Linea, Total_Encontradas=0, Fallos=0;
    char Palabra[99999], Respuesta[99999], Letra_Ingresada='~';
    initgraph(&gdriver,&gmode,NULL);
    
    
    for(i=0;i<99;i++) {
        Palabra[i]='~';
    }
    
    
    //Menu_Inicial();
    
     Pregunta(&Palabra,&Cantidad_de_Letras);
    /*
    closegraph(); // CIERRO Y VUELVO A ABRIR PARA QUE NO SE CUELGUE LA LECTURA DEL TEXTO
    gdriver=DETECT; gmode=7589738954937;
    initgraph(&gdriver,&gmode,NULL);
    */
    
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                               ");   
      
    while(Fallos<5){
        Poste_Ahorcado(Fallos,20,120);
        Lineas_Palabras(100,350,getmaxx()-100,Cantidad_de_Letras, &Largo_Cada_Linea,&Espacio_por_cada_Linea);
        Lee_Letra(&Letra_Ingresada);
        Comprobar_y_Colocar_Letra(Letra_Ingresada,&Palabra,Cantidad_de_Letras,Largo_Cada_Linea,Espacio_por_cada_Linea, &Total_Encontradas, &Fallos, 100, 350);
        if (Total_Encontradas==Cantidad_de_Letras) {
            cleardevice();
            outtextxy(195,65,"FELICIDADES --> Has Ganado");
            delay(3000);
            closegraph();
        }
    }
    
    cleardevice();
    outtextxy(195,65,"Lastima, Has PERDIDO");
    outtextxy(150,85,"Talvez tengas mayor suerte la proxima.");
    outtextxy(195,115,"RESPUESTA --> ");
    sprintf(Respuesta,"%s",Palabra);
    outtextxy(305,115,Respuesta);
    
    delay(3000);
    closegraph();
    
}
