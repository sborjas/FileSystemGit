#include "Folder.h"

Folder::Folder(string nombre, string ruta):Base(nombre,ruta){
    elementos = new Lista();
}

int Folder::getCantidadElemento(){
    return elementos->tamano_lista;
}

void Folder::agregarElemento(Base *el){
    elementos->agregar(el);
}

int Folder::buscarElemento(Base *el){
    return elementos->buscar(el);
}

Base *Folder::obtenerElemento(int pos){
    return elementos->obtener(pos);
}

void Folder::eliminarElemento(Base *el){
    elementos->eliminar(el);
}

Lista *Folder::getLista(){
    return elementos;
}


