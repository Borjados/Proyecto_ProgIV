#include <stdio.h>
#include <stdlib.h>
#include "estadisticas.h"
#include "admin.h"


void estadisticas(sqlite3 *db){
	int sel; //selección
	printf("MENÚ ESTADÍSTICAS\n");
	fflush(stdout);
	printf("------------------------------\n");
	fflush(stdout);
	printf("1.Tarifa más solicitada\n");
	fflush(stdout);
	printf("2.Tipos de usuario más comunes\n");
	fflush(stdout);
	printf("3.Usuarios más frecuentes\n");
	fflush(stdout);
	printf("4.Volver\n");
	fflush(stdout);
	printf("------------------------------\n");
	fflush(stdout);

	scanf(" %i", &sel);

	if(sel==1) {

	} else if(sel==2) {

	} else if(sel==3) {

	} else if(sel==4) {
		adminInicio(db);
	} else {
		printf("ya me joderia");
		estadisticas(db);
	}

}
