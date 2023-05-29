#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

// inet_addr
#include <arpa/inet.h>
#include <unistd.h>

// For threading, link with lpthread
#include <pthread.h>
#include <semaphore.h>

// Function to send data to
// server socket.
class Client
{

public:

	int network_socket;
	Client(char *IP,int PORT){


	//printf("Client_request: %d\n",client_request);
	// Create a stream socket
	network_socket = socket(AF_INET,
							SOCK_STREAM, 0);

	// Initialise port number and address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = inet_addr(IP);
	server_address.sin_port = htons(PORT);

	// Iniciar coneccion con el socket
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

	//Implementar recibe
	void Cerrar(){
		close(network_socket);
	}
};

// Driver Code
int main(int argc, char* argv[])
{

	char IP[20];
	int PORT;
	strcpy(IP,argv[1]);
	PORT = atoi(argv[2]);
	printf("1. Read\n");
	printf("2. Write\n");

	// Input
	int choice;
	scanf("%d", &choice);
	//pthread_t tid;

	// Create connection
	// depending on the input
	switch (choice) {
	case 1: {
		int client_request = 1;

		// Create thread
		//pthread_create(&tid, NULL,
		//			clienthread,
		//			&client_request);
		Client c1(IP,PORT);
		c1.Enviar(client_request);
		break;
	}
	case 2: {
		int client_request = 2;

		// Create thread
		//pthread_create(&tid, NULL,
		//			clienthread,
		//			&client_request);
		Client c1(IP,PORT);
		c1.Enviar(client_request);
		break;
	}
	default:
		printf("Input Invalido\n");
		break;
	}

	// Suspend execution of
	// calling thread
	//pthread_join(tid, NULL);
}
