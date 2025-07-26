#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#define size_tarea 100

typedef struct{
    int id;
    char titulo[size_tarea];
    int status;
} Tarea;

void agregar_tarea();
void listar_tarea();
void completar_tarea();
void eliminar_tarea();

#endif