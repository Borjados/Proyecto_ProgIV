#include <stdio.h>
#include <stdlib.h>
#include "ficheros.h"
#include "menuAdmin.h"

void ficheros(sqlite3 *db){

	int sel; //seleccion
	printf("FICHEROS\n");
	fflush(stdout);
	printf("------------------------------\n");
	fflush(stdout);
	printf("Seleccione el fichero que desea ver:\n");
	fflush(stdout);
	printf("1.Historial usuarios\n");
	fflush(stdout);
	printf("2.Taquillas ocupadas\n");
	fflush(stdout);
	printf("3.Volver\n");
	fflush(stdout);
	printf("------------------------------\n");
	fflush(stdout);

	scanf(" %i", &sel);

	if(sel==1) {

	} else if(sel==2) {

	} else if(sel==3) {
		//adminInicio(db); TODO volver al inicio
	} else {
		ficheros(db);
	}

}

