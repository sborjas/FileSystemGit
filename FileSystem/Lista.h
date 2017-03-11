#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include "base.h"

using namespace std;

class Lista{
private:
    Base *inicio;
    Base *fin;


public:

    int tamano_lista;

    Lista(){
        tamano_lista = 0;
        inicio = NULL;
        fin = NULL;
    }

    void agregar(Base *el){

        if(inicio==NULL){
            inicio = el;
            el->siguiente =NULL;
            fin = el;
            tamano_lista++;
        }
        Base *temp = inicio;
        while(temp->siguiente !=NULL){
            temp = temp->siguiente;
            cout<<temp->getNombre()<<endl;
        }

        temp->siguiente = el;
        el->anterior = temp;
        fin = el;
        tamano_lista++;


    }

    int buscar(Base *el){
        Base *temp = inicio;
        for(int x=0;x<tamano_lista;x++){
            if(temp ==el){
                return x;
            }

           temp = temp->siguiente;
        }
        return -1;
    }

    Base *obtener(int pos){
        Base *temp = inicio;
        if(pos>=0 && pos<tamano_lista){
           for(int x=0;x<pos;x++){
                temp = temp->siguiente;
            }
            return temp;
        }
        return NULL;
    }


    void eliminar(Base *el){
        if(tamano_lista!=0){
            if(inicio == el){
                inicio = inicio->siguiente;
                tamano_lista--;
            }else if(fin==el){
                fin = fin->anterior;
                tamano_lista--;
            }
            Base *temp = inicio;

            while(temp!=el){
                temp = temp->siguiente;
            }
            temp->anterior->siguiente=temp->siguiente;
            temp->siguiente->anterior = temp->anterior;
            delete temp;
        }

    }



};

#endif // LISTA_H
