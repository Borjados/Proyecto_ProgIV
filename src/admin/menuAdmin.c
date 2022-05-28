#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menuAdmin.h"
//#include "menuAuth.h"
#include "bonos.h"
//#include "cliente.h"
#include "estadisticas.h"
#include "../dbManager/consultas.h"
//#include "../domain/bonos.h"
//#include "../domain/cliente.h"
//#include "../domain/estadisticas.h"


typedef enum { false, true } bool;

void initAdmin()
{   
    int opcion;
    do {
        opcion = selectMenuOptionAdmin();
        selectOptionAdmin(opcion);
    } while (opcion != 0);

    //initAuth();       //función sin declarar
}

int selectMenuOptionAdmin() {
    char str[1], read;
    //int read;
    char option;
    bool right;

    do {
        printf("\n+---------------------------------------------+\n");
        printf("|        BIENVENIDO ADMINISTRADOR             |\n");
        printf("|---------------------------------------------|\n");
        printf("| 1. Ver estadisticas                         |\n");
        printf("| 2. Modificar bonos                          |\n");
        printf("| 0. Salir                                    |\n");
        printf("+---------------------------------------------+\n");

        printf("\nSelecciona una opcion: ");
        read = scanf("%c", &option);


        if (read != 1 || option == '\n' || option - '0' < 0 || option - '0' > 2) {
            //cleanStdin();         //función sin declarar
            //system("cls");        //función sin declarar
            printf("\nValor incorrecto, debe estar entre 0 y 2.\n");
            right = false;
        } else right = true;
    } while (!right);

    return option - '0';
}

void selectOptionAdmin(int option)
{
//    cleanStdin();         //función sin declarar
//    system("cls");        //función sin declarar
    switch (option)
    {
    case 1:
        menuEstadisticas();
        break;
    case 2:
        menuBonos();
        break;
    }
}

void menuEstadisticas() {
    int read;
    char option;
    bool rigth;

    do {
        printf("\n+---------------------------------------------+\n");
        printf("|              MENU ESTADISTICAS              |\n");
        printf("|---------------------------------------------|\n");
        printf("| 1. Tarifa mas solicitada                    |\n");
        printf("| 2. Tipo de usuario mas comun                |\n");
        printf("| 3. Usuarios mas frecuentes                  |\n");
        printf("| 0. Salir                                    |\n");
        printf("+---------------------------------------------+\n");

        printf("\nSelecciona una opcion: ");
        read = scanf("%c", &option);

        if (read != 1 || option == '\n' || option - '0' < 0 || option - '0' > 3) {
//            cleanStdin();     Mismo que antes
//            system("cls");
            printf("\nValor incorrecto, debe estar entre 0 y 3.\n");
            rigth = false;
        } else rigth = true;
    } while (!rigth);

    int sel = option - '0';

    switch (sel)
    {//comentado para q no crashee falta bd
    case 1:
        printf("%d", sel);
//        tarifaMasUsada(); //TODO poner puntero a db
        break;
    case 2:
        printf("%d", sel);
//        usuarioMasComun();//TODO poner puntero a db
        break;
    case 3:
        printf("%d", sel);
        usuariosMasFrecuentes();
        break;
    }
}

void menuBonos() {

    int read;
    char option;
    bool rigth;
    int precio;
    
    do {
        printf("\n+---------------------------------------------+\n");
        printf("|                    BONOS                    |\n");
        printf("|---------------------------------------------|\n");
        printf("| 1. 1 dia                                    |\n");
        printf("| 2. 1 semana                                 |\n");
        printf("| 3. 2 semanas                                |\n");
        printf("| 4. 1 mes                                    |\n");
        printf("| 5. Cuatrimestre                             |\n");
        printf("| 0. Salir                                    |\n");
        printf("+---------------------------------------------+\n");

        printf("\nSelecciona una opcion: ");
        read = scanf("%c", &option);

        if (read != 1 || option == '\n' || option - '0' < 0 || option - '0' > 5) {
//            cleanStdin();
//            system("cls");
            printf("\nValor incorrecto, debe estar entre 0 y 5.\n");
            rigth = false;
        } else rigth = true;
    } while (!rigth);

    int sel = option - '0';
//    cleanStdin();

    switch (sel)
    {
    case 1:
        printf("Que precio quieres poner al bono diario?");
        break;
    case 2:
        printf("Que precio quieres poner al bono semanal?");
        break;
    case 3:
        printf("Que precio quieres poner al bono bisemanal?");
        break; 
    case 4:
        printf("Que precio quieres poner al bono mensual?");
        break;
    case 5:
        printf("Que precio quieres poner al bono cuatrimestral?");
        break;
    }
    
    scanf("%d", &precio);
    //updateBonos(db, "cuatrimestral", precio);
}

/*
void menuFicheros() {
    int read;
    char option;
    bool rigth;

    do {
        printf("\n+---------------------------------------------+\n");
        printf("|           CREACION DE FICHEROS              |\n");
        printf("|---------------------------------------------|\n");
        printf("| 1. Historial usuarios                       |\n");
        printf("| 2. Taquillas ocupadas                       |\n");
        printf("| 0. Salir                                    |\n");
        printf("+---------------------------------------------+\n");

        printf("\nSelecciona una opcion: ");
        read = scanf("%c", &option);

        if (read != 1 || option == '\n' || option - '0' < 0 || option - '0' > 2) {
            cleanStdin();
            system("cls");
            printf("\nValor incorrecto, debe estar entre 0 y 2.\n");
            rigth = false;
        } else rigth = true;
    } while (!rigth);

    int sel = option - '0';

    switch (sel)
    {
    case 1:
        //Escribe en el fichero
        break;
    case 2:
        //Taquillas
        break;
    }
}
*/
