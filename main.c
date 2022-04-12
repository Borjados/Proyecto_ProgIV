#include <stdio.h>
#include <stdlib.h>
#include "admin/admin.h"
#include "sqlite3/sqlite3.h"


int main(){

	sqlite3 *db;

	int result = sqlite3_open("test.sqlite", &db);

	if (result != SQLITE_OK) {
		printf("Error opening database\n");
		return result;
	}

	printf("Database opened\n") ;

	inicio(*db);

	return 0;
}

