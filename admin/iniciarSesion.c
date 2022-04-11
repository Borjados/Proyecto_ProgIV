/*
 * iniciarSesion.c
 *
 *  Created on: 11 abr 2022
 *      Author: borja
 */

#include <stdio.h>
#include <stdlib.h>
#include "iniciarSesion.h"

void iniciarSesion(){

	int i = 2;
	char nombre[20];
	char contrasena[20];

	printf("\nINICIAR SESION\n");
	fflush(stdout);
	printf("--------------\n");
	fflush(stdout);
	printf("Introduzca su nombre: ");
	fflush(stdout);
	scanf(" %s", nombre);
	printf("Introduzca su contraseņa: ");
	fflush(stdout);fflush(stdout);
	scanf(" %s", contrasena);
	printf("Nombre:%s, Contraseņa:%s", nombre, contrasena);
	fflush(stdout);

	if(i == 1){
		//Aqui es para la consulta de si el usuario esta registrado, entonces sigue el programa, si no pasa al else
		//Usuario Normal
		printf("No disponible :(");
		fflush(stdout);
	}
	else if(i == 2){
		//Aqui es para la consulta de si el usuario esta registrado, entonces sigue el programa, si no pasa al else
		//Administrador
		adminInicio();
	}
	else{
		printf("\nDebes registrarte primero\n");
		fflush(stdout);
		registro();
	}

}
