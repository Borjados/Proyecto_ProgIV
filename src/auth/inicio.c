#include <stdio.h>
#include <stdlib.h>
#include "inicio.h"
#include "iniciarSesion.h"
#include "registro.h"



void inicio(sqlite3 *db, int *running){

	int sel = 0;
	printf("!BIENVENIDO A DEUSTOTAQUILLAS!\n");
	fflush(stdout);
	printf("------------------------------\n");
	fflush(stdout);
	printf("1.Iniciar Sesion\n");
	fflush(stdout);
	printf("2.Registrarse\n");
	fflush(stdout);
	printf("3.Cerrar\n");
	fflush(stdout);

	scanf(" %i", &sel);
	fflush(stdout);

		switch (sel){
		case 1:

			iniciarSesion(db);

		break;


		case 2:

			registro(db);

		break;

		case 3:
            *running = 1;
			exit(-1);

		break;

		}

}
