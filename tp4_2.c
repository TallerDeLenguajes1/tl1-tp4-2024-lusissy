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
void cargarTareasPendientes(Nodo **tareasP);
void cargarTareasRealizadas(Nodo **pendientes, Nodo**realizadas);
void mostrarTareas(Nodo *tareas, char *titulo);
void liberarLista(Nodo *lista);
int main (){

    Nodo *pendientes=NULL;
    Nodo *realizadas=NULL;
    cargarTareasPendientes(&pendientes);
    mostrarTareas(pendientes, "Pendientes");
    cargarTareasRealizadas(&pendientes, &realizadas);
    mostrarTareas(realizadas, "Realizadas");
    liberarLista(pendientes);
    liberarLista(realizadas);
    
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
void cargarTareasRealizadas(Nodo **pendientes, Nodo**realizadas){
    int opcion=1;
    int idIngresado;
    Nodo **aux=pendientes;

    while (opcion==1)
    {
        printf("\nIngrese el id de la tarea realizada:");
        scanf("%d",&idIngresado);
        aux = pendientes;
        while (*aux!=NULL && (*aux)->T.TareaID!=idIngresado)
        {
            aux=&(*aux)->Siguiente;
        }
        if (*aux!=NULL)
        {
            Nodo *realizada=*aux;
            *aux=(*aux)->Siguiente;

            realizada->Siguiente=  *realizadas;
            *realizadas = realizada;
            
            printf("Tarea completada registrada.\n");
        }else {
            printf("ID invalido. Operacion cancelada.\n");
        }
    printf("\nDesea registrar otra tarea realizada? si(escribir 1)/no(escribir 0):");
    scanf("%d",&opcion);
    }
       
}

void mostrarTareas(Nodo *tareas, char *titulo){
    Nodo *aux;
    printf("\n\nTareas %s", titulo);
    if (tareas!=NULL){
        aux=tareas;
        while (aux!=NULL)
        {
            printf("\nTarea %d: %s\n", aux->T.TareaID, aux->T.Descripcion);
            printf("Duracion: %d", aux->T.Duracion);
            aux=aux->Siguiente;
        }
    }
    else{
        printf("\nVacia");
    }
}
void liberarLista(Nodo *lista) {
    while (lista) {
        Nodo *temp = lista;
        lista = lista->Siguiente;
        free(temp->T.Descripcion); 
        free(temp); 
    }
}