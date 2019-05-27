#include "Cola.h"
#include <iostream>
#include <stdio.h>
#include <typeinfo>
#include "stdlib.h"
#include <limits.h>
#include "Solicitud.h"

using namespace std;

Cola::Cola(Solicitud *primero, Solicitud *ultimo){
    this->primero = primero;
    this->ultimo = ultimo;
}
Cola::~Cola()
{
    while(primero!=NULL){
        eliminar();
    }
}

//Insertar siempre crea una nueva solicitud
void Cola::insertar(string direccion_ip){
    Solicitud* aux = new Solicitud(direccion_ip);
/* ESTO NO FUNCIONA
    if (!this->primero){
        // Si no existe primero, ergo esta vacia
        this->primero = aux;
        this->ultimo = aux;
        //El aux es el unico elemento, ergo es primero y utimo
    }else{
        // Si hay elementos, se añade al final.
        this->ultimo->siguiente = aux;
    }
*/
// ESTO NO SE COMO FUNCIONA, PERO LO HACE
    if(ultimo){
        ultimo->siguiente = aux;
    }
    ultimo = aux;
    if(!primero){
        primero = aux;
    }

}

void Cola::borrarPrimeraSolicitud(){
    Solicitud* temp = primero;
    if (primero == NULL)
        cout<<"La Cola esta vacia..."<<endl;
    else
        primero = primero->siguiente;
        delete temp;
}

string Cola::primeraSolicitud(){
    cout<<"Primera solicitud realizada: "<< primero->direccion_ip;
    return primero->direccion_ip;
}

Solicitud* Cola::get_Primera_Solicitud(){
    return this->primero;
}

void Cola::mostrar(){
    if (this->esta_Vacia()){
        cout <<"La cola de solicutudes esta vacia";
    }else{
        Solicitud* aux =primero;
        while(aux !=NULL )
        {
            cout<<aux->direccion_ip <<"->";
            aux = aux->siguiente;
        }
    }
     cout <<endl;
}

void Cola::eliminar(){
    Solicitud* aux = primero;
    primero=primero->siguiente;
    delete aux;
}

bool Cola::esta_Vacia(){
    return (this->primero == NULL) ? false : true;
    
}

int Cola::contar_Solicitudes_Restantes(){
    int sol_restantes = 0;
     Solicitud* aux =primero;
     while(aux !=NULL )
     {
        sol_restantes++;
        aux = aux->siguiente;
     }
     return sol_restantes;
}

//Solicitud* Cola::borrarPrimerElemento(){
//     Solicitud* aux = primero;
//     if (primero == NULL){
//         return NULL
//     }
//     Solicitud* temp= primero;
//     primero = primero->siguiente;
//     delete temp;
//     return primero;
//}
//
//void Cola::empujar(){
//    
//}


//void Cola::empujar(Solicitud** primero_ref, string nueva_direccion) 
//{ 
//    Solicitud* nuevo_nodo = new Solicitud; 
//    nuevo_nodo->direccion_ip = nueva_direccion; 
//    nuevo_nodo->siguiente = (*primero_ref); 
//    (*primero_ref) = nuevo_nodo; 
//} 