#include "Computadora.h"


Computadora::Computadora(int codigo, Cola *solicitudes, Computadora *siguiente, Computadora *anterior){
    this->codigo = codigo;
    this->solicitudes = solicitudes;
    this->siguiente = siguiente;
    this->anterior = anterior;
}

Computadora::~Computadora(){

}

int Computadora::get_Codigo(){
    return this->codigo;
}

void Computadora::set_Codigo(int codigo){
    this->codigo = codigo;
}

void Computadora::set_Cola(Cola *Solicitudes){
    this->solicitudes = solicitudes;
}

Cola *Computadora::get_Cola(){
    return this->solicitudes;
}
