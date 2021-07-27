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
		//si el nodo es vacio se retorna
    if (r == NULL){
		return;
    } 
    //hacemos un recorrido postorder eliminando cada nodo en esa dispocision
    destructorRec(r -> izquierdo);
    destructorRec(r -> derecho);
    delete r;
    r = NULL;
}
void MapAVL::insert(pair<string,int> p){
	//creamos un nodo nuevo
	Nodo * nuevo = new Nodo(make_pair(p.first,p.second));
	//utilizamos nuestra funcion recursiva de insertar
	raiz = insertRec(raiz, nuevo);
}
Nodo * MapAVL::insertRec(Nodo * r,Nodo * nuevo){
	//si no hay raiz, se crea
	if(r == NULL){
		r = nuevo;
		//cout<<"se ingreso el nodo raiz"<<endl;
		return r;
	}
	//si la clave del nodo nuevo es igual a la clave en el nivel, se retorna la raiz
	else if(nuevo->clave == r->clave){
		//cout<<"el elemento esta repetido"<<endl;
		return r;
	}
	//si la clave nueva es menor que la clave del nivel, bajamos por la rama izquierda
	else if(abcMenor(nuevo->clave,r->clave)){
		r->izquierdo = insertRec(r->izquierdo,nuevo);
	} 
	//si la clave nueva es mayor que la clave del nivel, bajamos por la rama derecha
	else if(!abcMenor(nuevo->clave,r->clave)){
		r->derecho = insertRec(r->derecho,nuevo);
	}
	//hasta este momento hacemos el recorrido normal de un BST, ahora viene la parte del
	//AVL
	//sacamos el factor de balance, que no es más que calcular la altura del subarbol izquierdo
	//menos la altura del subarbol derecho, esto nos ayudara a determinar el subarbol más
	//grande (bf>1 el hijo izquierdo tiene mayor altura, bf<-1 el hijo derecho tiene mayor altura)
	int bf = getBalanceFactor(r);
	//si el factor de balance es mayor que 1 y la clave del nuevo nodo ingresada 
	//es menor que la clave del hijo izquierdo del nodo r en ese momento 
	//entramos en este caso zig-zig, se aplica rotacion derecha 
	if(bf>1 && abcMenor(nuevo->clave,r->izquierdo->clave)){
		return rightRotate(r);
	}
	//si el factor de balance es menor que -1 y la clave del nuevo nodo ingresada 
	//es mayor que la clave del hijo derecho del nodo r en ese momento 
	//entramos en este caso zig-zig, se aplica rotacion izquierda
	if(bf<-1 && !abcMenor(nuevo->clave,r->derecho->clave)){
		return leftRotate(r);
	}
	//si el factor de balance es mayor que 1 y la clave del nuevo nodo ingresada 
	//es mayor que la clave del hijo izquierdo del nodo r en ese momento 
	//entramos en este caso zig-zag  
	if(bf >1 && !abcMenor(nuevo->clave,r->izquierdo->clave)){
		r->izquierdo = leftRotate(r->izquierdo);
		return rightRotate(r);
	}
	//si el factor de balance es menor que -1 y la clave del nuevo nodo ingresada 
	//es menor que la clave del hijo derecho del nodo r en ese momento 
	//entramos en este caso zig-zag 
	if(bf<-1 && abcMenor(nuevo->clave,r->derecho->clave)){
		r->derecho = rightRotate(r->derecho);
		return leftRotate(r);
	}
	return r;
}
void MapAVL::erase(string s){
	//llama al metodo recursivo de erase
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
	//llama al metodo recursivo de at
	Nodo * numero = atRec(raiz,s);
	//si el nodo devuelto no es nulo, devolvemos el valor de ese nodo
	if(numero!=NULL){
		return numero->valor;
	}
	//si el nodo devuelto es nulo, devolvemos INT_MIN
	else return INT_MIN;
}
Nodo * MapAVL::atRec(Nodo* r,string s){
	//si se encuentra la clave o llegamos a una rama, se retorna r
	if (r == NULL || r -> clave == s)
      return r;
  //si la clave a buscar es menor que la clave del nodo actual, se busca hacia el hijo izquierdo
  else if (abcMenor(s, r->clave)) {
      return atRec(r->izquierdo , s);
  }
  //si la clave a buscar es mayor que la clave del nodo actual, se busca hacia el hijo derecho
  else{
      return atRec(r->derecho, s);
  }
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
	//si el nodo es hoja retornamos -1
	if (n == NULL) return -1;
	//se retorna la altura del hijo izquierdo menos la altura del hijo derecho
  return height(n -> izquierdo) - height(n -> derecho);
}
Nodo * MapAVL::rightRotate(Nodo * y){
	//creamos un nodo x que apunte al hijo izquierdo de y
	Nodo * x = y -> izquierdo;
	//creamos un nodo T2 que sera el auxiliar que apuntara al hijo derecho de x
  Nodo * T2 = x -> derecho;
  //comienza la rotacion, hacemos que el hijo derecho de x sea y
  //y que el hijo izquierdo de y sea T2, de esta forma logramos que x quede a la cabeza
  //y quede como hijo derecho de x y que T2 quede como hijo izquierdo de y 
  x -> derecho = y;
	y -> izquierdo = T2;
	//retornamos la cabeza de esta rotacion, que seria x
	return x;
}
Nodo * MapAVL::leftRotate(Nodo * x){
	//creamos un nodo y que apunte al hijo derecho de x
	Nodo * y = x -> derecho;
	//creamos un nodo T2 que sera el auxiliar que apuntara al hijo derecho de y
	Nodo * T2 = y -> izquierdo;

  //comienza la rotacion, hacemos que el hijo izquierdo de y sea x
  //y que el hijo derecho de x sea T2, de esta forma logramos que y quede a la cabeza
  //x quede como hijo izquierdo de y, y T2 quede como hijo derecho de x
  y -> izquierdo = x;
  x -> derecho = T2;
  //retornamos la cabeza de esta rotacion, que seria y
	return y;
}
int MapAVL::height(Nodo * r){
		//si estamos en una hoja retornamos -1
    if (r == NULL) return -1;
    else {
      //se saca la altura de cada hijo 
      int izqHeight = height(r -> izquierdo);
      int derHeight = height(r -> derecho);

      //retornamos la altura del mayor hijo
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
    //se busca a la hoja mas externa de la izquierda 
    while (current -> izquierdo != NULL) {
      	current = current -> izquierdo;
    }
    return current;
}