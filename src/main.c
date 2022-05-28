#include <stdio.h>
#include <stdlib.h>
#include "admin/menuAdmin.h"
#include "../lib/sqlite3/sqlite3.h"
#include "auth/inicio.h"
#include "cfg/cfg.h"
#include <winsock2.h>



#pragma comment(lib,"ws2_32.lib") //Winsock Library

int main(){
    int running = 0;

    Config config;
    int error = leer_configuracion(&config);
    if (error) {
        printf("Error loading config file\n");
        exit(error);
    }
    printf("Credenciales: %s, %s\n", config.usuarioAdmin, config.contrasenyaAdmin);

	sqlite3 *db;

    //Initialize winsock
    WSADATA wsa;
    SOCKET s;

    printf("\nInitialising Winsock...");
    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
    {
        printf("Failed. Error Code : %d",WSAGetLastError());
        return 1;
    }

    printf("Initialised.");

    //Create TCP socket
    if((s = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET)
    {
        printf("Could not create socket : %d" , WSAGetLastError());
    }

    printf("Socket created.\n");


	int result = sqlite3_open("../dbproyecto.db", &db);

	if (result != SQLITE_OK) {
		printf("Error opening database\n");
		return result;
	}

	printf("Database opened\n") ;
    while(running == 0){
	    inicio(db, &running);
        //TODO colocar el socket escuchando al cliente



    }

	sqlite3_close(db);

    closesocket(s);
    WSACleanup();

    return 0;
}

