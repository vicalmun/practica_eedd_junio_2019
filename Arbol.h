#include <iostream>
#include "NodoArbol.h"
#include "Computadora.h"
#include "Granja.h"

using namespace std;

class Arbol{
public:
	Arbol();
	~Arbol();

	void insert(int key);
	NodoArbol *buscar(int key);
	void elimina_Arbol();
	void inorder_print();
	void postorder_print();
	void preorder_print();
	void crear_Arbol_Desde_Granja(Granja *granja);
private:
	void elimina_Arbol(NodoArbol *hoja);
	void insert(int key, NodoArbol *hoja);
	NodoArbol *buscar(int key, NodoArbol *hoja);
	void inorder_print(NodoArbol *hoja);
	void postorder_print(NodoArbol *hoja);
	void preorder_print(NodoArbol *hoja);

	NodoArbol *raiz;
	NodoArbol *actual;	//Esto sale en los apuntes, no se si es necesario.
};