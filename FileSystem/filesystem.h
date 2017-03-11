#ifndef FILESYSTEM_H
#define FILESYSTEM_H
#include <typeinfo>
#include "archivo.h"
#include "Folder.h"

class filesystem{
public:
    filesystem();
    void agregarElemento(Folder*,string,int);
    Lista *listarElementos(Folder*);
    Base *cargarElementos(string);
    void eliminarElemento(string);
    void copiarElemento(Folder*,string,Folder*);
    Folder *raiz;

private:
    Base *temp;
    Base *cargarElementos(string,Folder*);
    void eliminarElementos(string,Folder*);
};

#endif // FILESYSTEM_H
