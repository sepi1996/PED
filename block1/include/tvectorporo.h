/*
 * tvectorPoro.h
 *
 *  Created on: 17 de feb. de 2016
 *      Author: jps74
 */

#ifndef TVECTORPORO_H_
#define TVECTORPORO_H_

#include "tporo.h"

class TVectorPoro {

friend ostream& operator<<(ostream &,const TVectorPoro &);

private:
	int dimension;
	TPoro *datos;
	TPoro error;
	void Copia(const TVectorPoro &);

public:
	//Canonica
	TVectorPoro();
	TVectorPoro(int);
	TVectorPoro(const TVectorPoro &);
	~TVectorPoro();
	TVectorPoro & operator=(const TVectorPoro &);

	//Metodos
	bool operator ==(const TVectorPoro &) const;
	bool operator !=(const TVectorPoro &) const;
	TPoro& operator[](int);//Parte izquierda, devolucion por referencia, no hace copia
	TPoro operator[](int) const;//Parte derecha, hace una copia llamando al construcotr de copia
	int Longitud() const {return dimension; }
	int Cantidad() const;
	bool Redimensionar(int);

	TPoro* getDatosPtr() {return datos;}


};

#endif /* TVECTORPORO_H_ */


