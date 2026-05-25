# include <stdio.h>
#include <pthread.h>

#define ITERACIONES 100000

/*Variable Global*/
int contador = 0;
void* hilo_suma(void *arg){
for (int i=0; i<ITERACIONES; i++){
	contador++;
}
return NULL;
}

void* hilo_resta(void *arg){
    for (int i=0; i<ITERACIONES;i++){
	contador--;
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
