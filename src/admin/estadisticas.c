#include <stdio.h>
#include "estadisticas.h"
//#include "cliente.h"

void tarifaMasSolicitada(){
    //llamar a la bd --> count
    int t = 0;

    switch(t)
    {
        case 0:
            printf("La tarifa mas solicitada es la de 1 dia");
            break;
        case 1:
            printf("La tarifa mas solicitada es el de 1 semana");
            break;
        case 2:
            printf("La tarifa mas solicitada es la de 2 semanas");
            break;
        case 3:
            printf("La tarifa mas solicitada es la de 1 mes");
            break;
        case 4:
            printf("La tarifa mas solicitada es la de 1 cuatrimestre");
            break;     
    }
}

void usuarioMasComun(){
    //los usarios los clasificamos por p, e, r
    char u = 'p';

    switch(u)
    {
        case 'p':
            printf("Los usuarios mas comunes son los profesores");
            break;
        case 'e':
            printf("Los usuarios mas comunes son los estudiantes");
            break;
        case 'r':
            printf("Los usuarios mas comunes son los regulares");
            break;    
    }
}

void usuariosMasFrecuentes(){
//    Cliente* c; //array desde la bd
//    //TODO falta crear la clase Cliente, esta parte deberia estar en el cliente, y el servior lo que hará será devolver los campos por separado
//
//    for (int i = 0; i < 5; i++) //queremos top 5 clientes
//    {
//        printf("%d) %d", i+1, c[i].dni); //esto deberia de funcionar en c++, pero en c no tenemos clases
//    }
//
}