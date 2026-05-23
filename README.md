Proyecto de entrenamiento en Sistemas en Tiempo Real (STR) usando Linux embebido, POSIX Threads y Raspberry Pi.

## Objetivos

- Aprender programación concurrente en C
- Implementar tareas periódicas
- Estudiar scheduling en Linux
- Practicar sincronización entre tareas
- Desarrollar arquitectura multitarea embebida
- Integrar GPIO y visión artificial básica

---

## Tecnologías

- Raspberry Pi 3 B+
- Linux Embedded
- POSIX Threads (pthread)
- GCC
- Git / GitHub
- Visual Studio Code Remote SSH

---

## Estructura del proyecto

```text
rt_linux_training/
├── app/
├── core/
├── drivers/
├── tasks/
├── include/
├── docs/
├── scripts/
├── tests/
├── README.md
├── Makefile
└── .gitignore
```

---

## Ejemplos implementados

| Archivo | Descripción |
|---|---|
| pthread_intro.c | Creación básica de hilos |
| pthread_main_exit.c | Terminación del hilo principal usando pthread_exit() |
| pthread_argument_example.c | Paso de argumentos usando punteros y memoria dinámica |

---

## Compilación

Ejemplo:

```bash
gcc app/pthread_intro.c -o app/pthread_intro -lpthread
```

---

## Ejecución

```bash
./app/pthread_intro
```

---

## Conceptos estudiados

- Threads
- Concurrencia
- pthread_create()
- pthread_exit()
- Paso de argumentos a threads
- Punteros
- Memoria dinámica (malloc/free)

---

## Autor

Anderson
