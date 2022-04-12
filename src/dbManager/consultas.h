#ifndef SQLITE3_CONSULTAS_H_
#define SQLITE3_CONSULTAS_H_

#include "../../lib/sqlite3/sqlite3.h"

int insertNewUser(sqlite3 *db, char nombre[], char username[], char apellidos[], char contrasena[], char tipo, int DNI, int tarjeta, int telefono);



#endif /* SQLITE3_CONSULTAS_H_ */
