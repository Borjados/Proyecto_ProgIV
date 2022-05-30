#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "admin/menuAdmin.h"
#include "../lib/sqlite3/sqlite3.h"
#include "auth/inicio.h"
#include "cfg/cfg.h"
#include <winsock2.h>
#include "dbManager/consultas.h"

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 6000

#pragma comment(lib,"ws2_32.lib") //Winsock Library

int main(){
    int running = 0;
    char sendBuff[512], recvBuff[512];
	struct sockaddr_in server;
	struct sockaddr_in client;

    /*Config config;
    int error = leer_configuracion(&config);
    if (error) {
        printf("Error loading config file\n");
        exit(error);
    }
    printf("Credenciales: %s, %s\n", config.usuarioAdmin, config.contrasenyaAdmin);*/

	sqlite3 *db;

    //Initialize winsock
    WSADATA wsa;
    SOCKET conn;
    SOCKET s;

    printf("\nInitialising Winsock...");
    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
    {
        printf("Failed. Error Code : %d",WSAGetLastError());
        return 1;
    }

    printf("Initialised.");

    //Create TCP socket
    if((conn = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET)
    {
        printf("Could not create socket : %d" , WSAGetLastError());
    }

    printf("Socket created.\n");

	server.sin_addr.s_addr = inet_addr(SERVER_IP);
	server.sin_family = AF_INET;
	server.sin_port = htons(SERVER_PORT);

	//BIND (the IP/port with socket)
	if (bind(conn, (struct sockaddr*) &server,
		sizeof(server)) == SOCKET_ERROR) {
		printf("Bind failed with error code: %d", WSAGetLastError());
		closesocket(conn);
		WSACleanup();
		return -1;
	}

	printf("Bind done.\n");

	//LISTEN to incoming connections (socket server moves to listening mode)
	if (listen(conn, 1) == SOCKET_ERROR) {
		printf("Listen failed with error code: %d", WSAGetLastError());
		closesocket(conn);
		WSACleanup();
		return -1;
	}

	//ACCEPT incoming connections (server keeps waiting for them)
	printf("Waiting for incoming connections...\n");
	int stsize = sizeof(struct sockaddr);
	s = accept(conn, (struct sockaddr*) &client, &stsize);
	// Using comm_socket is able to send/receive data to/from connected client
	if (conn == INVALID_SOCKET) {
		printf("accept failed with error code : %d", WSAGetLastError());
		closesocket(conn);
		WSACleanup();
		return -1;
	}
	printf("Incomming connection from: %s (%d)\n", inet_ntoa(client.sin_addr),
			ntohs(client.sin_port));

	// Closing the listening sockets (is not going to be used anymore)
	closesocket(conn);


	int result = sqlite3_open("dbproyecto.db", &db);

	if (result != SQLITE_OK) {
		printf("Error opening database\n");
		return result;
	}

	printf("Database opened\n") ;
    while(running == 0){
	    //inicio(db, &running);
        //TODO colocar el socket escuchando al cliente


    	//TODO lo que esta aqui comentado son los comandos que tiene el server para llamar a BD, lo he compilado y tira pero lo comento por si acaso
    	printf("Waiting for incoming commands from client... \n");

    	do{
    		recv(s, recvBuff, sizeof(recvBuff), 0);

    		//printf("Command received: %s \n", recvBuff);

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
    			int cont = 1;

    			recv(s, recvBuff, sizeof(recvBuff), 0);

    			while(strcmpi(recvBuff, "REGISTRO-END") != 0){
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
    				    strcpy(&tipo,recvBuff); //strcpy pide *char
    				    recv(s, recvBuff, sizeof(recvBuff), 0);
    				    break;
    				case 9:
    				    cont = 0;
                        int card = atoi(tarjeta);
                        int tel = atoi(telefono);
    				    int ret = insertNewUser(db, nombre, username, apellidos, contrasena, &tipo, DNI, card, tel);
    				    if(ret == 0){
    				    	strcpy(sendBuff, "OK");
    				    	send(s, sendBuff, sizeof(sendBuff), 0);
    				    }
    				    else{
    				    	strcpy(sendBuff, "ERROR");
    				    	send(s, sendBuff, sizeof(sendBuff), 0);
    				    }
    				    recv(s, recvBuff, sizeof(recvBuff), 0);
    				    break;
    				}

    			}

    		}
    		else if(strcmpi(recvBuff, "INICIO") == 0){
    			char nombre[20];
    		    char contrasena[20];
    		    int cont = 1;
    		    int valor;

    		    recv(s, recvBuff, sizeof(recvBuff), 0);

    		    while(strcmpi(recvBuff, "INICIO-END") != 0){
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
    		        		newInicio(db, nombre, contrasena, &valor);
    		        		if (valor == 1){
        				    	strcpy(sendBuff, "OK");
        				    	send(s, sendBuff, sizeof(sendBuff), 0);
    		        		}
    		        		else{
        				    	strcpy(sendBuff, "ERROR");
        				    	send(s, sendBuff, sizeof(sendBuff), 0);
    		        		}
    		        		recv(s, recvBuff, sizeof(recvBuff), 0);
    		        		break;
    		        }
    		    }
    		}

    		else if(strcmpi(recvBuff, "INICIOA") == 0){
    			char nombre[20];
    		    char contrasena[20];
    		    int cont = 1;
    		    int valor;

    		    recv(s, recvBuff, sizeof(recvBuff), 0);

    		    while(strcmpi(recvBuff, "INICIOA-END") != 0){
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
    		        		newInicioA(db, nombre, contrasena, &valor);
    		        		if (valor == 1){
        				    	strcpy(sendBuff, "OK");
        				    	send(s, sendBuff, sizeof(sendBuff), 0);
    		        		}
    		        		else{
        				    	strcpy(sendBuff, "ERROR");
        				    	send(s, sendBuff, sizeof(sendBuff), 0);
    		        		}
    		        		recv(s, recvBuff, sizeof(recvBuff), 0);
    		        		break;
    		        }
    		    }
    		}

    		else if(strcmpi(recvBuff, "STAT_TARIFA") == 0){
    			int valor;
    			recv(s, recvBuff, sizeof(recvBuff), 0);
    			while(strcmp(recvBuff, "STAT_TARIFA-END") != 0){
    				tarifaMasUsada(db,  &valor);
    				switch (valor){
    				case 1:
				    	strcpy(sendBuff, "Bono Diario");
				    	send(s, sendBuff, sizeof(sendBuff), 0);
				    	break;
    				case 2:
    					strcpy(sendBuff, "Bono semanal");
    					send(s, sendBuff, sizeof(sendBuff), 0);
    					break;
    				case 3:
    					strcpy(sendBuff, "Bono de 2 semanas");
    					send(s, sendBuff, sizeof(sendBuff), 0);
    					break;
    				case 4:
    					strcpy(sendBuff, "Bono mensual");
    					send(s, sendBuff, sizeof(sendBuff), 0);
    					break;
    				case 5:
    					strcpy(sendBuff, "Bono cuatrimestral");
    					send(s, sendBuff, sizeof(sendBuff), 0);
    					break;
    				}
    				recv(s, recvBuff, sizeof(recvBuff), 0);
    			}
    		}//TODO completar las funciones y crear las peticiones en el cliente
            else if(strcmpi(recvBuff, "STAT_COMM_USER") == 0){
            	int valor;
            	recv(s, recvBuff, sizeof(recvBuff), 0);
            	while(strcmp(recvBuff, "STAT_COMM_USER-END") != 0){
            		usuarioMasComun(db, &valor);
    				switch (valor){
    				case 1:
				    	strcpy(sendBuff, "Estudiante");
				    	send(s, sendBuff, sizeof(sendBuff), 0);
				    	break;
    				case 2:
    					strcpy(sendBuff, "Profesor");
    					send(s, sendBuff, sizeof(sendBuff), 0);
    					break;
    				case 3:
    					strcpy(sendBuff, "Regular");
    					send(s, sendBuff, sizeof(sendBuff), 0);
    					break;
    				}
            	}
            }
            else if(strcmpi(recvBuff, "STAT_FREQ_USER") == 0){}

            else if(strcmpi(recvBuff, "UPDATE_BONOS") == 0){
    			char tipo[20];
    			int cont = 1;
    		    char precio[20];
            	recv(s, recvBuff, sizeof(recvBuff), 0);
            	while(strcmp(recvBuff, "UPDATE_BONOS-END") != 0){
            		switch (cont){
    				case 1:
		        		cont = cont + 1;
		        		strcpy(tipo,recvBuff);
		        		recv(s, recvBuff, sizeof(recvBuff), 0);
		        		break;
    				case 2:
		        		cont = cont + 1;
		        		strcpy(precio,recvBuff);
		        		recv(s, recvBuff, sizeof(recvBuff), 0);
		        		break;
    				case 3:
    				    cont = 0;
                		int type = atoi(tipo);
                		int preis = atoi(precio);
                		updateBonos(db, type, preis);
    				    recv(s, recvBuff, sizeof(recvBuff), 0);
    				    break;
            		}
            	}
            }
            else if(strcmpi(recvBuff, "ALQUILAR") == 0){}
            else if(strcmpi(recvBuff, "DEVOLVER") == 0){}
            else if(strcmpi(recvBuff, "END") == 0){
            	exit(-1);
            }
    	}while (1);




    }

	sqlite3_close(db);

    closesocket(s);
    WSACleanup();

    return 0;
}

