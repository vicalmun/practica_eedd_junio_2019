
#include "Arbol.h"
#include "Computadora.h"
#include "Granja.h"
Arbol::Arbol(){
	raiz = NULL;
	this->raiz = NULL;
	// Que cambia entre estas 2 cosas
}

Arbol::~Arbol(){
	elimina_Arbol();
}

void Arbol::elimina_Arbol(NodoArbol *hoja){
	if(hoja != NULL){
		elimina_Arbol(hoja->izq);
		elimina_Arbol(hoja->drch);
		delete hoja;
	}
}

void Arbol::insert(int key, NodoArbol *hoja){
	// Solo se le pasa un NodoArbol porque solo introduce un valor
	// y y dentro vemos si se lo introducimos a la drch. o a la izq.
	if(key < hoja->valor){
		// Si es menor: añade a la izquierda
		if(hoja->izq != NULL){
			insert(key, hoja->izq);
			// va bajando hasta que encuentra un nodo donde no hay nodo a la izq.
		}else{
			// Si encuentra ese 'hueco'
			hoja->izq = new NodoArbol(key);	//el nodo izq. es un nuevo nodo
			hoja->izq->valor = key;	//Le pongo el valor al nodo
			hoja->izq->izq = NULL;
			hoja->izq->drch = NULL;	//Los hijos apuntan a null
		}
	}else if(key >= hoja->valor){
		// Si es mayor: añade a la derecha
		if(hoja->drch != NULL){
			insert(key, hoja->drch);
			// Va bajnado hasta que encuentra un nodo donde no hay nodo a la drch.
		}else{
			// Si encuntra ese 'hueco'
			hoja->drch = new NodoArbol(key);
			hoja->drch->valor = key;
			hoja->drch->drch = NULL;
			hoja->drch->izq = NULL;
		}
	}

}

void Arbol::insert(int key){
	if(raiz != NULL){
		insert(key, raiz);
	}else{
		raiz = new NodoArbol(key);
		raiz->valor = key;
		raiz->izq = NULL;
		raiz->drch = NULL;
	}
}

NodoArbol *Arbol::buscar(int key, NodoArbol *hoja){
	if(hoja != NULL){
		if(key == hoja->valor){
			return hoja;
		}
		if(key < hoja->valor){
			return buscar(key, hoja->izq);
		}else{
			return buscar(key, hoja->drch);
		}
	}else{
		return NULL;
	}
}

// Este es el publico y el primero porque le pasamos directamente
// el nodo raiz
NodoArbol *Arbol::buscar(int key){
	return buscar(key, raiz);
}

void Arbol::elimina_Arbol(){
	elimina_Arbol(raiz);
}

void Arbol::inorder_print(){
	inorder_print(raiz);
	cout << "\n";
}

void Arbol::inorder_print(NodoArbol *hoja){
	if(hoja != NULL){
		inorder_print(hoja->izq);
		cout << hoja->valor << ",";
		inorder_print(hoja->drch);
	}
}

void Arbol::postorder_print(){
	postorder_print(raiz);
	cout << "\n";
}

void Arbol::postorder_print(NodoArbol *hoja){
	if(hoja != NULL){
		postorder_print(hoja->izq);
		postorder_print(hoja->drch);
		cout << hoja->valor << ",";
	}
}

void Arbol::preorder_print(){
	preorder_print(raiz);
	cout << "\n";
}

void Arbol::preorder_print(NodoArbol *hoja){
	if(hoja != NULL){
		cout << hoja->valor << ",";
		preorder_print(hoja->izq);
		preorder_print(hoja->drch);
	}
}


void Arbol::crear_Arbol_Desde_Granja(Granja *granja){
	Computadora *temp;
	temp = granja->primero;

	while(temp){
		this->insert(temp->get_Codigo());
		temp = temp->siguiente;
	}
}
