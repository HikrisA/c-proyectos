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
    int id_actual = 0;
    
    FILE *lectura = fopen(FILENAME, "rb");
    while(fread(&temp, sizeof(Contacto), 1, lectura) == 1){
        if(temp.id > id_actual)
            id_actual = temp.id;
    }
    fclose(lectura);
    contacto.id = id_actual + 1;

    fwrite(&contacto, sizeof(Contacto), 1, archivo);

    fclose(archivo);

    cout<<"\nContacto guardado exitosamente con el ID: %d\n\n"<<contacto.id;

};