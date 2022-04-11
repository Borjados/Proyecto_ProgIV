/*
 * registro.c
 *
 *  Created on: 11 abr 2022
 *      Author: borja
 */

#include <stdio.h>
#include <stdlib.h>
#include "registro.h"
#include "inicio.h"

void registro(){

	int seleccion, DNI, tarjeta, telefono, selecadmin, bono;
	char nombre[20];
	char username[20];
	char apellidos[30];
	char contrasena[20];
	char tipo;
	int i = 0;
	int sel = 0;

	while(sel != 1){

	printf("\nRegistro\n");
	fflush(stdout);
	printf("--------------\n");
	fflush(stdout);
	printf("Introduzca su nombre: ");
	fflush(stdout);
	scanf(" %s", nombre);
	printf("Introduzca sus apellidos: ");
	fflush(stdout);
	scanf(" %s", apellidos);
	printf("Introduzca su DNI: ");
	fflush(stdout);
	scanf(" %i", &DNI);
	printf("Introduzca su Tarjeta: ");
	fflush(stdout);
	scanf(" %i", &tarjeta);
	printf("Introduzca su Telefono: ");
	fflush(stdout);
	scanf(" %i", &telefono);
	printf("Introduzca su nombre de usuario: ");
	fflush(stdout);
	scanf(" %s", username);
	printf("Introduzca su contraseña: ");
	fflush(stdout);
	scanf(" %s", contrasena);
	printf("Es profersor(p),Estudiante(e) o Regular(r): ");
	fflush(stdout);
	scanf(" %s", &tipo);
	printf("Nombre:%s, Apellidos:%s, DNI:%i, Tarjeta:%i, Telefono:%i, Nombre de usuario:%s, Contraseña:%s, Tipo:%c", nombre,apellidos,DNI,tarjeta,telefono,username,contrasena,tipo);
	fflush(stdout);

	//Aqui se hace el registro en BD del usuario

	if(i == 0){
		// Todo a ido bien se ha registrado el usuario
		iniciarSesion();
		sel = 1;
	}

	else{
		//Si el registro falla
		printf("Vuelve a intertarlo");
		fflush(stdout);
	}


	}

}
