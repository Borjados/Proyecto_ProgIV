#ifndef SQLITE3_CONSULTAS_H_
#define SQLITE3_CONSULTAS_H_

#include "../../lib/sqlite3/sqlite3.h"

int insertNewUser(sqlite3 *db, char nombre[], char username[], char apellidos[], char contrasena[], char tipo[], char DNI[], int tarjeta, int telefono);

int updateBonos(sqlite3 *db, char tipo[], int precio);

int newInicio(sqlite3 *db, char *nombre, char *contrasena, int *valor);

void tarifaMasUsada(sqlite3 *db, int *valor);

void usuarioMasComun(sqlite3 *db, int *valor);

int newInicioA(sqlite3 *db, char *nombre, char *contrasena, int *valor);

int alquilar(sqlite3 *db, char *nombre, int tipo, int *valor);

int taquillaelegir(sqlite3 *db, int *valor, int piso);

int taquillaalquilar(sqlite3 *db, int numero);

int usuarioTaquilla(sqlite3 *db, char nombre[], int numero, int Piso, int Bono);

int selectaquilla(sqlite3 *db, char nombre[], int numero);

int taquilladevolver(sqlite3 *db, int numero);

void pisomascomun(sqlite3* db, int *valor);

#endif /* SQLITE3_CONSULTAS_H_ */
