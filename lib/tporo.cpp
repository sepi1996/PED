#include "../include/tporo.h"

TPoro::TPoro(){
	x=0;
	y=0;
	volumen=0;
	color=NULL;//color apunta a null
}

TPoro::TPoro(int xx, int yy, double v){
	x=xx;
	y=yy;
	volumen=v;
	color=NULL;
}

TPoro::TPoro(int x, int y, double volumen, char* c){
	this->x=x;
	this->y=y;
	this->volumen=volumen;
	color = NULL;
	Color(c);
}

void TPoro::Copia(const TPoro &poro){
	x=poro.x;
	y=poro.y;
	volumen=poro.volumen;
	Color(poro.color);
}

TPoro::TPoro(const TPoro &p){//Hace falta comprobar si son iguales quien llama i el llamado
	color = NULL;
	Copia(p);
}

TPoro::~TPoro(){
	x=0;
	y=0;
	volumen=0;
	if(color != NULL){
		delete[] color;
		color=NULL;
	}
}

TPoro& TPoro::operator=(const TPoro &poro){
	if(this != &poro){//Comporbamos que no sea el mismo
		(*this).~TPoro();//Vaciamos el objeto al que le queremos asignar los nuevos valores
		Copia(poro);
	}
	return *this;
}

bool TPoro::operator==(const TPoro &poro) const{
	bool igualdad=false;

	if((color!=NULL && poro.color!=NULL)){
		if((strcmp (color, poro.color))==0){
			igualdad = (x==poro.x and y==poro.y and volumen==poro.volumen) ? true : false;
		}
	}
	if(color==NULL && poro.color==NULL){
		igualdad = (x==poro.x and y==poro.y and volumen==poro.volumen) ? true : false;
	}
	return igualdad;
}

bool TPoro::operator!=(const TPoro &poro) const{
	return !(*this == poro);//*this apunta al contenido de la variable que invoca el opreador sobrecargado---//poro es el contenido de la variable pasada por referencia
}


void TPoro::Color (char *c){
	if(color != NULL) {
		delete[] color;
		color = NULL;
	}
	if(c != NULL) {
		color = new char[strlen(c)+1];
		int i;
		for(i = 0; c[i]; i++) {
			color[i] = tolower(c[i]);
		}
		color[i] = '\0';
	}
}


char* TPoro::Color() const{
	return color;
}


bool TPoro::EsVacio() const{
	if(x==0 and y==0 and volumen==0 and color==NULL){
		return true;
	}
	else return false;
}

ostream& operator<<(ostream &os, const TPoro &poro){
	if(!poro.EsVacio()){
		os.setf(ios::fixed);
		os.precision(2);
		os<<"("<<poro.x<<", "<<poro.y<<") "<<poro.volumen<<" ";
		if(poro.color != NULL)
			os<<poro.color;
		else
			os<<"-";
	}
	else
		os<<"()";

	return os;
}
