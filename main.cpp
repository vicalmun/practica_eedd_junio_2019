#include <stdio.h>
#include <string.h>
#include "Cola.h"
#include "Solicitud.h"
#include <windows.h>
using namespace std;


int main()
{
cout << "********************************************* GRANJA DE SERVIDORES*****************************************************" << endl;
cout << "                                     <> VICTOR ALBA & MIGUEL VCENTE ARARA <>\n\n\n" << endl;

//Variables

string aux;
char decision;
int opcion;
Cola c;
//Programa principal

    cout<<"MENU DE OPERACIONES: \n\n"<<endl;
    cout<<"1. Insertar una solicitud a la Cola. "<<endl;
    cout<<"2. Borrar la primera solicitud. "<<endl;
    cout<<"3. Consultar la primera solicitud de la Cola."<<endl;
    cout<<"4. Solicitudes pendientes. "<<endl;
    cout<<"5. Salir. \n"<<endl;
    cout<<">>>Que operacion quieres realizar?  " , cin>>opcion;
    
    do{
        if(opcion == 1){
            cout<< ">>>Solicitud a insertar en la Cola: ", cin>>aux;
            cout<< "  Insertando solicitud a la Cola ..."<<endl;
            c.insertar(aux);
            cout<<"Cola de solicitudes pendientes: "<<endl;
            c.mostrar();
            cout<<"\n >>>Deseas insertar otra solicitud,S o N?   ", cin>>decision;
            if (decision == 'N' or decision == 'n')
                cout<<">>>Que otra OPERACION deseas realizar?  " , cin>>opcion;
            do{
                cout<< "Siguiente solicitud a insertar en la Cola: ",cin>>aux;
                c.insertar(aux);
                cout<<"Cola de solicitudes pendientes: "<<endl;
                c.mostrar();
                cout<<"\n >Deseas INSERTAR otra solicitud,S o N?   ", cin>>decision;
            }while (decision !='N' or decision !='n');
        }
        cout<<"\n >>>Que otra operacion deseas realizar?  " , cin>>opcion;
         if(opcion == 2){
             c.borrarPrimeraSolicitud();
             cout<<"\n Has borrado la primera solicitud!\n"<<endl;
             c.mostrar();
         }
        if(opcion == 3){
            c.primeraSolicitud();
        }
        if(opcion == 4){
            c.mostrar();
        }
    }while (opcion != 5);
}
