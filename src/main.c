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

    char sendBuff[512], recvBuff[512];

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
	    //inicio(db, &running);
        //TODO colocar el socket escuchando al cliente


    	//TODO lo que esta aqui comentado son los comandos que tiene el server para llamar a BD, lo he compilado y tira pero lo comento por si acaso
    	/*printf("Waiting for incoming commands from client... \n");

    	do{
    		recv(s, recvBuff, sizeof(recvBuff), 0);

    		printf("Command received: %s \n", recvBuff);

    		if(strcmp(recvBuff, "REGISTRO") == 0){
    			int selecadmin, bono;
    			char DNI[10];
    			char nombre[20];
    			char username[20];
    			char apellidos[30];
    			char contrasena[20];
    			char tarjeta[20];
    			char telefono[20];
    			char tipo;
    			int cont = 0;

    			recv(s, recvBuff, sizeof(recvBuff), 0);

    			while(strcmp(recvBuff, "REGISTRO-END") != 0){
    				switch (cont){
    				case 1:
    					cont = cont + 1;
    					strcpy(nombre,recvBuff);
    					recv(s, recvBuff, sizeof(recvBuff), 0);
    					break;
    				case 2:
    				    cont = cont + 1;
    				    strcpy(apellidos,recvBuff);
    				    recv(s, recvBuff, sizeof(recvBuff), 0);
    				    break;
    				case 3:
    				    cont = cont + 1;
    				    strcpy(DNI,recvBuff);
    				    recv(s, recvBuff, sizeof(recvBuff), 0);
    				    break;
    				case 4:
    				    cont = cont + 1;
    				    strcpy(tarjeta,recvBuff);
    				    recv(s, recvBuff, sizeof(recvBuff), 0);
    				    break;
    				case 5:
    				    cont = cont + 1;
    				    strcpy(telefono,recvBuff);
    				    recv(s, recvBuff, sizeof(recvBuff), 0);
    				    break;
    				case 6:
    				    cont = cont + 1;
    				    strcpy(username,recvBuff);
    				    recv(s, recvBuff, sizeof(recvBuff), 0);
    				    break;
    				case 7:
    				    cont = cont + 1;
    				    strcpy(contrasena,recvBuff);
    				    recv(s, recvBuff, sizeof(recvBuff), 0);
    				    break;
    				case 8:
    				    cont = cont + 1;
    				    strcpy(tipo,recvBuff);
    				    recv(s, recvBuff, sizeof(recvBuff), 0);
    				    break;
    				case 9:
    				    cont = 0;
    				    insertNewUser(db, nombre, username, apellidos, contrasena, tipo, DNI, tarjeta, telefono);
    				    recv(s, recvBuff, sizeof(recvBuff), 0);
    				    break;
    				}

    			}

    		}
    		else if(strcmp(recvBuff, "INICIO") == 0){
    			char nombre[20];
    		    char contrasena[20];
    		    int cont = 0;
    		    int valor;

    		    recv(s, recvBuff, sizeof(recvBuff), 0);

    		    while(strcmp(recvBuff, "INICIO-END") != 0){
    		    	switch (cont){
    		        	case 1:
    		        		cont = cont + 1;
    		        		strcpy(nombre,recvBuff);
    		        		recv(s, recvBuff, sizeof(recvBuff), 0);
    		        		break;
    		        	case 2:
    		        		cont = cont + 1;
    		        		strcpy(contrasena,recvBuff);
    		        		recv(s, recvBuff, sizeof(recvBuff), 0);
    		        		break;
    		        	case 3:
    		        		cont = 0;
    		        		newInicio(db, nombre, contrasena, valor);
    		        		recv(s, recvBuff, sizeof(recvBuff), 0);
    		        		break;
    		        }
    		    }
    		}
    	}while (1);



*/
    }

	sqlite3_close(db);

    closesocket(s);
    WSACleanup();

    return 0;
}

