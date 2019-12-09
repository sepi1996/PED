/*
 * tlistaporo.cpp
 *
 *  Created on: 15/03/2016
 *      Author: pepe
 */

#include "../include/tlistaporo.h"

//TLISTANODO

TListaNodo::TListaNodo() : e(){
	anterior=siguiente=NULL;
}
TListaNodo::TListaNodo(const TListaNodo &origen) : e(origen.e){
	//anterior=origen.anterior;
	//siguiente=origen.siguiente;
	anterior=siguiente=NULL;
}

TListaNodo::~TListaNodo(){//No hace falta llamar a los otros, se hace por defecto
	siguiente=anterior=NULL;
}

TListaNodo& TListaNodo::operator=(const TListaNodo &origen){
	if(this!=&origen){
		(*this).~TListaNodo();
		this->e=origen.e;
		//this->anterior=origen.anterior;
		//this->siguiente=origen.siguiente;
	}

	return *this;
}





//TLISTAPOSICION

TListaPosicion::TListaPosicion() {
	pos=NULL;
}
TListaPosicion::TListaPosicion(const TListaPosicion &listaPos){
	this->pos=listaPos.pos;
}

TListaPosicion::~TListaPosicion() {
	pos=NULL;
}

TListaPosicion& TListaPosicion::operator =(const TListaPosicion &listaPos){
	if(this!=&listaPos){
		(*this).~TListaPosicion();
		this->pos=listaPos.pos;
	}

	return *this;
}

bool TListaPosicion::operator ==(const TListaPosicion &listaPos)const{
	if(this->pos==listaPos.pos){
		return true;
	}
	else{
		return false;
	}
}

bool TListaPosicion::EsVacia()const{
	if(this->pos==NULL){
		return true;
	}

	else{
		return false;
	}
}

TListaPosicion TListaPosicion::Anterior()const{
	TListaPosicion posicion;
	if(this->pos->anterior==NULL){//Accedo al atributo "anterior" de un TListaNodo
		return posicion;
	}
	else{
		posicion.pos=this->pos->anterior;//Asignamos a posicion.pos, la direccion de memoria a la que apunta el atributo anterior de TNodo
		return posicion;
	}

}

TListaPosicion TListaPosicion::Siguiente()const{
	TListaPosicion posicion;
		if(this->pos->siguiente==NULL){
			return posicion;
		}
		else{
			posicion.pos=this->pos->siguiente;
			return posicion;
		}

}





//TListaPoro


TListaPoro::TListaPoro() {//OK
	primero=ultimo=NULL;
}

/*TListaPoro::TListaPoro(const TListaPoro &lista){//Acabar  MIRAR
	TListaPosicion recorredor_mi_lista;
	TListaPosicion recorredor_lista;
	TListaPosicion aux2;
	if(lista.EsVacia()){
		this->primero=NULL;
		this->ultimo=NULL;
	}
	else{
		recorredor_lista=lista.Primera();
		this->primero = new TListaNodo(*recorredor_lista.pos);//Creamos un nodo, con el contenido del primer elemento
		recorredor_mi_lista = this->Primera();
		recorredor_lista = recorredor_lista.Siguiente();

		while(!recorredor_lista.EsVacia()){
			aux2=recorredor_mi_lista;
			recorredor_mi_lista=recorredor_mi_lista.Siguiente();
			recorredor_mi_lista.pos = new TListaNodo(*recorredor_lista.pos);
			recorredor_mi_lista.pos->anterior=aux2.pos;
			recorredor_mi_lista.pos->siguiente=recorredor_mi_lista.pos;
			recorredor_lista = recorredor_lista.Siguiente();
		}
	}
}
*/

TListaPoro::~TListaPoro() {//OK
	//while(!this->Primera().EsVacia()){
		//this->Borrar(Primera());
	//}
	TListaPosicion p;
	TListaPosicion q;
	q=this->Primera();
	while(!q.EsVacia()){
		p=q;
		q=q.Siguiente();
		delete p.pos;
	}

	this->primero=NULL;
	this->ultimo=NULL;


}

TListaPosicion TListaPoro::Primera()const{//OK
	TListaPosicion p;

	if(this->EsVacia() == false){//Si la lista no esta vacia
		p.pos = this->primero;//LA direccion de memoria a la que apunta pos sera la que tiene el puntero primero.

	}
	return p;

}

TListaPosicion TListaPoro::Ultima()const{//OK
	TListaPosicion p;

	if(this->EsVacia() == false){
		p.pos = this->ultimo;
	}
	return p;

}

bool TListaPoro::EsVacia()const{//OK
	if(this->primero==NULL && this->ultimo==NULL){
		return true;
	}

	else{
		return false;
	}

}

bool TListaPoro::Buscar(const TPoro &poro)const{//OK
	bool encontrada=false;
	TListaPosicion recorredor;
	if(this->EsVacia()){
		return encontrada;
	}
	else{
		recorredor=this->Primera();
		while(encontrada==false && recorredor.EsVacia()==false){
			if((*recorredor.pos).e == poro){
				encontrada=true;
			}
			recorredor=recorredor.Siguiente();

		}

		return encontrada;
	}
}

bool TListaPoro::operator ==(const TListaPoro &lista)const{//Casi ok
	TListaPosicion posicion_mia;
	TListaPosicion posicion_lista;

	bool son_iguales=true;

	posicion_mia=this->Primera();
	posicion_lista=lista.Primera();

	while(posicion_mia.EsVacia()==false && posicion_lista.EsVacia()==false && son_iguales==true){
		if(posicion_mia.pos->e == posicion_lista.pos->e){
			posicion_mia=posicion_mia.Siguiente();
			posicion_lista=posicion_lista.Siguiente();
		}
		else{
			son_iguales=false;
		}

	}

	return son_iguales;

}

int TListaPoro::Longitud()const{//OK
	int longitud=0;
	TListaPosicion recorredor_mi_lista;

	if(this->EsVacia() == false){
		//longitud++;
		recorredor_mi_lista=this->Primera();

		while(recorredor_mi_lista.EsVacia() == false){
			longitud++;
			recorredor_mi_lista=recorredor_mi_lista.Siguiente();
		}
	}

	return longitud;

}


//TListaPoro TListaPoro::operator +(const TListaPoro &lista){

//}

void TListaPoro::Copia(const TListaPoro &lista){
	TListaPosicion mi_lista;
	TListaPosicion otra_lista;
	TListaPosicion aux;//Para guardar el poro anterior para poder asignarle el proximo

	if(lista.EsVacia()){
			this->primero=NULL;
			this->ultimo=NULL;
	}
	else{
		otra_lista=lista.Primera();
		this->primero= new TListaNodo(*otra_lista.pos);
		this->primero->anterior=NULL;//El naterior del primero es NULL
		mi_lista.pos=primero;
		otra_lista=otra_lista.Siguiente();
		while(otra_lista.EsVacia()==false){
			aux=mi_lista;//Almacenamos temporalmente la pos de memoria del poro anterior
			mi_lista=mi_lista.Siguiente();//Al principoi, hasta que no lo asignemos es NULL
			mi_lista.pos = new TListaNodo(*otra_lista.pos);
			(*aux.pos).siguiente=mi_lista.pos;//Le asignamos al siguiente del poro anteriror la pos de memoria del siguiente
			(*mi_lista.pos).anterior=aux.pos;//Al creado ahora, le indicamos cual es su anterior
			otra_lista=otra_lista.Siguiente();
		}
		(*mi_lista.pos).siguiente=NULL;//El siguiente del ultimo es NULL
		this->ultimo=mi_lista.pos;
	}
}

TListaPoro::TListaPoro(const TListaPoro &lista){//Casi ok
	Copia(lista);

}

TListaPoro& TListaPoro::operator =(const TListaPoro &lista){
	if(this!=&lista){
		(*this).~TListaPoro();
		Copia(lista);

	}
	return *this;

}

TPoro TListaPoro::Obtener(const TListaPosicion &posicion)const{//OK
	TPoro poro;
	TListaPosicion recorredor;
	bool obtener=false;
	recorredor=this->Primera();
	while(obtener==false && recorredor.EsVacia() == false){
		if(posicion.pos == recorredor.pos){
			obtener=true;
			poro=(*recorredor.pos).e;
		}
		recorredor=recorredor.Siguiente();
	}

	return poro;

}

bool TListaPoro::Insertar(const TPoro &poro){
	bool insertado=false;
	TListaNodo *nodo;
	TListaPosicion recorredor;
	TListaPosicion recorredor_anterior;
	nodo = new TListaNodo;
	nodo->e = poro;
	if(this->EsVacia()){
		//nodo = new TListaNodo();
		//nodo->e= poro;
		//nodo->anterior=NULL;		nodo->siguiente=NULL;
		this->primero=nodo;
		this->ultimo=nodo;
		insertado=true;
	}
	else{
		if(this->Buscar(poro) == false){//Miramos que no exista ya ese poro
			if(this->Primera().pos->e.Volumen() > poro.Volumen()){//Lo insertamos al incio, si es el menor
				//nodo = new TListaNodo();
				//nodo->e=poro;
				nodo->siguiente=this->Primera().pos;//El siguiente del ahora primero, es el anterior primeros
				this->Primera().pos->anterior=nodo;//El anteriror del anterior primero, es el primero de ahora--Al ser un puntero no necesitamos el &
				this->primero=nodo;//Por ultimo, ahora tenemos un nuevo primero
				insertado=true;
			}
			else if(this->Ultima().pos->e.Volumen() <= poro.Volumen()){//Miramos si puede ser el ultimo, para esto se supone que esta ordenado
				//nodo = new TListaNodo();
				//nodo->e=poro;
				nodo->anterior=this->Ultima().pos;
				this->Ultima().pos->siguiente=nodo;
				this->ultimo=nodo;
				insertado=true;

			}
			else{
				recorredor=this->Primera();
				recorredor=recorredor.Siguiente();//La primera ya la hemos comprobado, la saltamos
				while(poro.Volumen() >= recorredor.pos->e.Volumen() && recorredor.EsVacia() == false){
					recorredor=recorredor.Siguiente();
				}
				//nodo = new TListaNodo();
				//nodo->e=poro;
				recorredor_anterior=recorredor.Anterior();//Guardamos auxilirmente, el anterior del actual, que sera el anterior del nuevo
				nodo->siguiente=recorredor.pos;//El siguiente de nuestro nuevo nodo
				nodo->anterior=recorredor.pos->anterior;//El anterior de nuestro nuevo nodo, sera el anterior delactual
				recorredor.pos->anterior=nodo;//El anterior, ahora su siguiente sera el nuevo nodo
				recorredor_anterior.pos->siguiente=nodo;
				insertado=true;

			}
		}
	}
	return insertado;

}

TListaPoro TListaPoro::operator +(const TListaPoro &lista){
	TListaPosicion recorredor_lista_this;
	TListaPosicion recorredor_lista_dada;
	TListaPoro nueva_lista;

	recorredor_lista_this=this->Primera();
	recorredor_lista_dada=lista.Primera();

	while(recorredor_lista_this.EsVacia() == false){
		nueva_lista.Insertar(recorredor_lista_this.pos->e);
		recorredor_lista_this=recorredor_lista_this.Siguiente();
	}

	while(recorredor_lista_dada.EsVacia() == false){
			nueva_lista.Insertar(recorredor_lista_dada.pos->e);
			recorredor_lista_dada=recorredor_lista_dada.Siguiente();
	}

	return nueva_lista;

}

bool TListaPoro::Borrar(TPoro &poro){
	bool borrado=false;
	TListaPosicion recorredor;


	if(this->EsVacia() == true || this->Buscar(poro) == false ){
		return borrado;
	}
	else{
		if(this->Primera().pos->e == poro){//Si el poro se encuentra al inicio
			if(Longitud() == 1){//Si solo hay un elemento en la lista

				delete primero;
				primero=ultimo=NULL;
				//this->~TListaPoro();
				borrado=true;
			}
			else{
				recorredor = Primera();
				this->primero->siguiente->anterior=NULL;//El ahora primero apuntara a NULL
				this->primero=this->primero->siguiente;//primero apunta al siguiete nodo
				delete recorredor.pos;
				recorredor.pos=NULL;
				borrado=true;
				//recorredor.pos->~TListaNodo();
			}
		}
		else if(this->Ultima().pos->e == poro){//Si es el ultimo
			recorredor = Ultima();
			ultimo->anterior->siguiente=NULL;
			ultimo=ultimo->anterior;
			delete recorredor.pos;
			recorredor.pos=NULL;

			borrado=true;
			//recorredor.pos->~TListaNodo();
		}
		else{
			recorredor=this->Primera();
			recorredor=recorredor.Siguiente();
			while(borrado == false && recorredor.EsVacia() == false){
				if(recorredor.pos->e == poro){
					recorredor.pos->anterior->siguiente=recorredor.pos->siguiente;
					recorredor.pos->siguiente->anterior=recorredor.pos->anterior;
					delete recorredor.pos;
					recorredor.pos=NULL;
					borrado=true;
				}
				else{
					recorredor=recorredor.Siguiente();
				}
			}


		}
		return borrado;
	}

}

bool TListaPoro::Borrar(TListaPosicion &posicion){
	bool borrado;
	borrado = this->Borrar(posicion.pos->e);
	return borrado;

}

TListaPoro TListaPoro::operator -(const TListaPoro &lista){
	TListaPoro mi_lista;
	TListaPosicion recorredor_otra_lista;
	mi_lista=(*this);

	recorredor_otra_lista=lista.Primera();
	while(recorredor_otra_lista.EsVacia() == false){
		if(mi_lista.Buscar(recorredor_otra_lista.pos->e) == true){
			mi_lista.Borrar(recorredor_otra_lista.pos->e);
		}
		recorredor_otra_lista=recorredor_otra_lista.Siguiente();

	}

	return mi_lista;
}

ostream& operator<<(ostream &os, const TListaPoro &lista){
	TListaPosicion recorredor;
	if(lista.EsVacia()){
		os<<"()";
	}
	else{
		recorredor=lista.Primera();
		os<<"(";
		while(recorredor.EsVacia() == false){
			os<<lista.Obtener(recorredor);
			//os<<recorredor.pos->e;
			if(!(lista.Ultima() == recorredor)){
				os<<" ";
			}
			recorredor=recorredor.Siguiente();
		}
		os<<")";
	}

	return os;
}

TListaPoro TListaPoro::ExtraerRango(int n1, int n2)const{
	TListaPoro mi_lista_nueva;
	TListaPosicion recorredor_nueva_lista;
	TListaPosicion recorredor_esta_lista;
	int recorredor_int_esta_lista;
	if(n1>n2){
			return mi_lista_nueva;
	}

	if(n1<=0){
		n1=1;
	}
	if(n2>this->Longitud()){
		n2=this->Longitud();
	}

	recorredor_esta_lista=this->Primera();

	for(recorredor_int_esta_lista=1; recorredor_int_esta_lista <= n2; recorredor_int_esta_lista++){//Para insertar en la nueva lista
		if(recorredor_int_esta_lista >= n1 && recorredor_int_esta_lista <= n2){//Cuando entra aqui es por hay que modificar
			mi_lista_nueva.Insertar(recorredor_esta_lista.pos->e);//Lo insertamos

		}
		recorredor_esta_lista=recorredor_esta_lista.Siguiente();
	}


	recorredor_esta_lista=this->Primera();
	for(recorredor_int_esta_lista=1; recorredor_int_esta_lista <= n2; recorredor_int_esta_lista++){//Para borrar en la vieja lista
			if(recorredor_int_esta_lista >= n1 && recorredor_int_esta_lista <= n2){//Cuando entra aqui es por hay que modificar
				//this->Borrar(recorredor_esta_lista.pos->e);


			}
			recorredor_esta_lista=recorredor_esta_lista.Siguiente();
	}




	return mi_lista_nueva;











}
