#include <stdlib.h>
#include <stdio.h>
#include "utilidades.h"

void limpiar_consola(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pausar_consola(){
    #ifdef _WIN32
        system("pause");
    #else
        printf("Presiona ENTER para continuar...");
        getchar();
    #endif
}