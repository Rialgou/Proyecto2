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
public:
	MapAVL();
	~MapAVL();
	void insert(pair<string,int> p);
	Nodo * insertRec(Nodo * raiz, Nodo * nuevo);
	void erase(string );
	int at(string );
	int size();
	bool empty();
	void printAVL(Nodo * r, int space);
	int getBalanceFactor(Nodo * );
	Nodo * rightRotate(Nodo * );
	Nodo * leftRotate(Nodo * );
	int height(Nodo *);
	bool abcMenor(string s1, string s2);
	Nodo * getRaiz();
};
#endif