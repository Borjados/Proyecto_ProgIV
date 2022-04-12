#include <stdio.h>
#include <stdlib.h>
#include "admin/admin.h"
#include "../lib/sqlite3/sqlite3.h"
#include "auth/inicio.h"


int main(){

	sqlite3 *db;

	int result = sqlite3_open("test.sqlite", db);

	if (result != SQLITE_OK) {
		printf("Error opening database\n");
		return result;
	}

	printf("Database opened\n") ;

	inicio(db);

	sqlite3_close(db);

	return 0;
}

