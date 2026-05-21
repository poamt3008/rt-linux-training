#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 5

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
    pthread_t threads[NUM_THREADS];
    int ids[NUM_THREADS];

    for(int t = 0; t < NUM_THREADS; t++)
    {
        ids[t] = t;

        printf("Creando hilo %d\n", t);

        pthread_create(
            &threads[t],
            NULL,
            imprimir,
            &ids[t]
        );
    }

    printf("Main thread terminando...\n");

    pthread_exit(NULL);
}