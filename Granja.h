#ifndef Granja_H
#define Granja_H
#include "Computadora.h"
using namespace std;
class Granja{
    private:
        Computadora *primero;
        Computadora *ultimo;
        friend class Arbol;
    public:
        Granja(Computadora *primero = NULL, Computadora *ultimo = NULL);
        ~Granja();
        void add_Computadora(Computadora *nueva);
        void add_Computadora(int codigo);

        void borrar_Computadora (int codigo);
        bool existe_Computadora(int codigo);

        bool esta_Vacia();
        int get_Computadoras_Operativas(); 
        int get_Computadoras_En_Granja();

        Computadora* ver_Primero();

};
#endif 