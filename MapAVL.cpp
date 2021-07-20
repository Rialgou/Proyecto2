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
Nodo * MapAVL::insertRec(Nodo * raiz, Nodo * nuevo){
	if(raiz == NULL){
		raiz = nuevo;
	}
	return NULL;
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
int MapAVL::getBalanceFactor(Nodo * r){
	return 0;
}
Nodo * MapAVL::rightRotate(Nodo * y){
	return NULL;
}
Nodo * MapAVL::leftRotate(Nodo * x){
	return NULL;
}