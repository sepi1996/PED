#include <iostream>
#include <sstream>
#include <cstdlib>
#include "../include/tporo.h"
#include "../include/tvectorporo.h"
#include "../include/tlistaporo.h"
#include "../include/tabbporo.h"
using namespace std;




int
main(void){

			TPoro p1(1, 2, 3, (char*) "p1");
			TPoro p2(3, 2, 1, (char*) "p2");
			TPoro p3(2, 3, 2, (char*) "p3");
			TPoro p4(2, 3, 6, (char*) "p4");
			TPoro p5(2, 3, 0, (char*) "p5");
			TPoro p6(2, 3, 0.5, (char*) "p6");

			TABBPoro a;
			a.Insertar(p1);
			a.Insertar(p2);
			a.Insertar(p3);
			a.Insertar(p4);
			a.Insertar(p5);
			a.Insertar(p6);

			cout<<a.Inorden()<<endl;
			cout<<a.Niveles()<<endl;

			a.Borrar(p5);

			cout<<a.Inorden()<<endl;
			cout<<a.Niveles()<<endl;

			TABBPoro b;
			b=a;
			if(b==a){
				cout<<"OK"<<endl;
			}
			cout<<b;
			int numNodos=a.Nodos();
			int numNodosHoja=a.NodosHoja();

			cout<<numNodos<<endl;
			cout<<numNodosHoja<<endl;

			TVectorPoro vecin;
			TVectorPoro vecpre;
			TVectorPoro vecpos;

			vecin=a.Inorden();
			cout<<vecin<<endl;

			vecpre=a.Postorden();
			cout<<vecpre<<endl;

			vecpos=a.Preorden();
			cout<<vecpos<<endl;

			TABBPoro z;
			TPoro p10(1, 2, 10, (char*) "p5");
			TPoro p9(3, 2, 0, (char*) "p6");
			TPoro p7(3, 2, 5, (char*) "p7");
			TPoro p8(3, 2, 60, (char*) "p8");

			z.Insertar(p10);
			z.Insertar(p9);
			z.Insertar(p7);
			z.Insertar(p8);

			TABBPoro c;
			c=z+a;

			cout<<c.Inorden()<<endl;

			TABBPoro d;

			d.Insertar(p8);
			d.Insertar(p9);
			d.Insertar(p7);
			d.Insertar(p10);

			if(d==z){
				cout<<"ok"<<endl;
			}

			cout<<"NIVEELES"<<endl;
			cout<<d.Niveles()<<endl;

			//cout << a << endl;
}



