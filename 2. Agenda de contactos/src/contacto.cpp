#include <iostream>
#include <string.h>
#include "utilidades.h"
#include "contacto.h"
using namespace std;


Contacto::Contacto(){
    id = 0;
    strcpy(nombre, "");
    strcpy(apellido, "");
    telefono = 0;
    strcpy(correo, "");
    strcpy(direccion, "");
};

void Contacto::llenarDatos(){
    cout<<"Nombre: ";
    cin>>this->nombre;
    cout<<"Apellido: ";
    cin>>this->apellido;
    cout<<"Telefono: ";
    cin>>this->telefono;
    cout<<"Correo: ";
    cin>>this->correo;
    cout<<"Direccion: ";
    cin>>direccion;
}