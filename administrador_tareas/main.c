#include <stdio.h>
#include <stdlib.h>
#include "utilidades.h"
#include "administrador_tareas.h"

int main (){

    int opcion;

    do{
        // Menu
        limpiar_consola();
        printf("\t.: Administrador de Tareas :.\n");
        printf("\n1. Agregar tarea");
        printf("const char *restrict format, ...");
        scanf("%d", &opcion);
        // Switch con funciones
        switch (opcion) {
            case 1:
                break;
            case 2:
                printf("\nSaliendo...\n\n");
                break;
            default:
                printf("\nIngrese una opcion valida\n\n");
                pausar_consola();
        }
    }while(opcion != 2);

    return 0;
}