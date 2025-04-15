#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DESC 100

// Estructura para una Tarea
typedef struct {
    int TareaID;
    char *Descripcion;
    int Duracion; // En minutos (10-100)
} Tarea;

// Nodo para la lista enlazada
typedef struct Nodo {
    Tarea T;
    struct Nodo *Siguiente;
} Nodo;
int main(){
    return 0;
}