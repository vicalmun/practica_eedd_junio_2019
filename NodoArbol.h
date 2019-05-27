#include "Computadora.h"
class NodoArbol{
    private:
        int valor;   //Valor
        NodoArbol *izq;
        NodoArbol *drch;
        friend class Arbol;
    public:
        NodoArbol(int valor,NodoArbol *izq = NULL, NodoArbol *drch = NULL);
};