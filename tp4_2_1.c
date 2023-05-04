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
Tar* NuevaTarea(int id, char* desc, int duracion);
void AgregarTarea(struct NodoTarea** cabeza, struct Tarea* tarea);
NodTar* NuevoNodoTarea(struct Tarea* tarea);
Tar* EliminarTarea(struct NodoTarea** cabeza);
void ImprimirTarea(struct Tarea* tarea);


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
        tareas[i] = tarea;
        AgregarTarea(&pendientes, tarea);
    }

    printf("---TAREAS PENDIENTES---\n");
    while(pendientes != NULL)
    {
        Tar* tarea = EliminarTarea(&pendientes);
        ImprimirTarea(tarea);
        char respuesta[3];

        printf("Se realizo la tarea?(Si/No): ");
        scanf("%s", respuesta);

        if (strcmp(respuesta, "Si")==0)
        {
            AgregarTarea(&realizadas, tarea);
            tareas[tarea->TareaID-1] = NULL;
        }else
        {
            AgregarTarea(&pendientes, tarea);
        }

    }    
    printf("--TAREAS REALIZADAS--\n");
    NodTar* actual = realizadas;
    while(actual != NULL)
    {
        ImprimirTarea(actual->tarea);
        actual = actual->siguiente;
    }

    printf("--TAREAS PENDIENTES--\n");
    for (int i = 0; i < n; i++)
    {
        if (tareas[i] != NULL)
        {
            ImprimirTarea(tareas[i]);
        }
    }
    free(tareas);


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

    void AgregarTarea(NodTar** cabeza, Tar* tarea)
    {
        NodTar* nodo = NuevoNodoTarea(tarea);
        if(*cabeza == NULL)
        {
            *cabeza = nodo;
        }else
        {
            NodTar* actual = *cabeza;
            while(actual->siguiente != NULL)
            {
                actual = actual->siguiente;
            }
            actual->siguiente = nodo;
        }
    }
    NodTar* NuevoNodoTarea(Tar* tarea)
    {
        NodTar* nodo = (NodTar*)malloc(sizeof(NodTar));
        nodo->tarea = tarea;
        nodo->siguiente = NULL;

        return nodo;
    }

    Tar* EliminarTarea(NodTar** cabeza)
    {
        if(*cabeza == NULL)
        {
            return NULL;
        }else
        {
            NodTar* nodo = *cabeza;
            Tar* tarea = nodo->tarea;
            *cabeza = nodo->siguiente;
            free(nodo);

            return tarea;
        }
    }

    void ImprimirTarea(Tar* tarea)
    {
        printf("ID: %d, Descripcion: %s, Duracion: %d\n", tarea->TareaID, tarea->Descripcion, tarea->Duracion);
    }
