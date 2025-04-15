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
} typedef Nodo;

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

void mostrarTareas(Nodo *lista) {
    printf("\n--- TAREAS PENDIENTES ---\n");
    while (lista != NULL) {
        printf("ID: %d | Desc: %s | Duración: %d mins\n",
               lista->T.TareaID, lista->T.Descripcion, lista->T.Duracion);
        lista = lista->Siguiente;
    }
}

int main() {
    Nodo *pendientes = NULL;
    int tareaID = 1000;
    int continuar;
    char desc[MAX_DESC];
    int duracion;

    do {
        printf("\nIngrese descripción de la tarea: ");
        gets(desc);
        

        printf("Ingrese duración (10-100): ");
        scanf("%d", &duracion);

        Nodo *nueva = crearNodo(tareaID++, desc, duracion);
        insertarTarea(&pendientes, nueva);

        printf("¿Desea agregar otra tarea? (1: Sí / 0: No): ");
        scanf("%d", &continuar);

    } while (continuar != 0);

    mostrarTareas(pendientes);
    return 0;
}
