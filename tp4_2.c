#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DESC 100

struct {
    int TareaID;
    char *Descripcion;
    int Duracion;
} typedef Tarea;

struct Nodo {
    Tarea T;
    struct Nodo *Siguiente;
}typedef  Nodo;

Nodo* crearNodo(int id, const char *desc, int duracion) {
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->T.TareaID = id;
    nuevo->T.Descripcion = (char*)malloc(strlen(desc) + 1);
    strcpy(nuevo->T.Descripcion, desc);
    nuevo->T.Duracion = duracion;
    nuevo->Siguiente = NULL;
    return nuevo;
}

void insertarTarea(Nodo **lista, Nodo *nueva) {
    nueva->Siguiente = *lista;
    *lista = nueva;
}

void mostrarTareas(Nodo *lista, const char* titulo) {
    printf("\n--- %s ---\n", titulo);
    if (lista == NULL) {
        printf("No hay tareas.\n");
    }
    while (lista != NULL) {
        printf("ID: %d | Desc: %s | Duracion: %d mins\n",
               lista->T.TareaID, lista->T.Descripcion, lista->T.Duracion);
        lista = lista->Siguiente;
    }
}

void moverTarea(Nodo **pendientes, Nodo **realizadas, int id) {
    Nodo *actual = *pendientes;
    Nodo *anterior = NULL;

    while (actual != NULL && actual->T.TareaID != id) {
        anterior = actual;
        actual = actual->Siguiente;
    }

    if (actual == NULL) {
        printf("Tarea con ID %d no encontrada.\n", id);
        return;
    }

    if (anterior == NULL) {
        *pendientes = actual->Siguiente;
    } else {
        anterior->Siguiente = actual->Siguiente;
    }

    insertarTarea(realizadas, actual);
    printf("Tarea ID %d marcada como realizada.\n", id);
}

int main() {
    Nodo *pendientes = NULL;
    Nodo *realizadas = NULL;
    int tareaID = 1000;
    int continuar;
    char desc[MAX_DESC];
    int duracion;

    // CARGA DE TAREAS
    do {
        printf("\nIngrese descripcion de la tarea: ");
        getchar(); 
        gets(desc);

        printf("Ingrese duracion (10-100): ");
        scanf("%d", &duracion);

        Nodo *nueva = crearNodo(tareaID++, desc, duracion);
        insertarTarea(&pendientes, nueva);

        printf("¿Desea agregar otra tarea? (1: Si / 0: No): ");
        scanf("%d", &continuar);

    } while (continuar != 0);

    
    do {
        mostrarTareas(pendientes, "TAREAS PENDIENTES");

        printf("\n¿Desea marcar una tarea como realizada? (1: Si / 0: No): ");
        scanf("%d", &continuar);

        if (continuar) {
            int id;
            printf("Ingrese el ID de la tarea a marcar como realizada: ");
            scanf("%d", &id);
            moverTarea(&pendientes, &realizadas, id);
        }

    } while (continuar != 0);

    
    mostrarTareas(pendientes, "TAREAS PENDIENTES RESTANTES");
    mostrarTareas(realizadas, "TAREAS REALIZADAS");

    return 0;
}
