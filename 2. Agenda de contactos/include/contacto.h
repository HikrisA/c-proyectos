#ifndef CONTACTO_H
#define CONACTO_H

#define size_nom 50
#define size_ape 50
#define size_cor 30
#define size_dir

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
        void llenarDatos();
};
#endif