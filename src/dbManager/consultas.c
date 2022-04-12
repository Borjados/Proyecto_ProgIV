#include "consultas.h"
#include <stdio.h>

int insertNewUser(sqlite3 *db, char nombre[], char username[], char apellidos[], char contrasena[], char tipo, int DNI, int tarjeta, int telefono){
	sqlite3_stmt *stmt;

		char sql[] = "insert into usuario (id, nombre, username, apellidos, contrasena, tipo, DNI, tarjeta, telefono) values (NULL, ?, ?, ?, ?, ?, ?, ?, ?)";
		int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (INSERT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("SQL query prepared (INSERT)\n");

		sqlite3_bind_text(stmt, 1, nombre, strlen(nombre), SQLITE_STATIC);
		sqlite3_bind_text(stmt, 2, username, strlen(username), SQLITE_STATIC);
		sqlite3_bind_text(stmt, 3, apellidos, strlen(apellidos), SQLITE_STATIC);
		sqlite3_bind_text(stmt, 4, contrasena, strlen(contrasena), SQLITE_STATIC);
		sqlite3_bind_text(stmt, 5, tipo, strlen(tipo), SQLITE_STATIC);
		sqlite3_bind_int(stmt, 6, DNI);
		sqlite3_bind_int(stmt, 7, tarjeta);
		sqlite3_bind_int(stmt, 8, telefono);

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

	char sql[] = "UPDATE Bonos set precio=? WHERE where tipo=?";
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
