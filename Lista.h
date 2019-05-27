#include <iostream>
#include "Nodo.h"
using namespace std;
class Lista{
    private:
        int valorLista;
        Nodo *primero,*ultimo;
    public:
        Lista(int valorLista, Nodo* primero = NULL);
        void meterEnLista(Nodo* nodo,int posicion);
        void insertar(Nodo* nodo);
        int pop();
        int obtener(int posicion);
};