#ifndef SQLITE3_CONSULTAS_H_
#define SQLITE3_CONSULTAS_H_

#include "../../lib/sqlite3/sqlite3.h"

int insertNewUser(sqlite3 *db, char nombre[], char username[], char apellidos[], char contrasena[], char tipo[], char DNI[], int tarjeta, int telefono);

int updateBonos(sqlite3 *db, char tipo[], int precio);

int newInicio(sqlite3 *db, char *nombre, char *contrasena, int *valor);

void tarifaMasUsada(sqlite3 *db);

void usuarioMasComun(sqlite3 *db);

#endif /* SQLITE3_CONSULTAS_H_ */
