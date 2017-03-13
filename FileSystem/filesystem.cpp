#include "filesystem.h"

filesystem::filesystem(){
    temp = NULL;
    raiz = new Folder("raiz","raiz");


}

void filesystem::agregarElemento(Folder * destino,string nombre,int tipo){
    string ruta = destino->getRuta()+"/"+nombre;

    if(tipo==1){
        Folder *folder = new Folder(nombre,ruta);
        destino->agregarElemento(folder);

    }else if(tipo==2){
        Archivo *texto = new Archivo(nombre,ruta);
        destino->agregarElemento(texto);
    }
}

Base *filesystem::cargarElementos(string ruta){
    return cargarElementos(ruta,raiz);
}

Base * filesystem::cargarElementos(string ruta, Folder * subRaiz){
    for(int i = 0; i<subRaiz->getCantidadElemento(); i++){
        temp = subRaiz->obtenerElemento(i);

        if(temp->getRuta() == ruta)
            return temp;

        else if(typeid(temp) == typeid(Folder))
            return cargarElementos(ruta, (Folder*)temp);
    }

    if(subRaiz == raiz)
        return NULL;
}

/*

void filesystem::eliminarElemento(string ruta){
    eliminarElemento(ruta, raiz);
}

void filesystem::eliminarElemento(string ruta, Folder * subRaiz){
    for(int i = 0; i<subRaiz->getCantidadElemento(); i++){
        temp = subRaiz->obtenerElemento(i);

        if(temp->getRuta() == ruta){
            subRaiz->eliminarElemento(temp);
            return;
        }

        else if(typeid(temp) == typeid(Folder)){
            eliminarElemento(ruta, (Folder*)temp);
            return ;
        }
    }
}
*/


    void filesystem::copiarElemento (Folder * origen, string nombre, Folder * destino){
        for(int i = 0; i<origen->getCantidadElemento(); i++){
            temp = origen->obtenerElemento(i);

            if(temp->getNombre() == nombre)
                break;
        }

        if(temp != NULL){
            string ruta = destino->getRuta()+"/"+nombre;

            if(typeid(temp) == typeid(Folder)){
                Folder * folder = new Folder(nombre, ruta);
                Folder * conv = (Folder*)temp;

                for(int i = 0; i<conv->getCantidadElemento(); i++)
                    folder->agregarElemento(conv->obtenerElemento(i));

                destino->agregarElemento(folder);
            }
            else{
                Archivo * text = new Archivo(nombre, ruta);
                text->setContenido(((Archivo*)temp)->getContenido());
                destino->agregarElemento(text);
            }
        }
    }

    /*
    Base filesystem::listarElementos(Base *raiz){
        int elemento = 0;
        while(raiz->siguiente !=NULL){
            elemento++;
            return raiz->obtenerElemento(elemento);
        }
    }
    */






