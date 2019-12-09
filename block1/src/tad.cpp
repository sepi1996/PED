#include <iostream>
#include <sstream>
#include <cstdlib>
#include "../include/tporo.h"
#include "../include/tvectorporo.h"
#include "../include/tlistaporo.h"
using namespace std;

int
main(void){

			TPoro p1(1, 2, 3, (char*) "p1");
			TPoro p2(3, 2, 1, (char*) "p2");
			TPoro p3(2, 3, 2, (char*) "p3");
			TPoro p4(2, 3, 6, (char*) "p4");
			TListaPoro a;
			TListaPoro b;
			a.Insertar(p1);
			a.Insertar(p2);
			a.Insertar(p3);
			a.Insertar(p4);

			b=a.ExtraerRango(2, 4);

			cout << a << endl;
			cout << b <<endl;
}



