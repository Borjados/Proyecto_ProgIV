#include <stdio.h>
#include <stdlib.h>
#include "estadisticas.h"
#include "admin.h"

void estadisticas(){
	int sel; //selecci�n
	printf("MEN� ESTAD�STICAS\n");
	fflush(stdout);
	printf("------------------------------\n");
	fflush(stdout);
	printf("1.Tarifas m�s solicitadas\n");
	fflush(stdout);
	printf("2.Tipos de usuario m�s comunes\n");
	fflush(stdout);
	printf("3.Usuarios m�s frecuentes\n");
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
		adminInicio();
	} else {
		printf("ya me joderia");
		estadisticas();
	}

}
