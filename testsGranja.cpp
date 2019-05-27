#include "Cola.h"
#include "Solicitud.h"
#include "Granja.h"
#include "Arbol.h"
#include "Computadora.h" //Necesario? porque está en Granja.h

using namespace std;


int main(){ 
    Cola *colaPrueba = new Cola();
    cout <<colaPrueba->esta_Vacia() <<endl;
    colaPrueba->mostrar();
    colaPrueba->insertar("aaaaaa");
    colaPrueba->insertar("bbbbbb");
    colaPrueba->insertar("cccccc");
    colaPrueba->insertar("dddddd");
    cout <<colaPrueba->esta_Vacia() <<endl;
    colaPrueba->mostrar();
    cout <<colaPrueba->contar_Solicitudes_Restantes() <<endl;
    colaPrueba->eliminar(); //Elimina el primero
    colaPrueba->mostrar();
    cout <<colaPrueba->esta_Vacia() <<endl;
    cout <<colaPrueba->contar_Solicitudes_Restantes() <<endl;
    colaPrueba->primeraSolicitud();
    cout <<endl;
    cout <<colaPrueba->get_Primera_Solicitud()->get_Ip_Solicitud() <<endl;
    cout <<colaPrueba->contar_Solicitudes_Restantes() <<endl;

    cout <<"- - - - - - - - - - - - - - - - \n";

    Granja *pGranja = new Granja();
    Computadora *comput_Prueba = new Computadora(0, colaPrueba);
    cout <<pGranja->esta_Vacia() <<endl;
    cout <<"Computadoras en la granja: " <<pGranja->get_Computadoras_En_Granja() <<endl;

    pGranja->existe_Computadora(23);

    cout <<endl <<"HITO 1" <<endl;
    
    pGranja->add_Computadora(comput_Prueba);
    pGranja->add_Computadora(5);
    pGranja->add_Computadora(1);
    pGranja->add_Computadora(6);
    cout <<"Computadoras en la granja: " <<pGranja->get_Computadoras_En_Granja() <<endl;
    cout << pGranja->esta_Vacia() <<endl;

    cout <<endl <<"HITO 2" <<endl;

    pGranja->existe_Computadora(23);

    cout <<endl <<"HITO 3" <<endl;

    pGranja->existe_Computadora(0);
    pGranja->existe_Computadora(5);

    cout <<endl <<"HITO 4" <<endl;

    //pGranja->borrar_Computadora(0);

    cout <<"\nLlega aqui, esta en el main                     o\n";

    cout <<"Computadoras en la granja: " <<pGranja->get_Computadoras_En_Granja() <<endl;
    cout <<"Computadoras operativas en la granja: " <<pGranja->get_Computadoras_Operativas() <<endl;

    Arbol *arbol_Desde_Granja = new Arbol();
    arbol_Desde_Granja->crear_Arbol_Desde_Granja(pGranja);      //ESTE METODO SALE ALGO MAL
    arbol_Desde_Granja->inorder_print(); 

//                                      Cuando solo hay una computadora peta
    pGranja->existe_Computadora(7);
    pGranja->existe_Computadora(1);
    pGranja->existe_Computadora(0);

    cout <<"Imprimir" <<endl;

    // TODO imprimir lista
    cout <<"Primer elemento de la granja: " <<pGranja->ver_Primero()->get_Codigo() <<endl;    

    pGranja->borrar_Computadora(107);
    cout <<"Existe computadora 1 antes de eliminar: \n";
    //                                   Peta al borrar computadoras
    pGranja->borrar_Computadora(1);
    cout <<"Existe computadora 1??: ";
    pGranja->existe_Computadora(1);
    //cout << pGranja->ver_Primero().get_Codigo();
    
    cout <<"Computadoras en la granja: " <<pGranja->get_Computadoras_En_Granja() <<endl;
    cout <<"Computadoras operativas en la granja: " <<pGranja->get_Computadoras_Operativas() <<endl;

    pGranja->borrar_Computadora(0);
    cout <<"Computadoras en la granja: " <<pGranja->get_Computadoras_En_Granja() <<endl;
    cout <<"Computadoras operativas en la granja: " <<pGranja->get_Computadoras_Operativas() <<endl;

    Arbol *arbol = new Arbol();
    arbol->insert(5);
    arbol->insert(9);
    arbol->insert(3);
    arbol->inorder_print();
    arbol->postorder_print();
    arbol->preorder_print();

    cout <<"Jugar con la cola desde la granja \n";

    cout << "Solicitudes restantes de la primera computadora: " <<pGranja->ver_Primero()->get_Cola()->contar_Solicitudes_Restantes() <<endl;
    pGranja->ver_Primero()->get_Cola()->insertar("eeeee");
    cout << "Solicitudes restantes de la primera computadora: " <<pGranja->ver_Primero()->get_Cola()->contar_Solicitudes_Restantes() <<endl;
    cout << "Esta vacia?: " <<pGranja->ver_Primero()->get_Cola()->esta_Vacia() <<endl;
    pGranja->ver_Primero()->get_Cola()->mostrar();
  
}
