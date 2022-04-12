#include <stdio.h>
#include <stdlib.h>
#include "bonos.h"
#include "admin.h"
#include "dbManager/consultas.h"

void bonos(sqlite3 *db){
	int sel; //selección
	int precio;
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

			printf("Que precio quieres poner al bono diario?");
			fflush(stdout);
			scanf(" %i", &precio);

			updateBonos(db, "diaro", precio);

			bonos(db);

		} else if(sel==2) {

			printf("Que precio quieres poner al bono semanal?");
			fflush(stdout);
			scanf(" %i", &precio);

			updateBonos(db, "semanal", precio);

			bonos(db);

		} else if(sel==3) {

			printf("Que precio quieres poner al bono bisemanal?");
			fflush(stdout);
			scanf(" %i", &precio);

			updateBonos(db, "bisemanal", precio);

			bonos(db);

		} else if(sel==4) {

			printf("Que precio quieres poner al bono mensual?");
			fflush(stdout);
			scanf(" %i", &precio);

			updateBonos(db, "mensual", precio);

			bonos(db);

		} else if(sel==5) {

			printf("Que precio quieres poner al bono cuatrimestral?");
			fflush(stdout);
			scanf(" %i", &precio);

			updateBonos(db, "cuatrimestral", precio);

			bonos(db);

		} else if(sel==6) {
			adminInicio(db);
		} else {
			bonos(db);
		}


}
