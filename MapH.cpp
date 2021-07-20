#include <bits/stdc++.h>
#include "MapH.h"
using namespace std;

MapH::MapH(int N){
	v = vector<pair<string,int>>(N/2);
	fill =0;
	colisionesAt=0;
	colisionesInsert=0;
}
MapH::~MapH(){
}
void MapH::insert(pair<string,int> p){
	float alpha = (float)fill/(float)v.size();
	if(alpha >=0.5) rehash();
	//cout<<"v.size despues de rehash es: "<<v.size()<<endl;
	int indice = hashf(p.first,v.size());
	int cont= 1;
	//cout<<"v.size es: "<<v.size()<<endl;
	//cout<<"el número obtenido de la función hash es: "<<indice<<endl;
	for(int i=0;i<v.size();i++){
		if(v[indice].first==""||v[indice].first=="$"){
			v[indice].first = p.first;
			v[indice].second = p.second;
			fill++;
			return;
		}
		else if(v[indice].first == p.first){
			return;
		}
		else{
			colisionesInsert++;
			indice = (indice+cont*dHashf(p.first,v.size()))%v.size();
		}
	}
	return;
}
void MapH::erase(string s){
	int indice = hashf(s,v.size());
	int cont = 1;
	//cout<<"el número obtenido de la función hash es: "<<indice<<endl;
	for(int i=0;i<v.size();i++){
		if(v[indice].first==""){
			return;
		}
		else if(v[indice].first == s){
			v[indice].first = "$";
			v[indice].second = INT_MIN;
			fill--;
			return;
		}
		else{
			indice = (indice+cont*dHashf(s,v.size()))%v.size();
		}
	}
	return;
}
int MapH::at(string s){
	int indice = hashf(s,v.size());
	int cont =1;
	//cout<<"el número obtenido de la función hash es: "<<indice<<endl;
	for(int i=0;i<v.size();i++){
		if(v[indice].first==""){
			return INT_MIN;
		}
		else if(v[indice].first == s){
			return v[indice].second;
		}
		else{
			colisionesAt++;
			indice = (indice+cont*dHashf(s,v.size()))%v.size();
		}
	}
	return INT_MIN;
}
int MapH::size(){
	return fill;
}
bool MapH::empty(){
	return size()<1;
}
int MapH::dHashf(string s,int n){
	int k = hashf(s,n);
	return 47 - (k%47);
}
int MapH::hashf(string s,int n){
	int suma=0;
	//cout<<"el entero pasado a hasf es: "<<n<<endl;
	for(int i=0;i<s.size();i++){
		suma=(suma*7)+(int)s[i];
		//cout<<s[i]<<": "<<(int)s[i]<<endl;
	}
	//cout<<"siguiente: "<<endl;
	return suma%n;
}
void MapH::rehash(){
	int n = v.size()*2;
	//cout<<"v.size(): "<<v.size();
	fill =0;
	vector<pair<string,int>> aux = vector<pair<string,int>>(n);
	for(int i=0;i<v.size();i++){
		if(v[i].first!=""&&v[i].first!="$"){
			int cont=1;
			int indice = hashf(v[i].first,n);
			for(int j=0;j<aux.size();j++){
				if(aux[indice].first==""||aux[indice].first=="$"){
					aux[indice].first = v[i].first;
					aux[indice].second = v[i].second;
					fill++;
					break;
				}
				else if(aux[indice].first == v[i].first){
					break;
				}
				else{
					indice = (indice+cont*dHashf(v[i].first,n))%aux.size();
				}
			}
		}		
	}
	v = aux;
}
void MapH::printList(){
	for(int i=0;i<v.size();i++){
		cout<<"key: "<<v[i].first<<"- value: "<<v[i].second<<endl;
	}
}
int MapH::getColisionesAt(){
	return colisionesAt;
}
int MapH::getColisionesInsert(){
	return colisionesInsert;
}