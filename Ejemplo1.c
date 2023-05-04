#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura Tarea
struct Tarea {
    int TareaID;
    char* Descripcion;
    int Duracion;
};

// Definición de la estructura NodoTarea para la lista enlazada
struct NodoTarea {
    struct Tarea* tarea;
    struct NodoTarea* siguiente;
};

//Funciones
struct Tarea* NuevaTarea(int id, char* desc, int duracion);
void ImprimirTarea(struct Tarea* tarea);
struct NodoTarea* NuevoNodoTarea(struct Tarea* tarea);
void AgregarTarea(struct NodoTarea** cabeza, struct Tarea* tarea);
struct Tarea* EliminarTarea(struct NodoTarea** cabeza);


int main() {
    int n;
    printf("Ingrese la cantidad de tareas a cargar: ");
    scanf("%d", &n);
    struct Tarea** tareas = (struct Tarea**)malloc(sizeof(struct Tarea*)*n);
    struct NodoTarea* pendientes = NULL;
    struct NodoTarea* realizadas = NULL;
    for (int i = 0; i < n; i++) {
        int id = i+1;
        char desc[100];
        int duracion;
        printf("Ingrese la descripcion de la tarea %d: ", id);
        scanf("%s", desc);
        printf("Ingrese la duracion de la tarea %d (entre 10 y 100): ", id);
        scanf("%d", &duracion);
        struct Tarea* tarea = NuevaTarea(id, desc, duracion);
        tareas[i] = tarea;
        AgregarTarea(&pendientes, tarea);
    }
    printf("Tareas pendientes:\n");
    while (pendientes != NULL) {
        struct Tarea* tarea = EliminarTarea(&pendientes);
        ImprimirTarea(tarea);
        char respuesta[3];
        printf("¿Se realizó la tarea (Si/No)?: ");
        scanf("%s", respuesta);
        if (strcmp(respuesta, "Si") == 0) {
            AgregarTarea(&realizadas, tarea);
            tareas[tarea->TareaID-1] = NULL;
        } else {
            AgregarTarea(&pendientes, tarea);
        }
    }
    printf("Tareas realizadas:\n");
    struct NodoTarea* actual = realizadas;
    while (actual != NULL) {
        ImprimirTarea(actual->tarea);
        actual = actual->siguiente;
    }
    printf("Tareas pendientes:\n");
    for (int i = 0; i < n; i++) {
        if (tareas[i] != NULL) {
            ImprimirTarea(tareas[i]);
        }
    }
    free(tareas);
    return 0;
}

// Función para crear una nueva tarea
struct Tarea* NuevaTarea(int id, char* desc, int duracion) {
    struct Tarea* tarea = (struct Tarea*)malloc(sizeof(struct Tarea));
    tarea->TareaID = id;
    tarea->Descripcion = (char*)malloc(sizeof(char)*(strlen(desc)+1));
    strcpy(tarea->Descripcion, desc);
    tarea->Duracion = duracion;
    return tarea;
}

// Función para imprimir una tarea
void ImprimirTarea(struct Tarea* tarea) {
    printf("ID: %d, Descripcion: %s, Duracion: %d\n", tarea->TareaID, tarea->Descripcion, tarea->Duracion);
}

// Función para crear un nuevo nodo de tarea
struct NodoTarea* NuevoNodoTarea(struct Tarea* tarea) {
    struct NodoTarea* nodo = (struct NodoTarea*)malloc(sizeof(struct NodoTarea));
    nodo->tarea = tarea;
    nodo->siguiente = NULL;
    return nodo;
}

// Función para agregar un nodo de tarea al final de la lista enlazada
void AgregarTarea(struct NodoTarea** cabeza, struct Tarea* tarea) {
    struct NodoTarea* nodo = NuevoNodoTarea(tarea);
    if (*cabeza == NULL) {
        *cabeza = nodo;
    } else {
        struct NodoTarea* actual = *cabeza;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nodo;
    }
}

// Función para eliminar el primer nodo de tarea de la lista enlazada y retornar su tarea
struct Tarea* EliminarTarea(struct NodoTarea** cabeza) {
    if (*cabeza == NULL) {
        return NULL;
    } else {
        struct NodoTarea* nodo = *cabeza;
        struct Tarea* tarea = nodo->tarea;
        *cabeza = nodo->siguiente;
        free(nodo);
        return tarea;
    }
}






















/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura Tarea
struct Tarea {
    int TareaID;
    char* Descripcion;
    int Duracion;
};

// Definición de la estructura NodoTarea para la lista enlazada
struct NodoTarea {
    struct Tarea* tarea;
    struct NodoTarea* siguiente;
};

// Función para crear una nueva tarea
struct Tarea* NuevaTarea(int id, char* desc, int duracion) {
    struct Tarea* tarea = (struct Tarea*)malloc(sizeof(struct Tarea));
    tarea->TareaID = id;
    tarea->Descripcion = (char*)malloc(sizeof(char)*(strlen(desc)+1));
    strcpy(tarea->Descripcion, desc);
    tarea->Duracion = duracion;
    return tarea;
}

//Funciones
void ImprimirTarea(struct Tarea* tarea);
struct NodoTarea* NuevoNodoTarea(struct Tarea* tarea);
void AgregarTarea(struct NodoTarea** cabeza, struct Tarea* tarea);
struct Tarea* EliminarTarea(struct NodoTarea** cabeza);


int main() {
    int n;
    printf("Ingrese la cantidad de tareas a cargar: ");
    scanf("%d", &n);
    struct Tarea** tareas = (struct Tarea**)malloc(sizeof(struct Tarea*)*n);
    struct NodoTarea* pendientes = NULL;
    struct NodoTarea* realizadas = NULL;
    for (int i = 0; i < n; i++) {
        int id = i+1;
        char desc[100];
        int duracion;
        printf("Ingrese la descripcion de la tarea %d: ", id);
        scanf("%s", desc);
        printf("Ingrese la duracion de la tarea %d (entre 10 y 100): ", id);
        scanf("%d", &duracion);
        struct Tarea* tarea = NuevaTarea(id, desc, duracion);
        tareas[i] = tarea;
        AgregarTarea(&pendientes, tarea);
        }
        printf("Tareas pendientes:\n");
        while (pendientes != NULL) {
        struct Tarea* tarea = EliminarTarea(&pendientes);
        ImprimirTarea(tarea);
        char respuesta[3];
        printf("¿Se realizó la tarea (Si/No)?: ");
        scanf("%s", respuesta);
        if (strcmp(respuesta, "Si") == 0) {
        AgregarTarea(&realizadas, tarea);
        tareas[tarea->TareaID-1] = NULL;
        } else {
        AgregarTarea(&pendientes, tarea);
        }
        }
        printf("Tareas realizadas:\n");
        struct NodoTarea* actual = realizadas;
        while (actual != NULL) {
        ImprimirTarea(actual->tarea);
        actual = actual->siguiente;
        }
        printf("Tareas pendientes:\n");
        for (int i = 0; i < n; i++) {
        if (tareas[i] != NULL) {
        ImprimirTarea(tareas[i]);
        }
        }
        return 0;
        }


        // Función para imprimir una tarea
void ImprimirTarea(struct Tarea* tarea) {
    printf("ID: %d, Descripcion: %s, Duracion: %d\n", tarea->TareaID, tarea->Descripcion, tarea->Duracion);
}

// Función para crear un nuevo nodo de tarea
struct NodoTarea* NuevoNodoTarea(struct Tarea* tarea) {
    struct NodoTarea* nodo = (struct NodoTarea*)malloc(sizeof(struct NodoTarea));
    nodo->tarea = tarea;
    nodo->siguiente = NULL;
    return nodo;
}

// Función para agregar un nodo de tarea al final de la lista enlazada
void AgregarTarea(struct NodoTarea** cabeza, struct Tarea* tarea) {
    struct NodoTarea* nodo = NuevoNodoTarea(tarea);
    if (*cabeza == NULL) {
        *cabeza = nodo;
    } else {
        struct NodoTarea* actual = *cabeza;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nodo;
    }
}

// Función para eliminar el primer nodo de tarea de la lista enlazada y retornar su tarea
struct Tarea* EliminarTarea(struct NodoTarea** cabeza) {
    if (*cabeza == NULL) {
        return NULL;
    } else {
        struct NodoTarea* nodo = *cabeza;
        struct Tarea* tarea = nodo->tarea;
        *cabeza = nodo->siguiente;
        free(nodo);
        return tarea;
    }
}

*/