#include <iostream>
#include "utilidades.h"
#include "agenda.h"
#include "contacto.h"

using namespace std;

int main (){

    int eleccion;
    Agenda agenda;

    do{
        limpiar_consola();
        cout << "\t.: Agenda de contactos :.\n";
        cout << "\n1. Agregar contacto"
            << "\n2. Buscar contacto"
            << "\n3. Editar contacto"
            << "\n4. Eliminar contacto"
            << "\n5. Ver contactos"
            << "\n6. Ordenar contactos"
            << "\n7. Salir"
            << "\n\nOpcion: ";
        cin >> eleccion;
        getchar();
        switch(eleccion){
            case 1:
                agenda.agregarContacto();
                getchar();
                break;
            case 2:
                limpiar_consola();
                cout << "\t.: Buscar contacto :.\n\n";
                agenda.buscarContacto();
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                agenda.leerArchivo();
                break;
            case 6:
                break;
            case 7:
                cout << "\nSaliendo...\n\n";
                break;
            default:
                cout << "\nIngrese una opcion valida\n\n";
                break;
        }
        pausar_consola();
    }while(eleccion != 7);

}