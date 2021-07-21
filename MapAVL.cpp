#include <bits/stdc++.h>
#include "MapAVL.h"
using namespace std;

MapAVL::MapAVL(){
	raiz = NULL;
}
MapAVL::~MapAVL(){
	destructorRec(raiz);
	raiz = NULL;
}
void MapAVL::destructorRec(Nodo * r){
    if (r == NULL){
		return;
    } 
    destructorRec(r -> izquierdo);
    destructorRec(r -> derecho);
    delete r;
    r = NULL;
}
void MapAVL::insert(pair<string,int> p){
	Nodo * nuevo = new Nodo(make_pair(p.first,p.second));
	raiz = insertRec(raiz, nuevo);
}
Nodo * MapAVL::insertRec(Nodo * r,Nodo * nuevo){
	if(r == NULL){
		r = nuevo;
		cout<<"se ingreso el nodo raiz"<<endl;
		return r;
	}
	else if(nuevo->clave == r->clave){
		cout<<"el elemento esta repetido"<<endl;
		return r;
	}
	else if(abcMenor(nuevo->clave,r->clave)){
		r->izquierdo = insertRec(r->izquierdo,nuevo);
	} 
	else if(!abcMenor(nuevo->clave,r->clave)){
		r->derecho = insertRec(r->derecho,nuevo);
	}
	int bf = getBalanceFactor(r);
	if(bf>1 && abcMenor(nuevo->clave,r->izquierdo->clave)){
		return rightRotate(r);
	}
	if(bf<-1 && !abcMenor(nuevo->clave,r->derecho->clave)){
		return leftRotate(r);
	}
	if(bf >1 && !abcMenor(nuevo->clave,r->izquierdo->clave)){
		r->izquierdo = leftRotate(r->izquierdo);
		return rightRotate(r);
	}
	if(bf<-1 && abcMenor(nuevo->clave,r->derecho->clave)){
		r->derecho = rightRotate(r->derecho);
		return leftRotate(r);
	}
	return r;
}
void MapAVL::erase(string s){
	raiz = eraseRec(raiz,s);
}
Nodo * MapAVL::eraseRec(Nodo * r,string s){
	if(r == NULL){
		return NULL;
	}
	else if(s == r->clave){
		if (r -> izquierdo == NULL){
        	Nodo * aux = r -> derecho;
        	delete r;
        	return aux;
      	}
      	else if (r -> derecho == NULL){
        	Nodo * aux = r -> izquierdo;
        	delete r;
        	return aux;
      	}
      	else{
        	Nodo * aux = minValueNodo(r->derecho);;
        	r -> clave = aux -> clave;
        	r -> valor = aux -> valor; 
        	r -> derecho = eraseRec(r -> derecho, aux -> clave); 
      }
	}
	else if (abcMenor(s,r->clave)) {
      r -> izquierdo = eraseRec(r -> izquierdo, s);
    }
    else{
      r -> derecho = eraseRec(r -> derecho, s);
    }
    return r;
}
int MapAVL::at(string s){
	Nodo * numero = atRec(raiz,s);
	if(numero!=NULL){
		return numero->valor;
	}
	else return INT_MIN;
}
Nodo * MapAVL::atRec(Nodo* r,string s){
	if (r == NULL || r -> clave == s)
      return r;

    else if (abcMenor(s, r->clave)) {
      return atRec(r->izquierdo , s);
    }
    else{
      return atRec(r->derecho, s);
    }
    return r;
}
int MapAVL::size(){
	return 0;
}
bool MapAVL::empty(){
	if(raiz == NULL) return true;
	else return false;
}
void MapAVL::printAVL(Nodo *r,int space){
	if(r == NULL){
		return;
	}
	space +=10;
	printAVL(r->derecho,space);
	cout<<endl;
	for(int i = 10;i< space;i++){
		cout<<" ";
	}
	cout<<r->clave <<"-"<<r->valor<<endl;
	printAVL(r->izquierdo,space);
}
int MapAVL::getBalanceFactor(Nodo * n){
	if (n == NULL) return -1;
    return height(n -> izquierdo) - height(n -> derecho);
}
Nodo * MapAVL::rightRotate(Nodo * y){
	Nodo * x = y -> izquierdo;
    Nodo * T2 = x -> derecho;

    // rotacion  
    x -> derecho = y;
    y -> izquierdo = T2;

    return x;
}
Nodo * MapAVL::leftRotate(Nodo * x){
	Nodo * y = x -> derecho;
    Nodo * T2 = y -> izquierdo;

    // rotacion 
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
Nodo * MapAVL::getRaiz(){
	return raiz;
}
Nodo * MapAVL::minValueNodo(Nodo * nodo){
    Nodo * current = nodo;
    /* se busca a la hoja mas externa de la izquierda */
    while (current -> izquierdo != NULL) {
      	current = current -> izquierdo;
    }
    return current;
}