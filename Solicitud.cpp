#include "Solicitud.h"

Solicitud::Solicitud(string direccion_ip, Solicitud* siguiente)
{
    this->direccion_ip = direccion_ip;
    this->siguiente = siguiente;
}

Solicitud::~Solicitud()
{
}

string Solicitud::get_Ip_Solicitud(){
    return this->direccion_ip;
}
