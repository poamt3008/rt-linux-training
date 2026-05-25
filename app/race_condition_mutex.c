#include <stdio.h>
#include <pthread.h>

#define ITERACIONES 100000

int contador = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *hilo_suma(void *arg) {
    for (int i = 0; i < ITERACIONES; i++) {
        pthread_mutex_lock(&mutex);
        contador++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void *hilo_resta(void *arg) {
    for (int i = 0; i < ITERACIONES; i++) {
        pthread_mutex_lock(&mutex);
        contador--;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, hilo_suma, NULL);
    pthread_create(&t2, NULL, hilo_resta, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Resultado final: %d\n", contador);
    printf("Esperado: 0\n");

    return 0;
}