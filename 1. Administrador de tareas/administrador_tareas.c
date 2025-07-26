#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "administrador_tareas.h"
#include "utilidades.h"

#define FILENAME "tareas.bin"

void agregar_tarea(){

    limpiar_consola();
    printf("\t.: Agregar tarea :.\n\n");

    FILE *archivo = fopen(FILENAME, "ab");
    if(archivo == NULL){
        printf("\aError al abrir el archivo\n\n");
        return;
    }

    Tarea tarea, temp;

    printf("Nombre de la tarea: ");
    fgets(tarea.titulo, size_tarea, stdin);
    tarea.titulo[strcspn(tarea.titulo, "\n")] = '\0';
    tarea.status = 0;

    FILE *lectura = fopen(FILENAME, "rb");
    int id_actual = 0;
    while(fread(&temp, sizeof(Tarea), 1, lectura) == 1){
        if (temp.id > id_actual)
            id_actual = temp.id;
    }
    fclose(lectura);
    tarea.id = id_actual + 1;

    fwrite(&tarea, sizeof(Tarea), 1, archivo);

    fclose(archivo);

    printf("\nTarea guardada exitosamente con el ID: %d\n\n", tarea.id);
}

void listar_tarea(){
    
    limpiar_consola();
    printf("\t.: Ver tareas :.\n\n");

    FILE *archivo = fopen(FILENAME, "rb");
    if(archivo == NULL){
        printf("\aError al abrir el archivo\n\n");
        return;    
    }

    Tarea temp;

    while(fread(&temp, sizeof(Tarea), 1, archivo) == 1)
        printf("ID: %d | Tarea: %s Estado: %s\n", temp.id, temp.titulo, temp.status ? "Completada" : "Pendiente");
    printf("\n");

    fclose(archivo);
}

void completar_tarea(){
    limpiar_consola();
    printf("\t.: Marcar tarea como completada :.\n\n");

    FILE *archivo = fopen(FILENAME, "rb+");
    if(archivo == NULL){
        printf("\aError al abrir el archivo\n\n");
        return;
    }

    Tarea temp;
    int eleccion;

    printf("Tarea a marcar como completa: ");
    scanf("%d", &eleccion);
    getchar();
    while(fread(&temp, sizeof(Tarea), 1, archivo) == 1){
        if(eleccion == temp.id && temp.status == 0){
            temp.status = 1;
            fseek(archivo, -1 * sizeof(Tarea), SEEK_CUR);
            fwrite(&temp, sizeof(Tarea), 1, archivo);
            fclose(archivo);
            printf("\nTarea %d: %s, marcada como completada\n\n", temp.id, temp.titulo);
            return;
        }else if(eleccion == temp.id && temp.status == 1){
            printf("\nLa tarea %d ya está completada\n\n", eleccion);
            fclose(archivo);
            return;
        }
    }
    printf("\nTarea %d no encontrada\n\n", eleccion);
    fclose(archivo);
}

void eliminar_tarea(){
    limpiar_consola();
    printf("\t.: Eliminar tarea :.\n\n");

    FILE *archivo = fopen(FILENAME, "rb");
    if(archivo == NULL){
        printf("\aError al abrir el archivo de tareas\n\n");
        return;
    }

    int eleccion, bandera = 0;
    Tarea tareaTemp;

    printf("Tarea a eliminar: ");
    scanf("%d", &eleccion);
    getchar();

    while(fread(&tareaTemp, sizeof(Tarea), 1, archivo) == 1){
        if(tareaTemp.id == eleccion){
            bandera = 1;
            break;
        }
    }

    if(bandera == 1){

        rewind(archivo);

        FILE *archivoTemp = fopen("archivoTemporal.bin", "wb");
        if(archivo == NULL){
            printf("\aError al abrir el archivo temporal\n\n");
            return;
        }

        while(fread(&tareaTemp, sizeof(Tarea), 1, archivo) == 1){
            if(tareaTemp.id != eleccion)
                fwrite(&tareaTemp, sizeof(Tarea), 1, archivoTemp);
        }

        remove(FILENAME);
        rename("archivoTemporal.bin", FILENAME);

        printf("\nTarea %d eliminada\n\n", eleccion);
        fclose(archivoTemp);
    }else{
        printf("\nTarea %d no encontrada\n\n", eleccion);
        fclose(archivo);
    }
}