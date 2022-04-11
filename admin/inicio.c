/*
 * inicio.c
 *
 *  Created on: 11 abr 2022
 *      Author: borja
 */

#include <stdio.h>
#include <stdlib.h>
#include "inicio.h"

void inicio(){

	int sel = 0;
	printf("¡BIENVENIDO A DEUSTOTAQUILLAS!\n");
	fflush(stdout);
	printf("------------------------------\n");
	fflush(stdout);
	printf("1.Iniciar Sesion\n");
	fflush(stdout);
	printf("2.Registrarse\n");
	fflush(stdout);
	printf("3.Cerrar\n");
	fflush(stdout);

	scanf(" %i", &sel);
	fflush(stdout);

		switch (sel){
		case 1:

			iniciarSesion();

		break;


		case 2:

			registro();

		break;

		case 3:

			exit(-1);

		break;

		}

}
