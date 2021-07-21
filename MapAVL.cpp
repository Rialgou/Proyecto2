#include <bits/stdc++.h>
#include "MapAVL.h"
using namespace std;

MapAVL::MapAVL(){
	raiz = NULL;
}
MapAVL::~MapAVL(){
}
void MapAVL::insert(pair<string,int> p){
	Nodo * nuevo = new Nodo(make_pair(p.first,p.second));
	raiz = insertRec(raiz, nuevo);
}
Nodo * MapAVL::insertRec(Nodo * r, Nodo * nuevo){
	if(r == NULL){
		r = nuevo;
		cout<<"se ingreso el nodo raiz"<<endl;
		return r;
	}
	if(nuevo->clave == r->clave){
		cout<<"el elemento esta repetido"<<endl;
		return r;
	}
	else if(abcMenor(nuevo->clave,r->clave)){
		r->izquierdo = insertRec(r->izquierdo,nuevo);
	} 
	else if(!abcMenor(nuevo->clave,r->clave)){
		r->derecho = insertRec(r->derecho,nuevo);
	}
	return r;
}
void MapAVL::erase(string s){

}
int MapAVL::at(string s){
	return 0;
}
int MapAVL::size(){
	return 0;
}
bool MapAVL::empty(){
	if(raiz == NULL) return true;
	else return false;
}
void MapAVL::printList(){

}
int MapAVL::getBalanceFactor(Nodo * n){
	if (n == NULL) return -1;
    return height(n -> izquierdo) - height(n -> derecho);
}
Nodo * MapAVL::rightRotate(Nodo * y){
	Nodo * x = y -> izquierdo;
    Nodo * T2 = x -> derecho;

    // Perform rotation  
    x -> derecho = y;
    y -> izquierdo = T2;

    return x;
}
Nodo * MapAVL::leftRotate(Nodo * x){
	Nodo * y = x -> derecho;
    Nodo * T2 = y -> izquierdo;

    // Perform rotation  
    y -> izquierdo = x;
    x -> derecho = T2;

    return y;
}
int MapAVL::height(Nodo * r){
    if (r == NULL) return -1;
    else {
      /* se saca la altura de cada hijo */
      int izqHeight = height(r -> izquierdo);
      int derHeight = height(r -> derecho);

      /* usamos el mayor */
      if (izqHeight > derHeight)
        return (izqHeight + 1);
      else return (derHeight + 1);
    }
}
bool MapAVL::abcMenor(string s1, string s2){
	int menorEspacio;
	int contador = 0;
	if(s1.size() == s2.size()){
		for(int i=0;i<s1.size();i++){
			if(tolower(s1[i])< tolower(s2[i])) return true;
			else if(tolower(s1[i])>tolower(s2[i])) return false;
		}
	}
	else if(s1.size()>s2.size()){
		menorEspacio = s2.size();
		for(int i=0;i<menorEspacio;i++){
			if(tolower(s1[i])< tolower(s2[i])) return true;
			else if(tolower(s1[i])>tolower(s2[i])) return false;
			else contador++;
		}
		if(contador == menorEspacio){
			return false;
		}
	}
	else{
		menorEspacio = s1.size();
		for(int i=0;i<menorEspacio;i++){
			if(tolower(s1[i])< tolower(s2[i])) return true;
			else if(tolower(s1[i])>tolower(s2[i])) return false;
			else contador++;
		}
		if(contador == menorEspacio){
			return true;
		}
	} 
	return false;
}