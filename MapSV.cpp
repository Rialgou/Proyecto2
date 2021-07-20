#include <bits/stdc++.h>
#include "MapSV.h"
using namespace std;

MapSV::MapSV(){

}
MapSV::~MapSV(){

}
void MapSV::insert(pair<string,int> p){
	if(v.size()>0){
		for(int i=0;i<v.size();i++){
			if(v[i].first == p.first){
				return;
			}	
		}
		v.push_back(make_pair(p.first,p.second));
		sort(v.begin(),v.end());
	}
	else{
		v.push_back(make_pair(p.first,p.second));
		sort(v.begin(),v.end());
	}
}
void MapSV::erase(string s){
	for(int i=0;i<v.size();i++){
		if(v[i].first == s){
			v.erase(v.begin()+i);
		}
	}	
	return;
}
int MapSV::at(string s){
	for(int i=0;i<v.size();i++){
		if(v[i].first == s){
			return v[i].second;
		}
	}
	return INT_MIN;
}
int MapSV::size(){
	return v.size();
}
bool MapSV::empty(){
	return v.empty();
}
void MapSV::printList(){
	for(int i = 0;i<v.size();i++){
		cout<<v[i].first<<" - "<<v[i].second<<endl;
	}
}
bool MapSV::abcMenor(string s1, string s2){
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