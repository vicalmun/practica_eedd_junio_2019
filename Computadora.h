#ifndef Computadora_h
#define Computadora_h
#include "Cola.h"
#include <stdio.h>

using namespace std;

class Computadora{
    public:
        Computadora(int codigo, Cola *solicitudes = NULL, Computadora *siguiente = NULL, Computadora *anterior = NULL);
        ~Computadora();
        int get_Codigo();
        void set_Codigo(int codigo);    //Maybe no hace falta porque cuando se crean necesitan un codigo
        void set_Cola(Cola *Solicitudes);
        Cola* get_Cola();
    private:
        int codigo;
        Cola *solicitudes;
        Computadora* siguiente;
        Computadora *anterior;
        friend class Granja; 
        friend class Arbol;
};
#endif