#include <stdio.h>
#include <stdlib.h>
#include "registro.h"
#include "inicio.h"
#include "../dbManager/consultas.h"
#include "../auth/iniciarSesion.h"

void registro(sqlite3 *db){

	int seleccion, tarjeta, telefono, selecadmin, bono;
    char DNI[10];
	char nombre[20];
	char username[20];
	char apellidos[30];
	char contrasena[20];
	char tipo;
	int i = 0;
	int sel = 0;
	int ok = 0;

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
	scanf(" %s", DNI);
	printf("Introduzca su Tarjeta: ");
	fflush(stdout);
	scanf(" %i", &tarjeta);
	printf("Introduzca su Telefono: ");
	fflush(stdout);
	scanf(" %i", &telefono);
	printf("Introduzca su nombre de usuario: ");
	fflush(stdout);
	scanf(" %s", username);
	printf("Introduzca su contrasena: ");
	fflush(stdout);
	scanf(" %s", contrasena);
	printf("Es profesor(p),Estudiante(e) o Regular(r): ");
	fflush(stdout);
	scanf(" %s", &tipo);
	printf("Nombre:%s, Apellidos:%s, DNI:%s, Tarjeta:%i, Telefono:%i, Nombre de usuario:%s, Cotrasena:%s, Tipo:%c", nombre,apellidos,DNI,tarjeta,telefono,username,contrasena,tipo);
	fflush(stdout);

    printf("a");
	//ok = insertNewUser(db, nombre, username, apellidos, contrasena, tipo, DNI, tarjeta, telefono);//TODO error aqui, no pasa
    //printf("%i", ok);
	//Aqui se hace el registro en BD del usuario

	if(ok == 0){
		// Todo a ido bien se ha registrado el usuario
		iniciarSesion(db);
		sel = 1;
	}

	else{
		//Si el registro falla
		printf("Vuelve a intertarlo");
		fflush(stdout);
	}


	}

}
