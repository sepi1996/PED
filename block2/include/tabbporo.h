/*
 * tabbporo.h
 *
 *  Created on: 29 de mar. de 2016
 *      Author: pepe
 */

#ifndef TABBPORO_H_
#define TABBPORO_H_

#include "tporo.h"
#include "tvectorporo.h"
#include "tabbporo.h"


class TNodoABB;

class TABBPoro {
	//friend class TNodoABB;
	friend ostream & operator<<(ostream &, const TABBPoro &);
public:
	TABBPoro();
	TABBPoro(const TABBPoro &);
	~TABBPoro();
	TABBPoro & operator=(const TABBPoro &);
	bool operator==(const TABBPoro &)const;
	bool EsVacio()const;
	bool Insertar(const TPoro &);
	bool Borrar(const TPoro &);
	bool Buscar(const TPoro &)const;
	TPoro Raiz()const;
	int Altura()const;
	int Nodos()const;
	int NodosHoja()const;
	TVectorPoro Inorden()const;
	TVectorPoro Preorden()const;
	TVectorPoro Postorden()const;
	TVectorPoro Niveles()const;
	TABBPoro operator+(const TABBPoro &)const;
	TABBPoro operator-(const TABBPoro &)const;
private:
	TNodoABB *nodo;
	void InordenAux(TVectorPoro &, int &)const;
	void PreordenAux(TVectorPoro &, int &)const;
	void PostordenAux(TVectorPoro &, int &)const;
	void Copiar(const TABBPoro &);
	bool BorrarAux(const TPoro &, TNodoABB *);
	bool Borrar1(const TPoro &, TNodoABB *);
	TNodoABB* Minimo();
	void OperatorMas(const TABBPoro &);
	void OperatorMenos(const TABBPoro &);
};

class TNodoABB{
	friend class TABBPoro;
public:
	TNodoABB();
	TNodoABB(const TNodoABB &);
	~TNodoABB();
	TNodoABB & operator=(const TNodoABB &);

private:
	TPoro item;
	TABBPoro iz;
	TABBPoro de;

};







#endif /* TABBPORO_H_ */
