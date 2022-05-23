#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "iniciarSesion.h"
#include "registro.h"
#include "../admin/menuAdmin.h"

void iniciarSesion(sqlite3 *db){//TODO implementar el uso de la bd de usuarios

	char nombre[20];
	char contrasena[20];

	printf("\nINICIAR SESION\n");
	fflush(stdout);
	printf("--------------\n");
	fflush(stdout);
	printf("Introduzca su nombre: ");
	fflush(stdout);
	scanf(" %s", nombre);
	printf("Introduzca su contrasena: ");
	fflush(stdout);fflush(stdout);
	scanf(" %s", contrasena);
	printf("Nombre:%s, Contrasena:%s", nombre, contrasena);
	fflush(stdout);


	if(strcmp(nombre, "b") && strcmp(contrasena, "b")){
		//Aqui es para la consulta de si el usuario esta registrado, entonces sigue el programa, si no pasa al else
		//Usuario Normal
		printf("No disponible :(");
		fflush(stdout);
	}
	else if(strcmp(nombre, "a") && strcmp(contrasena, "a")){
		//Aqui es para la consulta de si el usuario esta registrado, entonces sigue el programa, si no pasa al else
		//Administrador
		//adminInicio(db); todo volver al inicio
	}
	else{
		printf("\nDebes registrarte primero\n");
		fflush(stdout);
		registro(db);
	}

}
