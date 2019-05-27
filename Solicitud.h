#ifndef Solicitud_H
#define Solicitud_H
#include <iostream>
#include <string.h>
using namespace std;

class Solicitud
{
public:
    friend class Cola;
    friend class Computadora;
    Solicitud(string direccion_ip, Solicitud* siguiente = NULL);
    ~Solicitud();
    string get_Ip_Solicitud();
    
private:
    string direccion_ip;
    Solicitud* siguiente;
};

#endif // Solicitud_H
