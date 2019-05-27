#ifndef Cola_H
#define Cola_H
#include "Solicitud.h"
#include <iostream>
#include <string.h>
using namespace std;

class Cola{
public:
    Cola(Solicitud *primero = NULL, Solicitud *ultimo = NULL);
    ~Cola();
    void insertar(string direccion_ip);
    Solicitud* get_Primera_Solicitud();
    void mostrar();     // es un imprimir
    void eliminar();    // elimina el primero
    bool esta_Vacia();
    int contar_Solicitudes_Restantes();
    void borrarPrimeraSolicitud();
    string primeraSolicitud();  //¿por qué mejor no devolver un nodoCola ~= solicitd?
    
    //void borrarPrimerElemento();    // lo mismo que el de arriba ESTÁ COMENTADO EN .cpp
    //void empujar(Solicitud** primero_ref, string nueva_direccion);  // ESTÁ COMENTADO EN .cpp

private:
    Solicitud* primero;
    Solicitud* ultimo;
    friend class Computadora;
};

#endif // Cola_H
