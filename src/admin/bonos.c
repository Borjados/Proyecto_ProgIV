#include <stdio.h>
#include <stdlib.h>
#include "bonos.h"
#include "admin.h"

void bonos(sqlite3 *db){
	int sel; //selección
		printf("BONOS\n");
		fflush(stdout);
		printf("------------------------------\n");
		fflush(stdout);
		printf("1.1 día\n");
		fflush(stdout);
		printf("2.1 semana\n");
		fflush(stdout);
		printf("3.2 semanas\n");
		fflush(stdout);
		printf("4.1 mes\n");
		fflush(stdout);
		printf("5.Cuatrimestre\n");
		fflush(stdout);
		printf("6.Salir\n");
		fflush(stdout);
		printf("------------------------------\n");
		fflush(stdout);
		printf("El descuento actual es de: %f\n");
		fflush(stdout);

		scanf(" %i", &sel);

		if(sel==1) {
			estadisticas(db);
		} else if(sel==2) {

		} else if(sel==3) {

		} else if(sel==4) {

		} else if(sel==5) {

		} else if(sel==6) {
			adminInicio(db);
		} else {
			bonos(db);
		}


}
