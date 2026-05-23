/*
Programa de creación de hilos

*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

//Defino la cantidad de Hilos mediante una etiqueta
#define NUM_THREADS 5

/***********Rutina llamada por Hilo (tarea)**************/
void* imprimir(void* arg)
{
    int id = *(int*)arg;

    printf("Hola, soy el hilo %d\n", id);

    sleep(2);

    printf("Hilo %d terminando\n", id);

    pthread_exit(NULL);
}


int main()
{
    /****** las variables de los Hilos con pthread_t ************/
    pthread_t threads[NUM_THREADS];
    int ids[NUM_THREADS];   //Creo una identificación del Hilo


    for(int k = 0; k < NUM_THREADS; k++)
    {
        ids[k] = k;

        printf("Creando hilo %d\n", k);
        
        /*********Fucion para CREAR hilos utilizando la variables definidas************/
        pthread_create(
            &threads[k],
            NULL,
            imprimir,
            &ids[k]
        );
    }

    /*****Esta es toda la tarea del proceso main
    Luego se cierra, pero deja que continue los hilos anteriores */

    printf("Hilo main terminando...\n");

    pthread_exit(NULL);
}