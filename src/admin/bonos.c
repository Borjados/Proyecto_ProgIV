#include <stdio.h>
#include <stdlib.h>
#include "bonos.h"
#include "menuAdmin.h"
#include "../dbManager/consultas.h"

void bonos(sqlite3 *db){
	int sel; //selecci�n
	int precio;
		printf("BONOS\n");
		fflush(stdout);
		printf("------------------------------\n");
		fflush(stdout);
		printf("1.1 dia\n");
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
//		printf("El descuento actual es de: %f\n"); //TODO no hay valor de descuento
		fflush(stdout);

		scanf(" %i", &sel);

		if(sel==1) { //Tipos: diario: D, semanal: S, bisemanal: B, mensual: M, cuatrimestre: C

			printf("Que descuento quieres poner al bono diario?");
			fflush(stdout);
			scanf(" %i", &precio);

			updateBonos(db, "D", precio);

			bonos(db);

		} else if(sel==2) {

			printf("Que descuento quieres poner al bono semanal?");
			fflush(stdout);
			scanf(" %i", &precio);

			updateBonos(db, "S", precio);

			bonos(db);

		} else if(sel==3) {

			printf("Que descuento quieres poner al bono bisemanal?");
			fflush(stdout);
			scanf(" %i", &precio);

			updateBonos(db, "B", precio);

			bonos(db);

		} else if(sel==4) {

			printf("Que descuento quieres poner al bono mensual?");
			fflush(stdout);
			scanf(" %i", &precio);

			updateBonos(db, "M", precio);

			bonos(db);

		} else if(sel==5) {

			printf("Que descuento quieres poner al bono cuatrimestral?");
			fflush(stdout);
			scanf(" %i", &precio);

			updateBonos(db, "C", precio);

			bonos(db);

		} else if(sel==6) {
			//adminInicio(db);  //todo volver al menu de inicio
		} else {
			bonos(db);
		}


}
