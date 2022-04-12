/*
 * consultas.h
 *
 *  Created on: 12 abr 2022
 *      Author: borja
 */

#ifndef SQLITE3_CONSULTAS_H_
#define SQLITE3_CONSULTAS_H_

int insertNewUser(sqlite3 *db, char nombre[], char username[], char apellidos[], char contrasena[], char tipo, int DNI, int tarjeta, int telefono);



#endif /* SQLITE3_CONSULTAS_H_ */
