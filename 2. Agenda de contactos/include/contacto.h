#ifndef CONTACTO_H
#define CONACTO_H

#define size_nom 50
#define size_ape 50
#define size_cor 30
#define size_dir 100

class Contacto{
    private:
        unsigned int id;
        char nombre[size_nom];
        char apellido[size_ape];
        unsigned int telefono;
        char correo[size_cor];
        char direccion[size_dir];
    public:
        Contacto();
        unsigned int return_id();
        unsigned int return_tel();
        char* return_name();
        char* return_apellido();
        char* return_correo();
        char* return_direccion();
        void modificar_id(int);
        void llenarDatos();
        void imprimirDatos();
};
#endif