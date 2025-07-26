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
        printf("\n2. Ver tareas");
        printf("\n3. Marcar tarea como completada");
        printf("\n4. Eliminar tarea");
        printf("\n5. Salir");
        printf("\n\nOpcion: ");
        scanf("%d", &opcion);
        getchar();
        // Switch con funciones
        switch (opcion) {
            case 1:
                agregar_tarea();
                break;
            case 2:
                listar_tarea();
                break;
            case 3:
                completar_tarea();
                break;
            case 4:
                eliminar_tarea(); 
                break;
            case 5:
                printf("\nSaliendo...\n\n");
                break;
            default:
                printf("\nIngrese una opcion valida\n\n");
        }
        pausar_consola();
    }while(opcion != 5);

    return 0;
}