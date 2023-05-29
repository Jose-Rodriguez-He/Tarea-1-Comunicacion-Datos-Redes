// inet_addr
#include <arpa/inet.h>

// For threading, link with lpthread
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

// Variables de Semaforo
sem_t x, y;
pthread_t tid;
pthread_t writerthreads[100];
pthread_t readerthreads[100];
int readercount = 0;

class Server
{

public:
	// Variables usadas por el Socket
	int serverSocket, newSocket,port,choice;
	struct sockaddr_in serverAddr;
	struct sockaddr_storage serverStorage;
	socklen_t addr_size;

	Server(int PORT){

		serverSocket = socket(AF_INET, SOCK_STREAM, 0);
		serverAddr.sin_addr.s_addr = inet_addr("192.168.1.3");
		serverAddr.sin_family = AF_INET;
		serverAddr.sin_port = htons(PORT);
		addr_size = sizeof(serverStorage);
		// Bind the socket to the
		// address and port number.
		bind(serverSocket,
			(struct sockaddr*)&serverAddr,
			sizeof(serverAddr));

		// Listen on the socket,
		// with 40 max connection
		// requests queued
		if (listen(serverSocket, 10) == 0)
			printf("Escuchando\n");
		else
			printf("Error\n");
	}
	int Aceptar(){
		// Extract the first
		// connection in the queue
		newSocket = accept(serverSocket,
						(struct sockaddr*)&serverStorage,
						&addr_size);
		printf("\nValor newSocket en clase Server: %d",newSocket);
		return (newSocket);
	}
	int Recibir(){
		recv(newSocket,
			&choice, sizeof(choice), 0);
		printf("\nchoice en clase: %d\n",choice);
		return choice;
	}
	void Cerrar(){
		close(newSocket);
	}

};

// Funcion Lectora
void* reader(void* param)
{
	// Bloquear Semaforo
	sem_wait(&x);
	readercount++;

	if (readercount == 1)
		sem_wait(&y);

	// Desbloquear Semaforo
	sem_post(&x);

	printf("\n%d reader is inside",
		readercount);


	// Bloquear Semaforo
	sem_wait(&x);
	readercount--;

	if (readercount == 0) {
		sem_post(&y);
	}

	// Desbloquear Semaforo
	sem_post(&x);

	printf("\n%d Reader is leaving",
		readercount + 1);
	//Cerrar hebra
	pthread_exit(NULL);
}

// Funcion Escritora
void* writer(void* param)
{
	printf("\nWriter is trying to enter");

	// Bloquear Semaforo
	sem_wait(&y);

	printf("\nWriter has entered");

	// Desbloquear Semaforo
	sem_post(&y);

	printf("\nWriter is leaving");
	//Cerrar hebra
	pthread_exit(NULL);
}

// Driver Code
int main(int argc, char* argv[])
{

	int port,choice,newSocket;
	port =atoi(argv[1]);
	sem_init(&x, 0, 1);
	sem_init(&y, 0, 1);

	Server s1(port);
	s1.Aceptar();
	choice = s1.Recibir();
	printf("\n%d\n",choice);
	newSocket= s1.Aceptar();
	printf("\n%d\n",newSocket);
	// Array for thread
	pthread_t tid[60];

	int i = 0;

	while (1) {

		if (choice == 1) {
			// Creater readers thread
			if (pthread_create(&readerthreads[i++], NULL,reader, &newSocket)!= 0){

				// Error in creating thread
				printf("Error al crear el thread\n");
			}
			else{
				s1.Cerrar();
			}
		}
		else if (choice == 2) {
			// Create writers thread
			if (pthread_create(&writerthreads[i++], NULL, writer, &newSocket)!= 0){

				// Error in creating thread
				printf("Error al crear el thread\n");
			}
			else{
				s1.Cerrar();
			}
		}

		if (i >= 10) {
			// Update i
			i = 0;

			while (i < 10) {
				// Suspend execution of
				// the calling thread
				// until the target
				// thread terminates
				pthread_join(writerthreads[i++],
							NULL);
				pthread_join(readerthreads[i++],
							NULL);
			}

			// Update i
			i = 0;
		}
	}

	return 0;
}
