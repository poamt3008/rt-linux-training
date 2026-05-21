#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5
//------rutina llamada por cada hilo -----//
void* imprimir(void* arg)
{
    int thread_id = *(int*)arg;

    printf("Hola, soy el hilo %d\n", thread_id);

    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    int rc;

    for(int t = 0; t < NUM_THREADS; t++)
    {
        thread_ids[t] = t;

        printf("Creando hilo %d\n", t);

        rc = pthread_create(
                &threads[t],
                NULL,
                imprimir,
                &thread_ids[t]);

        if(rc != 0)
        {
            printf("Error creando hilo %d\n", t);
            exit(EXIT_FAILURE);
        }
    }

    for(int t = 0; t < NUM_THREADS; t++)
    {
        pthread_join(threads[t], NULL);
    }

    printf("Todos los hilos terminaron\n");

    return 0;
}
