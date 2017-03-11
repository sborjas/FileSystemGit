#ifndef BASE_H
#define BASE_H
#include <iostream>

using namespace std;

class Base{
private:
    string nombre;
    string ruta;

public:

    Base *siguiente;
    Base *anterior;

    Base(){
        siguiente = NULL;
        anterior = NULL;
    }
    Base(string,string);
    string getNombre();
    string getRuta();

    void setNombre(string);
    void setRuta(string);

    bool operator==(Base * archivo);
};

#endif // BASE_H
