/*
 * tlistaporo.h
 *
 *  Created on: 15/03/2016
 *      Author: pepe
 */

#ifndef TLISTAPORO_H_
#define TLISTAPORO_H_

#include "tporo.h"

class TListaNodo {
friend class TListaPoro;
friend class TListaPosicion;
private:
	TPoro e;
	TListaNodo *anterior;
	TListaNodo *siguiente;
public:
	//Canonica
	TListaNodo();
	TListaNodo(const TListaNodo &);
	~TListaNodo();
	TListaNodo & operator=(const TListaNodo &);
};




class TListaPosicion {
friend class TListaPoro;
//friend class TListaNodo;

private:
	TListaNodo *pos;

public:
	//Canonica
	TListaPosicion();
	TListaPosicion(const TListaPosicion &);
	~TListaPosicion();
	TListaPosicion & operator=(const TListaPosicion &);

	//Metodos
	bool operator==(const TListaPosicion &)const;
	TListaPosicion Anterior()const;
	TListaPosicion Siguiente()const;
	bool EsVacia()const;
};



class TListaPoro {
friend ostream & operator <<(ostream &, const TListaPoro &);
friend class TListaPoscion;  ///NECESARIO AMISTAD????
//friend class TListaPoro;

private:
	TListaNodo *primero;
	TListaNodo *ultimo;
	void Copia(const TListaPoro &);

public:
	//Canonica
	TListaPoro();
	TListaPoro(const TListaPoro &);
	~TListaPoro();
	TListaPoro & operator =(const TListaPoro &);

	//Metodos
	bool operator==(const TListaPoro &)const;
	TListaPoro operator+(const TListaPoro &);
	TListaPoro operator-(const TListaPoro &);
	bool EsVacia()const;
	bool Insertar(const TPoro &);
	bool Borrar(TPoro &);
	bool Borrar(TListaPosicion &);
	TPoro Obtener(const TListaPosicion &)const;
	bool Buscar(const TPoro &)const;
	int Longitud()const;
	TListaPosicion Primera()const;
	TListaPosicion Ultima()const;
	TListaPoro ExtraerRango(int n1, int n2)const;



};
#endif /* TLISTAPORO_H_ */
