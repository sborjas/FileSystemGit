#ifndef ARCHIVO_H
#define ARCHIVO_H
#include "base.h"
#include <iostream>


class Archivo:public Base{
public:
    Archivo(string nombre, string ruta);
    string getContenido();
    void setContenido(string cont);

private:
    string contenido;
};

#endif // ARCHIVO_H
