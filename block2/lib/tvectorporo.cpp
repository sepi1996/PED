/*
 * tvectorPoro.cpp
 *
 *  Created on: 17 de feb. de 2016
 *      Author: jps74
 */

#include "../include/tvectorporo.h"

TVectorPoro::TVectorPoro():error(){//invoca al construcotr por defecto de TPoro
	dimension=0;
	datos=NULL;
}

TVectorPoro::TVectorPoro(int tam){
	if(tam<=0){
		dimension=0;
		datos=NULL;

	}
	else{
		dimension=tam;
		datos= new TPoro [(int)dimension];
		//for(int i=0; i<tam ; i++){
			//datos[i] = TPoro();//Asi llamamos al construcotor por defecto de TPoro?
		//}
	}
}

void TVectorPoro::Copia(const TVectorPoro &vector){//Invocar al de copia
	if(vector.dimension<=0){
		dimension=0;
		datos=NULL;
	}
	else{
		dimension=vector.dimension;
		datos= new TPoro [(int)vector.dimension];
		for(int i=0; i<vector.dimension; i++){
				datos[i] = vector.datos[i];//Con la sobrecarga del operador =, hacemos una copia de vector.datos[i] en datos[i]
				//Aunque el vector.datos[i] sea un poro vacio, el constructor lo hace vacio tambie
		}

	}
}

TVectorPoro::TVectorPoro(const TVectorPoro &vector) : error(vector.error){//Bien
	Copia(vector);
}



TVectorPoro::~TVectorPoro(){
	dimension=0;
	if(datos!=NULL){
		delete [] datos;
		datos=NULL;
	}
}

TVectorPoro& TVectorPoro::operator =(const TVectorPoro &vector){//OK
	if(this != &vector){
		(*this).~TVectorPoro();
		Copia(vector);
	}

	return *this;

}

bool TVectorPoro::operator ==(const TVectorPoro &vector) const{//OK
	if(dimension != vector.dimension){
		return false;
	}
	else{
		for(int i=0; i<vector.dimension; i++){
			if(datos[i] != vector.datos[i]){//Llamamos al operador sobrecargado != para ver si son iguales, sus datos TPoro
				return false;
			}
		}
		return true;
	}
}

bool TVectorPoro:: operator!=(const TVectorPoro &vector) const{//OK
	return !(*this == vector);
}



TPoro& TVectorPoro::operator[](int pos){
	if(pos>=1 && pos<= dimension){
			return datos[pos-1];
	}
	else{
		return error;
	}
}

TPoro TVectorPoro::operator[](int pos) const{
	if(pos>=1 && pos<= dimension){
		return datos[pos-1];
	}
	else{
		return error;
	}
}

int TVectorPoro:: Cantidad()const{
	int cantidad=0;
	for(int i=0; i < this->dimension; i++ ){
		if(this->datos[i].EsVacio() == false){
			cantidad++;
		}
	}
	return cantidad;
}

bool TVectorPoro::Redimensionar(int tam){
	if(tam<=0 || this->dimension == tam){
		return false;
	}
	else{
		if(tam>0 && tam>this->dimension){
			TPoro *aux = new TPoro[(int)tam];//creamos un nuevo array

				for(int i=0; i<this->dimension; i++){//le anyadimos lo del array original
					aux[i] = this->datos[i];
				}
				for(int i=this->dimension; i<tam; i++){//el resto a vacio
					aux[i] = TPoro();
				}
				for(int i=0; i<dimension; i++){//eliminamos los poros del antiguo array
					this->datos[i].~TPoro();
				}
				if(datos!=NULL){
					delete [] datos;//Sin []?
					datos=NULL;
				}
				dimension=tam;
				datos=aux;
				return true;

		}
		else if(tam>0 && tam < this->dimension){
			TPoro *aux = new TPoro[(int)tam];//creamos un nuevo array

				for(int i=0; i<tam; i++){//le anyadimos al nuevo array lo del array original
					aux[i]=this->datos[i];
				}
				for(int i=0; i<dimension; i++){//eliminamos los poros del antiguo array
					this->datos[i].~TPoro();
				}
				if(datos!=NULL){
					delete [] datos;//Sin []?
					datos=NULL;
				}
				dimension=tam;
				datos=aux;
				return true;
		}
		else{
			return false;
		}
	}
}


ostream& operator<<(ostream &os, const TVectorPoro &vector){
	if(vector.dimension==0){
		os<<"[]";
	}
	else{
		os<<"[";
		for(int i=0; i<vector.dimension; i++){
			if(i!=0){
				os<<" ";
			}
			os<<(i+1)<<" ";
			os<<vector.datos[i];

		}
		os<<"]";

	}
	return os;


}




