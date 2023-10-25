#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "semaphore.h"

sem_t sem1,sem2;
void funcion1 ();
void funcion2 ();

int x=10;

int main()
{
    pthread_t h1,h2;

    sem_init(&sem1,0,1); // INICIALIZO EL SEMAFORO (SEMAFORO, SI COMPARTO HILOS DE UN MISMO PROCESO, EMPIEZA ABIERTO O CERRADO)
    sem_init(&sem2,0,0); // INICIALIZO EL SEMAFORO (SEMAFORO, SI COMPARTO HILOS DE UN MISMO PROCESO, EMPIEZA ABIERTO O CERRADO)


    pthread_create (&h1,NULL,funcion1,NULL);  // CREO HILO (HILO, SI CONTIENE ALGO, LA FUNCION, SI QUIERO QUE RETORNE ALGO)
    pthread_create (&h2,NULL,funcion2,NULL);  // CREO HILO (HILO, SI CONTIENE ALGO, LA FUNCION, SI QUIERO QUE RETORNE ALGO)

    pthread_join(h1,NULL);   // QUIERO QUE EL MAIN ESPERE QUE TERMINE ESTOS PROCESOS PARA FINALIZAR
    pthread_join(h2,NULL);   // QUIERO QUE EL MAIN ESPERE QUE TERMINE ESTOS PROCESOS PARA FINALIZAR

    sem_destroy(&sem1);      // DESTRUIR EL SEMAFORO(SEMAFORO)
    sem_destroy(&sem2);      // DESTRUIR EL SEMAFORO(SEMAFORO)


    return 0;
}


void funcion1 ()
{
    sem_wait(&sem1);
    x=100;
    x+=50;
    printf("\n%i", x);
    sem_post(&sem2);
}

void funcion2 ()
{
    sem_wait(&sem2);
    x=500;
    x= x/5;
    printf("\n%i", x);
    sem_post(&sem1);
}



