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

public:
	MapAVL();
	~MapAVL();
	void insert(pair<string,int> p);
	void erase(string s);
	int at(string s);
	int size();
	bool empty();
	void printList();
};
#endif