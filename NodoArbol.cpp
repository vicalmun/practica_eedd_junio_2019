#include "NodoArbol.h"

NodoArbol::NodoArbol(int valor , NodoArbol *izq, NodoArbol *drch){
    this->izq = izq;
    this->drch = drch;
    this->valor = valor;
}

