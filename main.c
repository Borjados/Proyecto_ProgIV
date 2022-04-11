#include <stdio.h>
#include <stdlib.h>
#include "admin/admin.h"


int main(){

	inicio();

	//adminInicio();
/*
	setvbuf(stdout, NULL, _IONBF, 0);
	int seleccion, DNI, tarjeta, telefono, selecadmin, bono;
	char nombre[20];
	char username[20];
	char apellidos[30];
	char contrasena[20];
	char tipo;
	int i = 0;

	printf("¡BIENVENIDO A DEUSTOTAQUILLAS!\n");
	printf("------------------------------\n");
	printf("1.Iniciar Sesion\n");
	printf("2.Registrarse\n");
	printf("3.Cerrar\n");

	scanf(" %i", &seleccion);

	while (seleccion != 3){

	switch (seleccion){
	case 1:
		printf("\nINICIAR SESION\n");
		printf("--------------\n");
		printf("Introduzca su nombre: ");
		scanf(" %s", nombre);
		printf("Introduzca su contraseña: ");
		scanf(" %s", contrasena);
		printf("Nombre:%s, Contraseña:%s", nombre, contrasena);
		if(i == 1){
			//Aqui es para la consulta de si el usuario esta registrado, entonces sigue el programa, si no pasa al else
			//Usuario Normal
			printf("No disponible :(");
		}
		else if(i == 2){
			//Aqui es para la consulta de si el usuario esta registrado, entonces sigue el programa, si no pasa al else
			//Administrador

		while (selecadmin != 4){

			printf("¡BIENVENIDO ADMINISTRADOR!\n");
			printf("------------------------------\n");
			printf("1.Ver estadisticas\n");
			printf("2.Modificar Bonos\n");
			printf("3.Acceder a los ficheros\n");
			printf("4.Salir\n");

			scanf(" %i", &selecadmin);

			switch (selecadmin) {
				case 1:
					printf("Aqui se ven las estadisticas. No disponible\n");
				break;
				case 2:
					// Aqui va el codigo para poder modificar los datos de los bonos

					while(bono != 5){
					printf("BONOS\n");
					printf("------------------------------\n");
					printf("Seleccione el bono que desea modificar\n");
					printf("\n");
					printf("1.Diario\n");
					printf("2.Semanal\n");
					printf("3.Mensual\n");
					printf("4.Cuatrimensual\n");
					printf("5.Salir\n");

					scanf(" %i", &bono);

					switch(bono){

					case 1:
						//codigo para modificacion del bono diario
					break;
					case 2:
						//codigo para modificacion del bono semanal
					break;
					case 3:
						//codigo para modificacion del bono mensual
					break;
					case 4:
						//codigo para modificacion del bono diario
					break;
					case 5:
						bono = 5;
					break;

					}
				}

				break;
				case 3:
					printf("Aqui se ven los ficheros. No disponible\n");
				break;
				case 4:
					selecadmin = 4;
				break;
				default:
					break;
			}

		}

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
		scanf(" %s", nombre);
		printf("Introduzca sus apellidos: ");
		scanf(" %s", apellidos);
		printf("Introduzca su DNI: ");
		scanf(" %i", &DNI);
		printf("Introduzca su Tarjeta: ");
		scanf(" %i", &tarjeta);
		printf("Introduzca su Telefono: ");
		scanf(" %i", &telefono);
		printf("Introduzca su nombre de usuario: ");
		scanf(" %s", username);
		printf("Introduzca su contraseña: ");
		scanf(" %s", contrasena);
		printf("Es profersor(p),Estudiante(e) o Regular(r): ");
		scanf(" %s", &tipo);
		printf("Nombre:%s, Apellidos:%s, DNI:%i, Tarjeta:%i, Telefono:%i, Nombre de usuario:%s, Contraseña:%s, Tipo:%c", nombre,apellidos,DNI,tarjeta,telefono,username,contrasena,tipo);
		//Aqui se hace el registro en BD del usuario
		seleccion = 1;
		break;

	case 3:
		exit(-1);
		break;
	}
	}

*/
	return 0;
}

