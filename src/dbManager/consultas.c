#include "consultas.h"
#include <stdio.h>
#include <string.h>

int insertNewUser(sqlite3 *db, char nombre[], char username[], char apellidos[], char contrasena[], char tipo[], char DNI[], int tarjeta, int telefono){
	sqlite3_stmt *stmt;
    FILE *f;
    f = fopen("Log.txt", "a");

		char sql[] = "insert into Usuario (dni, username, nombre, apellidos, num_tarjeta, contrasenya, telefono, tipo_usuario) values (?, ?, ?, ?, ?, ?, ?, ?)";
		int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (INSERT)\n");
			fprintf(f, "Error preparing statement (INSERT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			fprintf(f, "%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("SQL query prepared (INSERT)\n");
		fprintf(f, "SQL query prepared (INSERT)\n");

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
			fprintf(f, "Error inserting new data into usuario table\n");
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			printf("Error finalizing statement (INSERT)\n");
			fprintf(f, "Error finalizing statement (INSERT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			fprintf(f, "%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("Prepared statement finalized (INSERT)\n");
		fprintf(f, "Prepared statement finalized (INSERT)\n");


		fclose(f);
		return SQLITE_OK;
}

int updateBonos(sqlite3 *db, char tipo[], int precio){
	sqlite3_stmt *stmt;
	FILE *f;
    f = fopen("Log.txt", "a");

	char sql[] = "UPDATE Bono SET precio=? WHERE id_bono=?";
	int result = sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		fprintf(f, "Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		fprintf(f, "%s\n", sqlite3_errmsg(db));
		return result;
	}
	printf("SQL query prepared (UPDATE)\n");
	fprintf(f, "SQL query prepared (UPDATE)\n");

	sqlite3_bind_int(stmt, 1, precio);
	sqlite3_bind_int(stmt, 2, tipo);

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error updating new data into bono table\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (UPDATE)\n");
		fprintf(f, "Error finalizing statement (UPDATE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		fprintf(f, "%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (UPDATE)\n");
	fprintf(f, "Prepared statement finalized (UPDATE)\n");

	fclose(f);
	return SQLITE_OK;
}

int newInicio(sqlite3 *db, char *nombre, char *contrasena, int *valor) {
	sqlite3_stmt *stmt;
	FILE *f;
    f = fopen("Log.txt", "a");
	char sql[] =
			"Select u.contrasenya from Usuario u where u.username = ?";
	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	sqlite3_bind_text(stmt, 1, nombre, strlen(nombre), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		fprintf(f, "Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		fprintf(f, "%s\n", sqlite3_errmsg(db));

		return result;
	}

	printf("SQL query prepared (SELECT)\n");
	fprintf(f, "SQL query prepared (SELECT)\n");

	char contrasenya[200];
	char tipo_usuario[200];

	do {
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) {
			strcpy(contrasenya, (char*) sqlite3_column_text(stmt, 0));
//					printf("ID: %d Name: %s\n", id, name); //TODO $id y $name no estan inicializadas, no existen
				}
			} while (result == SQLITE_ROW);

			result = sqlite3_finalize(stmt);
			if (result != SQLITE_OK) {
				printf("Error finalizing statement (SELECT)\n");
				fprintf(f, "Error finalizing statement (SELECT)\n");
				printf("%s\n", sqlite3_errmsg(db));
				fprintf(f, "%s\n", sqlite3_errmsg(db));
				return result;
			}


			printf("Prepared statement finalized (SELECT)\n");
			printf(f, "Prepared statement finalized (SELECT)\n");

			if (strcmpi(contrasena,contrasenya)==0){
				*valor = 1;
			}
			else{
				*valor = 2;
			}
			fclose(f);
			return result;

}

void tarifaMasUsada(sqlite3 *db, int *valor){
	sqlite3_stmt *stmt;
	FILE *f;
    f = fopen("Log.txt", "a");

	char sql[] = "SELECT u.id_bono FROM Usuario u GROUP BY id_bono ORDER BY COUNT(id_bono) DESC";

	int result = sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		fprintf(f, "Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		fprintf(f, "%s\n", sqlite3_errmsg(db));
	}
	result = sqlite3_step(stmt);
	if (result == SQLITE_ROW) {
		int id = sqlite3_column_int(stmt, 0);
		if (id == 1) {
			*valor = 1;
		}
		else if (id == 2) {
			*valor = 1;
		}
		else if (id == 3) {
			*valor = 1;
		}

		else if (id == 4) {
			*valor = 1;
		}
		else if (id == 5) {
			*valor = 1;
		}
	}
	fclose(f);
}

void usuarioMasComun(sqlite3 *db, int *valor){
	sqlite3_stmt *stmt;
	FILE *f;
    f = fopen("Log.txt", "a");

	char sql[] = "SELECT u.tipo_usuario FROM Usuario u GROUP BY tipo_usuario ORDER BY COUNT(tipo_usuario) DESC";

	int result = sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		fprintf(f, "Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		fprintf(f, "%s\n", sqlite3_errmsg(db));
	}

	result = sqlite3_step(stmt);
	if (result == SQLITE_ROW) {
		const char *id = sqlite3_column_text(stmt, 0);

		if (strcmpi(id, "e") == 0) {
			*valor = 1;
		}
		if (strcmpi(id, "p") == 0) {
			*valor = 2;
		}
		if (strcmpi(id, "r") == 0) {
			*valor = 3;
		}
	}

	fclose(f);

}

int newInicioA(sqlite3 *db, char *nombre, char *contrasena, int *valor) {
	sqlite3_stmt *stmt;
	FILE *f;
    f = fopen("Log.txt", "a");
	char sql[] =
			"Select a.contrasenya from Administrador a where a.usuario = ?";
	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	sqlite3_bind_text(stmt, 1, nombre, strlen(nombre), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		fprintf(f, "Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		fprintf(f, "%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (SELECT)\n");
	fprintf(f, "SQL query prepared (SELECT)\n");

	char contrasenya[200];
	char tipo_usuario[200];

	do {
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) {
			strcpy(contrasenya, (char*) sqlite3_column_text(stmt, 0));
//					printf("ID: %d Name: %s\n", id, name); //TODO $id y $name no estan inicializadas, no existen
				}
			} while (result == SQLITE_ROW);

			result = sqlite3_finalize(stmt);
			if (result != SQLITE_OK) {
				printf("Error finalizing statement (SELECT)\n");
				fprintf(f, "Error finalizing statement (SELECT)\n");
				printf("%s\n", sqlite3_errmsg(db));
				fprintf(f, "%s\n", sqlite3_errmsg(db));

				return result;
			}

			printf("Prepared statement finalized (SELECT)\n");
			fprintf(f, "Prepared statement finalized (SELECT)\n");

			if (strcmpi(contrasena,contrasenya)==0){
				*valor = 1;
			}
			else{
				*valor = 2;
			}
			fclose(f);
			return result;

}

int alquilar(sqlite3 *db, char *nombre, int tipo, int *valor){
	sqlite3_stmt *stmt;
	FILE *f;
    f = fopen("Log.txt", "a");

		char sql[] = "Select b.precio from Bono b where b.id_bono = ?";

		int result = sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);

		sqlite3_bind_int(stmt, 1, tipo);

		if (result != SQLITE_OK) {
			printf("Error preparing statement (INSERT)\n");
			fprintf(f, "Error preparing statement (INSERT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			fprintf(f, "%s\n", sqlite3_errmsg(db));
		}


		printf("Prepared alquilar statement finalized (SELECT)\n");
		fprintf(f, "Prepared alquilar statement finalized (SELECT)\n");


		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) {
			int id = sqlite3_column_int(stmt, 0);
			*valor = id;

		}
		fclose(f);
	return result;
}

int taquillaelegir(sqlite3 *db, int *valor){
	sqlite3_stmt *stmt;
	int cont = 0;
	FILE *f;
    f = fopen("Log.txt", "a");

			char sql[] = "Select t.id_taquilla from Taquilla t where t.taquilla_alquilada = 0";

			int result = sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);

			if (result != SQLITE_OK) {
				printf("Error preparing statement (INSERT)\n");
				fprintf(f, "Error preparing statement (INSERT)\n");
				printf("%s\n", sqlite3_errmsg(db));
				fprintf(f, "%s\n", sqlite3_errmsg(db));
			}


			printf("Prepared alquilar statement finalized (SELECT)\n");
			fprintf(f, "Prepared alquilar statement finalized (SELECT)\n");

			int id = 0;

			result = sqlite3_step(stmt);
			if (result == SQLITE_ROW && cont == 0) {
				id = sqlite3_column_int(stmt, 0);
				//*valor = id;
				cont = cont + 1;

			}

			*valor = id;
			fclose(f);
		return result;
}

int taquillaalquilar(sqlite3 *db, int numero){
	sqlite3_stmt *stmt;
	FILE *f;
    f = fopen("Log.txt", "a");

		char sql[] = "UPDATE Taquilla SET taquilla_alquilada=1 WHERE id_taquilla=?";
		int result = sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (INSERT)\n");
			fprintf(f, "Error preparing statement (INSERT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			fprintf(f, "%s\n", sqlite3_errmsg(db));
			return result;
		}
		printf("SQL query prepared (UPDATE)\n");
		fprintf(f, "SQL query prepared (UPDATE)\n");

		sqlite3_bind_int(stmt, 1, numero);


		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			printf("Error updating new data into bono table\n");
			fprintf(f, "Error updating new data into bono table\n");
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			printf("Error finalizing statement (UPDATE)\n");
			fprintf(f, "Error finalizing statement (UPDATE)\n");
			printf("%s\n", sqlite3_errmsg(db));
			fprintf(f, "%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("Prepared statement finalized (UPDATE)\n");
		fprintf(f, "Prepared statement finalized (UPDATE)\n");

		fclose(f);
		return SQLITE_OK;
}

int usuarioTaquilla(sqlite3 *db, char nombre[], int numero){
	sqlite3_stmt *stmt;
	FILE *f;
    f = fopen("Log.txt", "a");

		char sql[] = "UPDATE Usuario SET id_taquilla=? WHERE username=?";
		int result = sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (INSERT)\n");
			fprintf(f, "Error preparing statement (INSERT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			fprintf(f, "%s\n", sqlite3_errmsg(db));
			return result;
		}
		printf("SQL query prepared (UPDATE)\n");
		fprintf(f, "SQL query prepared (UPDATE)\n");


		sqlite3_bind_int(stmt, 1, numero);
		sqlite3_bind_text(stmt, 2, nombre, strlen(nombre), SQLITE_STATIC);


		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			printf("Error updating new data into bono table\n");
			fprintf(f, "Error updating new data into bono table\n");
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			printf("Error finalizing statement (UPDATE)\n");
			fprintf(f, "Error finalizing statement (UPDATE)\n");
			printf("%s\n", sqlite3_errmsg(db));
			fprintf(f, "%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("Prepared statement finalized (UPDATE)\n");
		fprintf(f, "Prepared statement finalized (UPDATE)\n");

		fclose(f);
		return SQLITE_OK;
}

int usuarioBono(sqlite3 *db, char nombre[], int numero){
	sqlite3_stmt *stmt;
	FILE *f;
    f = fopen("Log.txt", "a");

		char sql[] = "UPDATE Usuario SET id_bono=? WHERE username=?";
		int result = sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (INSERT)\n");
			fprintf(f, "Error preparing statement (INSERT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			fprintf(f, "%s\n", sqlite3_errmsg(db));
			return result;
		}
		printf("SQL query prepared (UPDATE)\n");
		fprintf(f, "SQL query prepared (UPDATE)\n");

		sqlite3_bind_int(stmt, 1, numero);
		sqlite3_bind_text(stmt, 2, nombre, strlen(nombre), SQLITE_STATIC);


		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			printf("Error updating new data into bono table\n");
			fprintf(f, "Error updating new data into bono table\n");
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			printf("Error finalizing statement (UPDATE)\n");
			fprintf(f, "Error finalizing statement (UPDATE)\n");
			printf("%s\n", sqlite3_errmsg(db));
			fprintf(f, "%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("Prepared statement finalized (UPDATE)\n");
		fprintf(f, "Prepared statement finalized (UPDATE)\n");

		fclose(f);
		return SQLITE_OK;
}

int selectaquilla(sqlite3 *db, char nombre[], int *valor){
	sqlite3_stmt *stmt;
	int cont = 0;
	FILE *f;
    f = fopen("Log.txt", "a");

			char sql[] = "Select u.id_taquilla from Usuario u where u.username = ?";

			int result = sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);

			if (result != SQLITE_OK) {
				printf("Error preparing statement (INSERT)\n");
				fprintf(f, "Error preparing statement (INSERT)\n");
				printf("%s\n", sqlite3_errmsg(db));
				fprintf(f, "%s\n", sqlite3_errmsg(db));
			}


			printf("Prepared alquilar statement finalized (SELECT)\n");
			fprintf(f, "Prepared alquilar statement finalized (SELECT)\n");

			sqlite3_bind_text(stmt, 1, nombre, strlen(nombre), SQLITE_STATIC);

			int id = 0;

			result = sqlite3_step(stmt);
			if (result == SQLITE_ROW) {
				id = sqlite3_column_int(stmt, 0);
				//*valor = id;
				cont = cont + 1;

			}

			*valor = id;

			fclose(f);

		return result;

}

int taquilladevolver(sqlite3 *db, int numero){
	sqlite3_stmt *stmt;
	FILE *f;
    f = fopen("Log.txt", "a");

		char sql[] = "UPDATE Taquilla SET taquilla_alquilada=0 WHERE id_taquilla=?";
		int result = sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (INSERT)\n");
			fprintf(f, "Error preparing statement (INSERT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			fprintf(f, "%s\n", sqlite3_errmsg(db));
			return result;
		}
		printf("SQL query prepared (UPDATE)\n");
		fprintf(f, "SQL query prepared (UPDATE)\n");

		sqlite3_bind_int(stmt, 1, numero);


		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			printf("Error updating new data into bono table\n");
			fprintf(f, "Error updating new data into bono table\n");
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			printf("Error finalizing statement (UPDATE)\n");
			fprintf(f, "Error finalizing statement (UPDATE)\n");
			printf("%s\n", sqlite3_errmsg(db));
			fprintf(f, "%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("Prepared statement finalized (UPDATE)\n");
		fprintf(f, "Prepared statement finalized (UPDATE)\n");

		fclose(f);

		return SQLITE_OK;
}
