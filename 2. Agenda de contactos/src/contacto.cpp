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

unsigned int Contacto::return_id(){
    return this->id;
};

unsigned int Contacto::return_tel(){
    return this->telefono;
};

char* Contacto::return_name(){
    return this->nombre;
};

char* Contacto::return_apellido(){
    return this->apellido;
}

char* Contacto::return_correo(){
    return this->correo;
}

char* Contacto::return_direccion(){
    return this->direccion;
}

void Contacto::modificar_id(int nuevo_id){
    this->id = nuevo_id + 1;
};

void Contacto::llenarDatos(){
    cout << "Nombre: ";
    cin >> this->nombre;
    cout << "Apellido: ";
    cin >> this->apellido;
    cout << "Telefono: ";
    cin >> this->telefono;
    cout << "Correo: ";
    cin >> this->correo;
    cout << "Direccion: ";
    cin >> direccion;
};

void Contacto::imprimirDatos(){
    cout << "ID: " << this->id << "\n"
    << "Nombre: " << this->nombre << "\n"
    << "Apellido: " << this->apellido << "\n"
    << "Telefono: " << this->telefono << "\n"
    << "Correo: " << this->correo << "\n"
    << "Direccion: " << this->direccion << "\n\n";
};