/*
 * tporo.h
 *
 *  Created on: 17 de feb. de 2016
 *      Author: jps74
 */

#ifndef TPORO_H_
#define TPORO_H_

#include <iostream>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> // para tolower
#include <deque>          // std::deque
#include <list>           // std::list
#include <queue>          // std::queue
using namespace std;


class TPoro {
	friend ostream& operator<<(ostream & os, const TPoro & poro);
	private:
		int x;
		int y;
		double volumen;
		char* color;
		void Copia(const TPoro &);

	public:
		//Forma canónica
		TPoro();
		TPoro(int, int, double);
		TPoro(int, int, double, char*);
		TPoro(const TPoro &);
		~TPoro();
		TPoro& operator=(const TPoro &);

		//Metodos
		bool operator==(const TPoro &)const;
		bool operator!=(const TPoro &)const;
		void Posicion(int xx,int yy) {x=xx; y=yy; }
		void Volumen(double v) {volumen=v; }
		void Color(char *);
		int PosicionX() const {return x; }//SE PUEDE HACER INLINE?? HACE FALTA CONST?
		int PosicionY() const {return y; }
		double Volumen() const {return volumen; }
		char * Color() const;
		bool EsVacio() const;



};

#endif /* TPORO_H_ */
