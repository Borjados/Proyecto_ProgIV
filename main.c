/*
 * main.c
 *
 *  Created on: 5 abr 2022
 *      Author: borja
 */
#include <stdio.h>

int main(){

	setvbuf(stdout, NULL, _IONBF, 0);
	int seleccion, DNI, tarjeta, telefono;
	char nombre[20];
	char username[20];
	char apellidos[30];
	char contrasena[20];
	char tipo;
	int i = 0;

	printf("�BIENVENIDO A DEUSTOTAQUILLAS!\n");
	printf("------------------------------\n");
	printf("1.Iniciar Sesion\n");
	printf("2.Registrarse\n");
	printf("3.Cerrar\n");

	scanf("%i", &seleccion);

	while (seleccion != 3){

	switch (seleccion){
	case 1:
		printf("\nINICIAR SESION\n");
		printf("--------------\n");
		printf("Introduzca su nombre: ");
		scanf("%s", nombre);
		printf("Introduzca su contrase�a: ");
		scanf("%s", contrasena);
		printf("Nombre:%s, Contrase�a:%s", nombre, contrasena);
		if(i == 1){
			//Aqui es para la consulta de si el usuario esta registrado, entonces sigue el programa, si no pasa al else
		}
		else{
			printf("\nDebes registrarte primero\n");
			seleccion = 2;
		}
		break;

	case 2:
		printf("\nRegistro\n");
		printf("--------------\n");
		printf("Introduzca su nombre: ");
		scanf("%s", nombre);
		printf("Introduzca sus apellidos: ");
		scanf("%s", apellidos);
		printf("Introduzca su DNI: ");
		scanf("%i", &DNI);
		printf("Introduzca su Tarjeta: ");
		scanf("%i", &tarjeta);
		printf("Introduzca su Telefono: ");
		scanf("%i", &telefono);
		printf("Introduzca su nombre de usuario: ");
		scanf("%s", username);
		printf("Introduzca su contrase�a: ");
		scanf("%s", contrasena);
		printf("Es profersor(p),Estudiante(e) o Regular(r): ");
		scanf("%s", &tipo);
		printf("Nombre:%s, Apellidos:%s, DNI:%i, Tarjeta:%i, Telefono:%i, Nombre de usuario:%s, Contrase�a:%s, Tipo:%c", nombre,apellidos,DNI,tarjeta,telefono,username,contrasena,tipo);
		//Aqui se hace el registro en BD del usuario
		seleccion = 1;
		break;

	case 3:
		exit(-1);
		break;
	}
	}


	return 0;
}

