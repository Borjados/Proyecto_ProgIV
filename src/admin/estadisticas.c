#include <stdio.h>
#include <stdlib.h>
#include "estadisticas.h"
#include "admin.h"
#include "../dbManager/consultas.h"


void estadisticas(sqlite3 *db){
	int sel; //seleccion
	printf("MENU ESTADASTICAS\n");
	fflush(stdout);
	printf("------------------------------\n");
	fflush(stdout);
	printf("1.Tarifa mas solicitada\n");
	fflush(stdout);
	printf("2.Tipo de usuario mas comun\n");
	fflush(stdout);
	printf("3.Usuarios mas frecuentes\n");
	fflush(stdout);
	printf("4.Volver\n");
	fflush(stdout);
	printf("------------------------------\n");
	fflush(stdout);

	scanf(" %i", &sel);

	if(sel==1) {
		tarifaMasUsada(db);
	} else if(sel==2) {
		usuarioMasComun(db);
	} else if(sel==3) {

	} else if(sel==4) {
		adminInicio(db);
	} else {
		estadisticas(db);
	}

}
