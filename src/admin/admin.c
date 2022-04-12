#include <stdio.h>
#include <stdlib.h>
#include "admin.h"
#include "estadisticas.h"
#include "../auth/inicio.h"

void adminInicio(sqlite3 *db){

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
		estadisticas(db);
	} else if(sel==2) {
		bonos(db);
	} else if(sel==3) {
		ficheros(db);
	} else if(sel==4) {
		inicio(db);
	} else {
		adminInicio(db);
	}

}

