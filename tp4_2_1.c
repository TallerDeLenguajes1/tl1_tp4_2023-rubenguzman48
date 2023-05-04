#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura Tarea
typedef struct Tarea {
    int TareaID;
    char* Descripcion;
    int Duracion;
}Tar;

// Definición de la estructura NodoTarea para la lista enlazada
typedef struct NodoTarea {
    Tar* tarea;
    struct NodoTarea* siguiente;
}NodTar;

//Funciones
struct Tarea* NuevaTarea(int id, char* desc, int duracion);
void ImprimirTarea(struct Tarea* tarea);
struct NodoTarea* NuevoNodoTarea(struct Tarea* tarea);
void AgregarTarea(struct NodoTarea** cabeza, struct Tarea* tarea);
struct Tarea* EliminarTarea(struct NodoTarea** cabeza);


int main() 
{
    int n;
    printf("Ingrese la cantidad de tareas a cargar: ");
    scanf("%d", &n);
    Tar** tareas = (Tar**)malloc(sizeof(struct Tar*)*n);
    NodTar* pendientes = NULL;
    NodTar* realizadas = NULL;
    for (int i = 0; i < n; i++) {
        int id = i+1;
        char descrip[100];
        int duracion;

        printf("Ingrese la descripcion de la tarea %d: ", id);
        scanf("%s", descrip);
        printf("Ingrese la duracion de la tarea %d (entre 10 y 100): ", id);
        scanf("%d", &duracion);

        struct Tarea* tarea = NuevaTarea(id, descrip, duracion);


    }
    return 0;
}        
    Tar* NuevaTarea(int id, char* descrip, int duracion)
    {
        Tar* tarea = (Tar*)malloc(sizeof(Tar));
        tarea->TareaID = id;
        tarea->Descripcion = (char*)malloc(sizeof(char)*(strlen(descrip)+1));
        strcpy(tarea->Descripcion, descrip);
        tarea->Duracion = duracion;
        return tarea;
    }


