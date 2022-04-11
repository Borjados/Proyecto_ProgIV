#include <stdio.h>
#include <stdlib.h>
#include "admin.h"
#include "estadisticas.h"
#include "inicio.h"

void adminInicio(){

	printf("¡BIENVENIDO ADMINISTRADOR!\n");
	fflush(stdout);
	printf("------------------------------\n");
	fflush(stdout);
	printf("1.Ver estadísticas\n");
	fflush(stdout);
	printf("2.Modificar Bonos\n");
	fflush(stdout);
	printf("3.Acceder a los ficheros\n");
	fflush(stdout);
	printf("4.Salir\n");
	fflush(stdout);

	int sel; //selección
	scanf(" %i", &sel);

	if(sel==1) {
		estadisticas();
	} else if(sel==2) {
		bonos();
	} else if(sel==3) {
		ficheros();
	} else if(sel==4) {
		//Aqui llamar a clase iniciar sesion xddddddddddddddddddddddddddddd
		inicio();
	} else {
		printf("ya me joderia");
		adminInicio();
	}

}

