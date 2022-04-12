#include "consultas.h"
#include <stdio.h>

int insertNewUser(sqlite3 *db, char nombre[], char username[], char apellidos[], char contrasena[], char tipo, int DNI, int tarjeta, int telefono){
	sqlite3_stmt *stmt;

		char sql[] = "insert into Usuario (dni, username, nombre, apellidos, num_tarjeta, contrasenya, telefono, tipo_usuario) values (?, ?, ?, ?, ?, ?, ?, ?)";
		int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (INSERT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("SQL query prepared (INSERT)\n");

		sqlite3_bind_int(stmt, 1, DNI);
		sqlite3_bind_text(stmt, 2, username, strlen(username), SQLITE_STATIC);
		sqlite3_bind_text(stmt, 3, nombre, strlen(nombre), SQLITE_STATIC);
		sqlite3_bind_text(stmt, 4, apellidos, strlen(apellidos), SQLITE_STATIC);
		sqlite3_bind_int(stmt, 5, tarjeta);
		sqlite3_bind_text(stmt, 6, contrasena, strlen(contrasena), SQLITE_STATIC);
		sqlite3_bind_int(stmt, 7, telefono);
		sqlite3_bind_text(stmt, 8, tipo, strlen(tipo), SQLITE_STATIC);


		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			printf("Error inserting new data into usuario table\n");
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			printf("Error finalizing statement (INSERT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("Prepared statement finalized (INSERT)\n");

		return SQLITE_OK;
}

int updateBonos(sqlite3 *db, char tipo, int precio){
	sqlite3_stmt *stmt;

	char sql[] = "UPDATE Bono SET precio=? WHERE tipo_bono=?";
	int result = sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	printf("SQL query prepared (UPDATE)\n");

	sqlite3_bind_int(stmt, 1, precio);
	sqlite3_bind_text(stmt, 2, tipo, strlen(tipo), SQLITE_STATIC);

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error updating new data into bono table\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (UPDATE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (INSERT)\n");

	return SQLITE_OK;
}

int newInicio(sqlite3 *db, char nombre[], char contrasena) {
	sqlite3_stmt *stmt;
	char sql[] =
			"Select contrasenya, tipo_usuario from Usuario where username = ?";
	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (SELECT)\n");

	char contrasenya[200];
	char tipo_usuario[200];

	do {
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) {
			strcpy(contrasenya, (char*) sqlite3_column_text(stmt, 0));
			strcpy(tipo_usuario, (char *) sqlite3_column_text(stmt, 1);
					printf("ID: %d Name: %s\n", id, name);
				}
			} while (result == SQLITE_ROW);

			result = sqlite3_finalize(stmt);
			if (result != SQLITE_OK) {
				printf("Error finalizing statement (SELECT)\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}

			printf("Prepared statement finalized (SELECT)\n");

			if (contrasena == contrasenya) {
				if (tipo_usuario == "estudiante" || tipo_usuario == "regular" || tipo_usuario == "profesor") {
					result = 1;
				} else if (tipo_usuario == "Administrador") {
					result = 2;
				}
			} else {
				result = 3;
			}

			return result;

		}
