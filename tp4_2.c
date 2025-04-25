#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX 100
#define inicialID 1000
struct Tarea{
    int TareaID;//Numérico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion; // entre 10 – 100
}typedef Tarea ;

struct Nodo{
    Tarea T;
    struct Nodo *Siguiente;
}typedef Nodo;


/*FUNCIONES*/

Nodo * crearTarea(int i);

int main (){

    Nodo *pendientes=NULL;
    Nodo *realizadas=NULL;
    

    

    return 0;
}
Nodo *crearNodoTarea(int i ){
    
    Nodo *nuevo=(Nodo*)malloc(sizeof(Nodo));
    int aux, cont=0;
    char desc[MAX];
    int duracion;
    nuevo->T.TareaID=i+inicialID;
    printf("Ingresar descripcion de la tarea %d:", nuevo->T.TareaID);
    getchar();
    gets(desc);
    int tamCadena = strlen(desc);
    
    nuevo->T.Descripcion=(char*)malloc(tamCadena*sizeof(char)+1);
    strcpy(nuevo->T.Descripcion,desc);
    do {
        printf("Ingrese la duracion de la tarea (entre 10 y 100): ");
        scanf("%d", &nuevo->T.Duracion);
    } while(nuevo->T.Duracion < 10 || nuevo->T.Duracion > 100);
    nuevo->Siguiente=NULL;
    return nuevo;
}

void cargarTareasPendientes(Nodo **tareasP){
    int opcion=1;
    int contador=0;
    Nodo *nuevaTarea;
    while (opcion==1)
    {
        nuevaTarea=crearNodoTarea(contador);
        nuevaTarea->Siguiente=*tareasP;
        *tareasP=nuevaTarea;
        printf("\n¿Quiere cargar otra tarea SI(1)-NO(0):?");
        scanf("%d", &opcion);
        contador++;
    }
    
}
