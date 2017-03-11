#include "archivo.h"

Archivo::Archivo(string nombre,string ruta):Base(nombre,ruta){
    contenido = "";
}

string Archivo::getContenido(){
    return contenido;
}

void Archivo::setContenido(string cont){
    this->contenido = cont;
}
