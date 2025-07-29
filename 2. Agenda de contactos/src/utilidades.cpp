#include <iostream>
#include <stdlib.h>
#include "utilidades.h"
using namespace std;

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
        cout << "Presiona ENTER para continuar...";
        getchar();
    #endif
}