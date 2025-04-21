#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX 100

struct Tarea{
    int TareaID;//Numérico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion; // entre 10 – 100
}typedef Tarea ;

struct Nodo{
    Tarea T;
    struct Nodo *Siguiente;
}typedef Nodo;


Nodo *crearNodo(char *desc, int duracion, int id){
    Nodo * nuevo = (Nodo *) malloc (sizeof(Nodo));
    nuevo->T.Descripcion=(char*)malloc(strlen(desc)+1);
    strcpy(nuevo->T.Descripcion, desc );
    nuevo->T.Duracion=duracion;
    nuevo->T.TareaID=id;
    nuevo->Siguiente=NULL;

    return nuevo;
}
void insertarNodo(Nodo **start, Nodo *Nodo){
    Nodo->Siguiente= *start;
    *start=Nodo;
}

void mostrarTareas( Nodo *pendientes){
   
    while (pendientes!=NULL)
    {
        printf("\nID:%d  //  Descripcion:%s //Duracion:%d", pendientes->T.TareaID, pendientes->T.Descripcion, pendientes->T.Duracion);
        pendientes=pendientes->Siguiente;

    }
    
}


Nodo *buscarNodo(Nodo *start, int idBuscado){
    Nodo * Aux = start;
    while(Aux && Aux->T.TareaID != idBuscado)  
    {
        Aux = Aux->Siguiente;
    }
    return Aux;
}


void QuitarNodo(Nodo **start, int id) {
    Nodo *aux = *start;
    Nodo *prev = NULL;
    
    // Buscamos el nodo a eliminar
    while (aux != NULL && aux->T.TareaID != id) {
        prev = aux;
        aux = aux->Siguiente;
    }

    // Si encontramos el nodo
    if (aux != NULL) {
        if (prev == NULL) { 
            *start = aux->Siguiente;  
        } else {
            prev->Siguiente = aux->Siguiente;  
        }

        
    }
}

int main (){
    Nodo *pendientes=NULL;
    int id=1000;
    int aux, cont=0;
    char desc[MAX];
    int duracion;

    do
    {
        printf("Ingrese la descripcion de la tarea a realizar:");
        getchar();
        gets(desc);

        printf("Ingrese la duracion de la tarea realizada:");
        scanf("%d", &duracion);

        Nodo *new=crearNodo(desc, duracion, id++);
        insertarNodo(&pendientes, new);

        printf("¿Quiere otra tarea pediente?(1-SI  0-NO)");
        scanf("%d", &aux);
        

    } while (aux!=0);
    printf("------TAREAS PENDIENTES------");
    mostrarTareas( pendientes);
    Nodo *realizadas=NULL;
    int busqueda;
    
    printf("Ingrese el ID de la tarea que ya fue realizada: ");
    scanf("%d", &busqueda);
    Nodo *encontrado = buscarNodo(pendientes, busqueda);
        
    insertarNodo(&realizadas, encontrado);
    QuitarNodo(&pendientes, busqueda);  
      
    printf("------TAREAS REALIZADAS------");
    mostrarTareas(realizadas);

    

    return 0;
}