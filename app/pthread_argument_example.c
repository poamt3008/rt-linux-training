#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 5

char *mensajes[NUM_THREADS]=
{
    "Soy el Hilo 0",
    "Soy el Hilo 1",
    "Soy el Hilo 2",
    "Soy el Hilo 3",
    "Soy el Hilo 4"
};

/******** Rutina ejecutada por cada Hilo */
void* imprimir(void* arg){
    /* Convertir void* a int* */
    int *id_ptr = (int*)arg;
    //Obtener el valor de ID
    int id = *id_ptr;

    printf("Thread %d iniciado\n", id);
    printf("Mensaje: %s\n", mensajes[id]);

    /* Simular trabajo */
    for(int j=0;j<1000000; j++){
        int prueba=0;
    };

    /*Mensaje de finalizacion de tarea*/
    printf("Thread %d terminando\n", id);

    /* Liberar memoria */
    free(id_ptr);

    pthread_exit(NULL);
}

/***************************************************************
 * Hilo principal
 ***************************************************************/
int main()
{
    pthread_t threads[NUM_THREADS];

    int rc;

    /**********************************************************
     * Crear todo los Hilos
     **********************************************************/
    for(int k = 0; k < NUM_THREADS; k++)
    {
        /* Reservar memoria dinamica para ID del thread */
        int *task_id = (int*)malloc(sizeof(int));

        /*Guardar ID en memoria reservada*/
        *task_id = k;

        printf("Creando thread %d\n", k);

        /* Crear thread*/
        rc = pthread_create(
                &threads[k],
                NULL,
                imprimir,
                (void*)task_id
        );
        /*Verificar error de creacion*/

        if(rc != 0)
        {
            printf("Error creando thread %d\n", k);
            exit(EXIT_FAILURE);
        }
    }

    /*----------------------------------------------------------
     * Finalizar SOLO el main thread
     *
     * Los demas threads continuan ejecutandose
     *---------------------------------------------------------*/
    printf("Soy el hilo main, terminando mi proceso \n");
    pthread_exit(NULL);
}