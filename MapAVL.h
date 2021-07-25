//mapa en base a AVL
#ifndef	MAPAVL_H
#define MAPAVL_H
#include "ADTMap.h"
#include <vector>
using namespace std;
struct Nodo{
	string clave;
	int valor;
	Nodo * derecho;
	Nodo * izquierdo;
	Nodo(){
		clave = "";
		valor = INT_MIN;
		derecho = NULL;
		izquierdo = NULL;
	}
	Nodo(pair<string,int> p){
		clave = p.first;
		valor = p.second;
		derecho = NULL;
		izquierdo = NULL;
	}
};
class MapAVL : public ADTMap{

private:
	Nodo * raiz;
	Nodo * insertRec(Nodo * , Nodo * );
	Nodo * eraseRec(Nodo*, string);
	Nodo * atRec(Nodo*,string);
	int getBalanceFactor(Nodo * );
	Nodo * rightRotate(Nodo * );
	Nodo * leftRotate(Nodo * );
	int height(Nodo *);
	bool abcMenor(string , string );
	Nodo * minValueNodo(Nodo *);
	void destructorRec(Nodo * );
public:
	MapAVL();
	~MapAVL();
	void insert(pair<string,int> p);
	void erase(string );
	int at(string );
	int size();
	bool empty();
	void printAVL(Nodo *, int);
	Nodo * getRaiz();
};
#endif