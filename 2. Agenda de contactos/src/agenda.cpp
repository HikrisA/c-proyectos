#include <iostream>
#include <stdlib.h> 
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
    cout<<"\t.: Agregar Contacto :.\n\n";

    FILE *archivo = fopen(FILENAME, "ab");
    if(archivo == NULL){
        cout<<"\aError al abrir archivo\n\n";
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

    cout<<"\nContacto guardado exitosamente con el ID: "<<contacto.return_id()<<"\n\n";

};

void Agenda::leerArchivo(){
    
    Contacto temp;

    limpiar_consola();
    cout<<"\t.: Leer contactos :.\n\n";

    FILE *archivo = fopen(FILENAME, "rb");
    if(archivo == NULL){
        cout<<"\aError al abrir archivo\n\n";
        return;
    }

    while(fread(&temp, sizeof(Contacto), 1, archivo) == 1){
        temp.imprimirDatos();
    }

    fclose(archivo);

};

void Agenda::buscarContacto(){

    int campoElegido;

    FILE *archivo = fopen(FILENAME, "rb");
    if(archivo == NULL){
        cout<<"\aError al abrir archivo\n\n";
        return;
    }

    cout<<"Buscar por: \n\n"
    <<"1. ID\n"
    <<"2. Nombre\n"
    <<"3. Apellido\n"
    <<"4. Telefono\n"
    <<"5. Correo\n"
    <<"6. Direccion\n"
    <<"7. Salir\n\n"
    <<"Opcion: ";
    cin>>campoElegido;

    switch(campoElegido){
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            cout<<"\nSaliendo...\n\n";    
            break;
        default:
            cout<<"\nIngrese una opcion valida\n\n";
            break;
    }

}