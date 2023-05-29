// inet_addr
#include <arpa/inet.h>

// Librerias para hebras
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

//Clase servidor
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
		serverAddr.sin_addr.s_addr = INADDR_ANY;
		serverAddr.sin_family = AF_INET;
		serverAddr.sin_port = htons(PORT);
		addr_size = sizeof(serverStorage);
		// Vincular el socket a la dirección ip y el número de puerto.
		bind(serverSocket,
			(struct sockaddr*)&serverAddr,
			sizeof(serverAddr));

		// Escuchar el socket, con 10 solicitudes de conexión máximas en cola
		if (listen(serverSocket, 10) == 0)
			printf("Escuchando\n");
		else
			printf("Error\n");
	}
	int Aceptar(){
		// Extrae la primera conexión en la cola
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


int main(int argc, char* argv[])
{

	int port,choice,newSocket;
	//recibir por parametro el puerto
	port =atoi(argv[1]);

	sem_init(&x, 0, 1);
	sem_init(&y, 0, 1);
	
	//Crear clase server
	Server s1(port);
	s1.Aceptar();
	
	choice = s1.Recibir();
	printf("\n%d\n",choice);
	newSocket= s1.Aceptar();
	printf("\n%d\n",newSocket);
	pthread_t tid[60];

	int i = 0;

	while (1) {

		if (choice == 1) {
			// Creacion de hebras
			if (pthread_create(&readerthreads[i++], NULL,reader, &newSocket)!= 0){

				// Error al crear la hebra
				printf("Error al crear el thread\n");
			}
			else{
				s1.Cerrar();
			}
		}
		else if (choice == 2) {
			// Creacion de hebras
			if (pthread_create(&writerthreads[i++], NULL, writer, &newSocket)!= 0){

				// Error al crear la hebra
				printf("Error al crear el thread\n");
			}
			else{
				s1.Cerrar();
			}
		}

		if (i >= 10) {
			// Actualizar i
			i = 0;

			while (i < 10) {
				// Suspender la ejecución del subproceso de llamada hasta que finalice el subproceso de destino
				pthread_join(writerthreads[i++],
							NULL);
				pthread_join(readerthreads[i++],
							NULL);
			}

			// Actualizar i
			i = 0;
		}
	}

	return 0;
}
