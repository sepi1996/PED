/*
 * tabbporo.cpp
 *
 *  Created on: 29 de mar. de 2016
 *      Author: pepe
 */

#include "../include/tabbporo.h"

TNodoABB::TNodoABB(): item(), iz(), de(){
	//NADA??
}

TNodoABB::TNodoABB(const TNodoABB &origen): item(origen.item), iz(origen.iz), de(origen.de){//OK

}

TNodoABB::~TNodoABB(){//OK
	//No hacemos nada, el TNodo invoca automaticamente al destructor de poro y a los dos de arbol
}

TNodoABB& TNodoABB::operator =(const TNodoABB &origen){
	if(this != &origen){
		item = origen.item;
		de=origen.de;
		iz=origen.iz;
	}
	return *this;
}







//TABBPoro//

TABBPoro::TABBPoro(){//OK
	nodo=NULL;
}

TABBPoro::TABBPoro(const TABBPoro &origen){//OK
	Copiar(origen);
}

void TABBPoro::Copiar(const TABBPoro &origen){//OK
	if(origen.nodo != NULL){
		TNodoABB *aux = new TNodoABB();
		aux->item = origen.nodo->item;
		nodo=aux;
		nodo->de.Copiar(origen.nodo->de);
		nodo->iz.Copiar(origen.nodo->iz);
	}
	else{
		nodo=NULL;
	}
}


TABBPoro::~TABBPoro() {//OK entender??
	if(nodo != NULL){
		delete nodo;
		nodo=NULL;
	}
}

TABBPoro& TABBPoro::operator =(const TABBPoro &origen){//OK
	if(nodo != NULL){
		this->~TABBPoro();
	}
	this->Copiar(origen);
	return (*this);
}

TPoro TABBPoro::Raiz()const{//OK
	if(nodo == NULL){
		return TPoro();
	}
	else{
		return nodo->item;
	}
}

bool TABBPoro::EsVacio()const{//OK
	return (nodo == NULL);
}


int TABBPoro::Altura()const{
	int altura1, altura2;
	if(nodo != NULL){
		altura1 = nodo->de.Altura();
		altura2 = nodo->iz.Altura();
		return (1 + (altura1 < altura2 ? altura2:altura1));
	}
	else return 0;

}


bool TABBPoro::Insertar(const TPoro &poro){//OK
	bool insertado=false;
	if(nodo == NULL){
		nodo=new TNodoABB();
		nodo->item=poro;
		insertado=true;
		return insertado;

	}
	else{
		if(this->Buscar(poro)){//Si ese nodo ya lo tenemos, false y finalizamos.
			return insertado;
		}
		else{
			if(nodo->item.Volumen() > poro.Volumen()){
				if(nodo->iz.nodo == NULL){
					nodo->iz.nodo = new TNodoABB();
					nodo->iz.nodo->item = poro;
					insertado=true;
					return insertado;
				}
				else{
					return nodo->iz.Insertar(poro);
				}

			}
			else if(nodo->item.Volumen() < poro.Volumen()){
				if(nodo->de.EsVacio()){
					nodo->de.nodo = new TNodoABB();
					nodo->de.nodo->item = poro;
					insertado=true;
					return insertado;
				}
				else{
					return nodo->de.Insertar(poro);
				}
			}
			else if(this->nodo->item.Volumen() == poro.Volumen()){
				return insertado;
			}
		}
		return insertado;

	}
}


bool TABBPoro::Buscar(const TPoro &poro)const{//OK
	bool encontrado=false;

	if(nodo != NULL && encontrado == false){
		if(nodo->item == poro){
			 encontrado=true;
			 return encontrado;
		}
		else{
			if(nodo->item.Volumen() > poro.Volumen()){
				return nodo->iz.Buscar(poro);
			}
			else{
				return nodo->de.Buscar(poro);

			}
		}
	}

	return encontrado;

}

int TABBPoro::Nodos()const{
	if(nodo == NULL){
		return 0;
	}
	return(1 + nodo->de.Nodos() + nodo->iz.Nodos());

}

int TABBPoro::NodosHoja()const{

	if(nodo != NULL){
		if(nodo->de.nodo == NULL && nodo->iz.nodo == NULL){
			return 1;
		}
		else if(nodo->de.nodo == NULL){
			return (nodo->iz.NodosHoja());
		}

		else if(nodo->iz.nodo == NULL){
			return (nodo->de.NodosHoja());
		}
		else{
			return(nodo->de.NodosHoja() + nodo->iz.NodosHoja());
		}

	}
	else{
		return 0;
	}

}

TVectorPoro TABBPoro::Inorden()const{
	int posicion = 1;

	TVectorPoro v(Nodos());
	InordenAux(v, posicion);
	return v;
}

void TABBPoro::InordenAux(TVectorPoro &vec, int &tam)const{
	if(this->nodo != NULL){
		this->nodo->iz.InordenAux(vec, tam);
		vec[tam]=nodo->item;
		tam++;
		this->nodo->de.InordenAux(vec, tam);
	}
}

TVectorPoro TABBPoro::Preorden()const{
	int posicion = 1;

	TVectorPoro v(Nodos());
	PreordenAux(v, posicion);
	return v;
}

void TABBPoro::PreordenAux(TVectorPoro &vec, int &tam)const{
	if(this->nodo != NULL){
		vec[tam]=nodo->item;
		tam++;
		this->nodo->iz.PreordenAux(vec, tam);
		this->nodo->de.PreordenAux(vec, tam);
	}
}

TVectorPoro TABBPoro::Postorden()const{
	int posicion = 1;

	TVectorPoro v(Nodos());
	PostordenAux(v, posicion);
	return v;
}

void TABBPoro::PostordenAux(TVectorPoro &vec, int &tam)const{
	if(this->nodo != NULL){
		this->nodo->iz.PostordenAux(vec, tam);
		this->nodo->de.PostordenAux(vec, tam);
		vec[tam]=nodo->item;
		tam++;
	}
}


bool TABBPoro::operator ==(const TABBPoro &arb)const{
	bool correcto=true;
	TVectorPoro otro = arb.Inorden();
	TPoro a;

	for(int i=1; i<=otro.Longitud() && correcto == true; i++){
		a=otro[i];
		correcto = this->Buscar(a);
	}

	return correcto;



}


TABBPoro TABBPoro::operator +(const TABBPoro &arb)const{

	TABBPoro ArbolNuevo(*this);
	TVectorPoro recorredor = arb.Inorden();

	for(int i=0; i<recorredor.Longitud(); i++){
		ArbolNuevo.Insertar(recorredor[i]);
	}

	return ArbolNuevo;
}

TABBPoro TABBPoro::operator -(const TABBPoro &arb)const{

	TABBPoro ArbolNuevo(*this);
	TVectorPoro recorredor = arb.Inorden();

	for(int i=0; i<recorredor.Longitud(); i++){
		ArbolNuevo.Borrar(recorredor[i]);
	}

	return ArbolNuevo;
}

bool TABBPoro::Borrar1(const TPoro &p, TNodoABB *padre){
	if(nodo != NULL){
			if(this->nodo->item.Volumen() == p.Volumen()){//Si lo tenemos lo borramos
					return BorrarAux(p, padre);
				}
				else if(this->nodo->item.Volumen() > p.Volumen()){
					padre=nodo;
					return nodo->iz.Borrar1(p, padre);
				}
				else if(this->nodo->item.Volumen() < p.Volumen()){
					padre=nodo;
					return nodo->de.Borrar1(p, padre);
				}
				else{//imposible entrar aqui
					return false;
			}
		}
		return false;
	
}

bool TABBPoro::Borrar(const TPoro &p){
	TNodoABB *padre = NULL;
	return Borrar1(p, padre);
	
}

TNodoABB* TABBPoro::Minimo(){
	if(nodo->de.nodo != NULL){
		return this->nodo->de.Minimo();
	}
	else{
		return this->nodo;
	}
}

bool TABBPoro::BorrarAux(const TPoro &p, TNodoABB *padre){
	TNodoABB *aux = NULL;
	TNodoABB *minimo = NULL;
	if(this->nodo->de.nodo != NULL && this->nodo->iz.nodo != NULL){//tiene los dos hijos
		minimo = nodo->iz.Minimo();
		aux = nodo;//El que vamos a borrar lo guardamos en aux
		swap(nodo->item, minimo->item);
		if(nodo->iz.nodo->de.nodo == minimo){//Vamos a ver si el hijo iz se queda sin hijos de, para que apunte a NULL
			nodo->iz.nodo->de.nodo = NULL;
		}
		else{
			nodo->iz.nodo=minimo->iz.nodo;
		}

		minimo->de.nodo=NULL;
		minimo->iz.nodo=NULL;
		delete minimo;
		minimo = NULL;
		return true;

	}
	else if(this->nodo->de.nodo != NULL){//Solo tiene hijos derechos
		if(padre == NULL){//Es la raiz
			aux=nodo;
			this->nodo=this->nodo->de.nodo;
		}
		else if(padre->iz.nodo == nodo){
			aux = nodo;
			padre->iz.nodo = nodo->de.nodo;
		}
		else{
			aux=nodo;
			padre->de.nodo = nodo->de.nodo;
		}
		aux->de.nodo=NULL;//Para que el nodo que vamos a borrar no apunte a otros arboles, asi se borre solo él
		aux->iz.nodo=NULL;
		delete aux;
		aux=NULL;
		return true;	
	}
	else if(this->nodo->iz.nodo != NULL){//Solo hijo izquierdo
		if(padre==NULL){
			aux=nodo;
			this->nodo=this->nodo->iz.nodo;
		}
		else if(padre->iz.nodo == nodo){
			aux = nodo;
			padre->iz.nodo = nodo->iz.nodo;
		}
		else{
			aux=nodo;
			padre->de.nodo = nodo->iz.nodo;
		}
		aux->de.nodo=NULL;
		aux->iz.nodo=NULL;
		delete aux;
		aux=NULL;
		return true;
	}
	else{//No tiene hijos
		if(padre == NULL){
			//NADA
		}
		else if(nodo==padre->iz.nodo){
			padre->iz.nodo=NULL;
		}
		else{
			padre->de.nodo=NULL;
		}
		delete nodo;
		nodo=NULL;
		return true;
	}
}








TVectorPoro TABBPoro::Niveles()const{
	TVectorPoro v(Nodos());
	if(this->EsVacio() == false){
		queue <TNodoABB*> miCola;
		TNodoABB *actual;
		int posicion = 1;
		miCola.push(nodo);

		while(miCola.front() != NULL){
			actual=miCola.front();
			v[posicion]=actual->item;
			posicion++;
			//cout<<v<<endl;
			miCola.pop();
			if(actual->iz.EsVacio() == false){
				miCola.push(actual->iz.nodo);
			}
			if(actual->de.EsVacio() == false){
				miCola.push(actual->de.nodo);
			}
		}
	}
	return v;

}

ostream& operator<<(ostream &os, const TABBPoro &arbol){
	os<<arbol.Niveles();
	return os;
}


