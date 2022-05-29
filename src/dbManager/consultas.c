#include "consultas.h"
#include <stdio.h>
#include <string.h>

int insertNewUser(sqlite3 *db, char nombre[], char username[], char apellidos[], char contrasena[], char tipo[], char DNI[], int tarjeta, int telefono){
	sqlite3_stmt *stmt;

		char sql[] = "insert into Usuario (dni, username, nombre, apellidos, num_tarjeta, contrasenya, telefono, tipo_usuario) values (?, ?, ?, ?, ?, ?, ?, ?)";
		int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (INSERT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("SQL query prepared (INSERT)\n");

		sqlite3_bind_text(stmt, 1, DNI, strlen(DNI), SQLITE_STATIC);
		sqlite3_bind_text(stmt, 2, username, strlen(username), SQLITE_STATIC);
		sqlite3_bind_text(stmt, 3, nombre, strlen(nombre), SQLITE_STATIC);
		sqlite3_bind_text(stmt, 4, apellidos, strlen(apellidos), SQLITE_STATIC);
		sqlite3_bind_int(stmt, 5, tarjeta);
		sqlite3_bind_text(stmt, 6, contrasena, strlen(contrasena), SQLITE_STATIC);
		sqlite3_bind_int(stmt, 7, telefono);
		sqlite3_bind_text(stmt, 8, tipo, strlen(tipo), SQLITE_STATIC);


		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			printf("%s\n", sqlite3_errmsg(db));
			printf("%d\n", result);
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

int updateBonos(sqlite3 *db, char tipo[], int precio){
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

int newInicio(sqlite3 *db, char *nombre, char *contrasena, int *valor) {
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
			strcpy(tipo_usuario, (char *) sqlite3_column_text(stmt, 1));
//					printf("ID: %d Name: %s\n", id, name); //TODO $id y $name no estan inicializadas, no existen
				}
			} while (result == SQLITE_ROW);

			result = sqlite3_finalize(stmt);
			if (result != SQLITE_OK) {
				printf("Error finalizing statement (SELECT)\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}

			printf("Prepared statement finalized (SELECT)\n");

			if (strcmp(contrasena,contrasenya)) {
				if (strcmp(tipo_usuario,"estudiante") || strcmp(tipo_usuario,"regular") || strcmp(tipo_usuario,"profesor")) {
					*valor = 1;
				} else if (strcmp(tipo_usuario,"administrador")) {
					*valor = 2;
				}
			} else {
				*valor = 3;
			}

			return result;

}

void tarifaMasUsada(sqlite3 *db){
	sqlite3_stmt *stmt;

	char sql[] = "SELECT TOP 1 id_bono FROM Usuario GROUP BY id_bono ORDER BY COUNT(id_bono) DESC";

	int result = sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}
	printf("La tarifa mas solicitada es el...\n");
	result = sqlite3_step(stmt);
	if (result == SQLITE_ROW) {
		int id = sqlite3_column_int(stmt, 0);
		if (id == 1) {
			printf("Bono diario");
		}
		if (id == 2) {
			printf("Bono semanal");
		}
		if (id == 3) {
			printf("Bono de 2 semanas");
		}

		if (id == 4) {
			printf("Bono mensual");
		}
		if (id == 5) {
			printf("Bono cuatrimestral");
		}
	}
}

void usuarioMasComun(sqlite3 *db){
	sqlite3_stmt *stmt;

	char sql[] = "SELECT TOP 1 tipo_usuario FROM Usuario GROUP BY tipo_usuario ORDER BY COUNT(tipo_usuario) DESC";

	int result = sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}

	printf("El tipo de usuario mas comun es...\n");
	result = sqlite3_step(stmt);
	if (result == SQLITE_ROW) {
		const char *id = sqlite3_column_text(stmt, 0); //TODO el tipo de id no es válido, recibe "const unsigned char*", pero la parte de unsigned no nos interesa

		if (strcmp(id, "estudiante") == 0) {
			printf("Estudiante.");
		}
		if (strcmp(id, "profesor") == 0) {
			printf("Profesor.");
		}
		if (strcmp(id, "regular") == 0) {
			printf("Usuario externo.");
		}
	}

}


