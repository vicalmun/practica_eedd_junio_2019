#include "Granja.h"
using namespace std;
Granja::Granja(Computadora *primero, Computadora *ultimo){
    this->primero = primero;
    this->ultimo = ultimo;
}
Granja::~Granja(){
}
void Granja::add_Computadora(Computadora *nueva){
Computadora *temp = this->primero;
// While: está comparando las direcciones de memoria a donde a puntan temp y ultimo
if (this->esta_Vacia()){
    this->primero = nueva;
    this->ultimo = nueva;
}else if (this->primero == this->ultimo){
    //Si solo tiene un elemento
    if (primero->codigo < nueva->codigo){
        primero->siguiente = nueva;
        nueva->anterior = primero;
        nueva->siguiente = NULL;
        ultimo = nueva;
    }else{
        primero->anterior = nueva;
        nueva->siguiente = primero;
        //Para prevenir
        nueva->anterior = NULL;
        primero = nueva;
    }
}else{
    do{
        // Si encuentra donde meter
        if (nueva->codigo < temp->codigo){
            if(primero=temp){  
                // 1º asignar a nueva el título de primero
                primero = nueva;
            }
            else{
                // El anterior de temp que el sguiente apunte a nuevo
                temp->anterior->siguiente = nueva;
            }
            temp->anterior = nueva;
            nueva->siguiente = temp;
            break;
        }
        temp = temp->siguiente;
    }while(temp != ultimo);
    // Si estamos aqui, es porque no se ha encontrado ningun candidato entonces nuestra nueva computadora va al final.
    nueva->anterior = ultimo;
    ultimo->siguiente = nueva;
    ultimo= nueva;
    nueva->siguiente = NULL; //Por si acaso.
}

cout << "Se ha añadido Computadora " << nueva->codigo << endl; // " entre Computadora " << nueva->anterior->codigo << " y Computadora " << nueva->siguiente->codigo << endl;

}
void Granja::add_Computadora(int codigo){
    Computadora *computadora = new Computadora(codigo);
    // Con el overload conseguimos poder crear una computadora atraves de CODIGO o pasandole una computadora.
    this->add_Computadora(computadora);
}
void Granja::borrar_Computadora (int codigo){
    cout <<"HAS ENTRADO AL METODO BORRRAR\n";
    if (this->existe_Computadora(codigo)){
        //Existe
        cout <<"Existe el codigo que quieres borrar (" <<codigo <<")"  <<endl;
        Computadora *temp = this->primero;
        if (this->primero == this->ultimo && temp->get_Codigo() == codigo){
                //Y hay uno, es ese
                cout << "SOLO HAY UN ELEMENTO Y ES ESE\n";
                delete this->primero;
                this->primero = NULL;
                this->ultimo = NULL;
                cout <<"Elemento eliminado\n";
        }
        else{
            //Hay varios

            cout <<"Codigo del primero de la lista:" <<this->primero->get_Codigo() <<endl;
            cout <<"Codigo del temporal: " <<temp->get_Codigo() <<endl;        

            cout <<"siguiente del temporal: " <<temp->siguiente->get_Codigo() <<endl;
            cout <<"Siguiente del primero: " <<this->primero->siguiente->get_Codigo() <<endl;
            
            cout <<"Ultimo de la lista: " <<this->ultimo->get_Codigo() <<endl;
            do {
                cout <<"Hay varios elementos en la lista, lo voy a buscar...\n";
                cout <<"Codigo del temporal: " <<temp->get_Codigo() <<endl;

                if(temp->get_Codigo() == codigo){
                    //Encontrado
                    cout <<"HA ENCONTRADO EL ELEMENTO\n";
                    if(temp->get_Codigo() == this->primero->get_Codigo()){
                        //Si es el primero
                        temp->siguiente->anterior = NULL;
                        delete temp;
                        cout <<"Encontrado en primera posicion, computadora eliminada\n";
                        break;
                    }else{
                        //Si es algun otro
                        temp->siguiente->anterior = temp->anterior;
                        temp->anterior->siguiente = temp->siguiente;
                        // NO es necesario apuntar a null porque se va a borrar, pero por si acaso
                        temp->anterior = NULL;
                        temp->siguiente = NULL;
                        delete temp;
                        cout <<"Computadora eliminada\n";
                        break;
                    }
                }
                temp = temp->siguiente;
            }while(temp != ultimo->siguiente);
        }
        cout <<"Ostia, y aqui llega?\n";
    }else{
        cout << "Esa computadora no existe\n";
    }
}

bool Granja::existe_Computadora(int codigo){
    cout <<"HAS ENTRADO AL METODO EXISTE\n";
    
    
    cout <<"Codigo introducido: " <<codigo <<endl;
    //cout << temp->codigo <<" y primero: " <<primero->codigo;
    bool encontrado = false;
    if (this->esta_Vacia()){
        cout << "La lista esta vacia, asi que no existe\n"  <<endl;
    }else{
        cout <<"la lista no esta vacia \n";
        // Si la lista no está vacía creamos un temporal para buscarlo
        Computadora *temp = this->primero;
        cout <<"codigo del temporal: " <<temp->get_Codigo() <<endl;

        if(this->primero == this->ultimo && temp->get_Codigo() == codigo){
        //Tiene un solo elmento y es ese
        cout <<"Tiene un solo elemento y entra aqui? \n";
            encontrado = true;
            cout <<"Elemento encontrado\n";
        }
        else{
            // Tiene varios elementos, recorre la lista
        do {
            if (temp->get_Codigo() == codigo){
                //Existe
                encontrado = true;
                cout <<"Elemento encontrado\n";
                break;
            }
            else{
            cout <<"El elemento de codigo " <<codigo <<" no existe en esta posicion\n";
        }
            temp = temp->siguiente;
        }while (temp != ultimo->siguiente);
        }
    }
    cout << "Finalizada la lista\n" <<endl;
    return encontrado;
}

bool Granja::esta_Vacia(){
    // Operador ternario http://www.cplusplus.com/forum/articles/14631/
    return (this->primero) ? false : true;
}

int Granja::get_Computadoras_Operativas(){
    //Recorrer toda la lista buscando las que están operativas
    int computadoras_Operativas = 0;
    if(this->esta_Vacia()){
        cout << "No hay computadoras operativas";
    }else {
        Computadora *temp = this->primero;
        do {
            if(temp->solicitudes != NULL){
                // ¿Comprueba que la cola de solicitudes esté a NULL?
                computadoras_Operativas++;
            }
            temp = temp->siguiente;
        }while (temp != ultimo->siguiente);
    }
    return computadoras_Operativas;
}

int Granja::get_Computadoras_En_Granja(){
    int numero_Computadoras = 0;
    if(this->esta_Vacia()){
        cout << "No hay computadoras ";
    }else {
        Computadora *temp = this->primero;
        while (temp != ultimo->siguiente) {
            numero_Computadoras++;
            temp = temp->siguiente;   
        }
    }
    return numero_Computadoras;
}

//REVISAR PARA QUE NO ELIMINE EL NUMERO
Computadora* Granja::ver_Primero(){
    Computadora *temp = NULL;
    if (!this->esta_Vacia()){
        temp = this->primero;
        //this->primero = primero->siguiente;
    } 
    return temp;
}
/*
void Granja::imprimir_Lista(Granja *granja){
    Computadora *temp = NULL;
    //Granja granja_imprimir = this;
    if (!granja->esta_Vacia()){
        temp = granja->primero;
        granja->primero = primero->siguiente;
    }
    cout << temp->get_Codigo() <<" - ";
}
*/