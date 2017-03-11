#ifndef FOLDER_H
#define FOLDER_H
#include "base.h"
#include "Lista.h"

class Folder:public Base{

public:
    Folder(string nombre, string ruta);
    //Lista elementos;
    int getCantidadElemento();
    void agregarElemento(Base *);
    int buscarElemento(Base *);

    Base *obtenerElemento(int);
    void eliminarElemento(Base *);
    Lista *getLista();
private:
    Lista *elementos;

};

#endif // FOLDER_H
