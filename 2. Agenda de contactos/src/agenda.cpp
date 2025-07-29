#include <iostream>
#include <stdlib.h> 
#include <string.h>
#include "utilidades.h"
#include "contacto.h"
#include "agenda.h"
using namespace std;

#define FILENAME "data.bin"

Agenda::Agenda(){
    ;
};

void Agenda::agregarContacto(){

    Contacto contacto, temp;
    limpiar_consola();
    cout << "\t.: Agregar Contacto :.\n\n";

    FILE *archivo = fopen(FILENAME, "ab");
    if(archivo == NULL){
        cout << "\aError al abrir archivo\n\n";
        return;
    }

    contacto.llenarDatos();
    unsigned int id_actual = 0;
    
    FILE *lectura = fopen(FILENAME, "rb");
    while(fread(&temp, sizeof(Contacto), 1, lectura) == 1){
        if(temp.return_id() > id_actual)
            id_actual = temp.return_id();
    }
    fclose(lectura);
    contacto.modificar_id(id_actual);

    fwrite(&contacto, sizeof(Contacto), 1, archivo);

    fclose(archivo);

    cout << "\nContacto guardado exitosamente con el ID: " << contacto.return_id() << "\n\n";

};

void Agenda::leerArchivo(){
    
    Contacto temp;

    limpiar_consola();
    cout << "\t.: Leer contactos :.\n\n";

    FILE *archivo = fopen(FILENAME, "rb");
    if(archivo == NULL){
        cout << "\aError al abrir archivo\n\n";
        return;
    }

    while(fread(&temp, sizeof(Contacto), 1, archivo) == 1){
        temp.imprimirDatos();
    }

    fclose(archivo);

};

void Agenda::buscarContacto(){

    int campoElegido;
    unsigned int valorBuscado, flag = 0;
    char nombreBuscado[size_nom] = {}, correoBuscado[size_cor] = {};
    char direccionBuscada[size_dir] = {};
    Contacto temp;

    FILE *archivo = fopen(FILENAME, "rb");
    if(archivo == NULL){
        cout << "\aError al abrir archivo\n\n";
        return;
    }

    cout << "Buscar por: \n\n"
    << "1. ID\n"
    << "2. Nombre\n"
    << "3. Apellido\n"
    << "4. Telefono\n"
    << "5. Correo\n"
    << "6. Direccion\n"
    << "7. Salir\n\n"
    << "Opcion: ";
    cin >> campoElegido;
    getchar();

    switch(campoElegido){
        case 1:
            cout << "\n\t:. Busqueda por ID :.\n\nID: ";
            cin >> valorBuscado;
            getchar();
            while(fread(&temp, sizeof(Contacto), 1, archivo) == 1){
                if(valorBuscado == temp.return_id()){
                    flag = 1;
                    break;
                }
            }
            if(flag){
                cout << "\nRegistro hallado:\n\n";
                temp.imprimirDatos();
                break;
            }
            cout << "\nRegistro con ID: " << valorBuscado << ", no encontrado\n\n";
            break;
        case 2:
            cout << "\n\t:. Busqueda por nombre :.\n\nNombre: ";
            cin >> nombreBuscado;
            getchar();
            while(fread(&temp, sizeof(Contacto), 1, archivo) == 1){
                if(strcmp(nombreBuscado, temp.return_name()) == 0){
                    if(flag){
                        temp.imprimirDatos();
                    }else{
                    cout << "\nRegistros hallados:\n\n";
                    temp.imprimirDatos();
                    flag = 1;
                    }
                }
            }
            if(flag == 0)
                cout << "\nRegistro con nombre: " << nombreBuscado << ", no encontrado\n\n";
            break;
        case 3:
            cout << "\n\t:. Busqueda por apellido :.\n\nApellido: ";
            cin >> nombreBuscado;
            getchar();
            while(fread(&temp, sizeof(Contacto), 1, archivo) == 1){
                if(strcmp(nombreBuscado, temp.return_apellido()) == 0){
                    if(flag){
                        temp.imprimirDatos();
                    }else{
                    cout << "\nRegistros hallados:\n\n";
                    temp.imprimirDatos();
                    flag = 1;
                    }
                }
            }
            if(flag == 0)
                cout << "\nRegistro con apellido: " << nombreBuscado << ", no encontrado\n\n";
            break;
        case 4:
            cout << "\n\t:. Busqueda por telefono :.\n\nTelefono: ";
            cin >> valorBuscado;
            getchar();
            while(fread(&temp, sizeof(Contacto), 1, archivo) == 1){
                if(valorBuscado == temp.return_tel()){
                    flag = 1;
                    break;
                }
            }
            if(flag){
                cout << "\nRegistro hallado:\n\n";
                temp.imprimirDatos();
                break;
            }
            cout << "\nRegistro con numero: " << valorBuscado << ", no encontrado\n\n";
            break;
        case 5:
            cout << "\n\t:. Busqueda por correo :.\n\nCorreo: ";
            cin >> correoBuscado;
            getchar();
            while(fread(&temp, sizeof(Contacto), 1, archivo) == 1){
                if(strcmp(correoBuscado, temp.return_correo()) == 0){
                    flag = 1;
                    break;
                }
            }
            if(flag){
                cout << "\nRegistro hallado:\n\n";
                temp.imprimirDatos();
                break;
            }
            cout << "\nRegistro con correo: " << correoBuscado << ", no encontrado\n\n";
            break;
        case 6:
            cout << "\n\t:. Busqueda por direccion :.\n\nDireccion: ";
            cin >> direccionBuscada;
            getchar();
            while(fread(&temp, sizeof(Contacto), 1, archivo) == 1){
                if(strcmp(direccionBuscada, temp.return_direccion()) == 0){
                    if(flag){
                        temp.imprimirDatos();
                    }else{
                    cout << "\nRegistros hallados:\n\n";
                    temp.imprimirDatos();
                    flag = 1;
                    }
                }
            }
            if(flag == 0)
                cout << "\nRegistro con direccion: " << direccionBuscada << ", no encontrado\n\n";
            break;
        case 7:
            cout << "\nSaliendo...\n\n";    
            break;
        default:
            cout << "\nIngrese una opcion valida\n\n";
            break;
    }

}