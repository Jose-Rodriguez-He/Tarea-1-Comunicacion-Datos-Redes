#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

// inet_addr
#include <arpa/inet.h>
#include <unistd.h>

// Librerias para hebras
#include <pthread.h>
#include <semaphore.h>

// Clase cliente
class Client
{

public:

	int network_socket;
	Client(char *IP,int PORT){

	// Crea el stream socket
	network_socket = socket(AF_INET,
							SOCK_STREAM, 0);

	// Incializa el numero de puerto y el de la dirreccion ip
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = inet_addr(IP);
	server_address.sin_port = htons(PORT);

	// Iniciar conexion con el socket
	int connection_status = connect(network_socket,
									(struct sockaddr*)&server_address,
									sizeof(server_address));

	// Error al conectar
	if (connection_status < 0) {
		puts("Error\n");
		exit(EXIT_FAILURE);
	}

	printf("Conexion establecida\n");
	}
	void Enviar(int client_request){
		send(network_socket, &client_request, sizeof(client_request), 0);
		printf("Mensaje enviado\n");
	}
	void Recibir(int disparo){
		recv(network_socket,
			&disparo, sizeof(disparo), 0);
	}

	void Cerrar(){
		close(network_socket);
	}
};


int main(int argc, char* argv[])
{

	char IP[20];
	int PORT;
	//Recibir por parametros la ip y el puerto
	strcpy(IP,argv[1]);
	PORT = atoi(argv[2]);
	printf("1. Read\n");
	printf("2. Write\n");

	int choice;
	scanf("%d", &choice);

	switch (choice) {
	case 1: {
		int client_request = 1;

		//Crear clase cliente
		Client c1(IP,PORT);
		c1.Enviar(client_request);
		break;
	}
	case 2: {
		int client_request = 2;

		// Crear clase cliente
		Client c1(IP,PORT);
		c1.Enviar(client_request);
		break;
	}
	default:
		printf("Input Invalido\n");
		break;
	}

}
