#include "base.h"

Base::Base(string nombre,string ruta){
    this->nombre = nombre;
    this->ruta = ruta;
}

string Base::getNombre(){
    return nombre;
}

string Base::getRuta(){
    return ruta;
}

void Base::setNombre(string nombre){
    this->nombre = nombre;
}

void Base::setRuta(string ruta){
    this->ruta = ruta;
}

bool Base::operator ==(Base * archivo){
    return (this->nombre == archivo->getNombre() && this->ruta == archivo->getRuta());
}

