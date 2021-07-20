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
	if(v.size()>0){
		int primero =0;
		int ultimo = v.size()-1;
		int medio = (ultimo+primero)/2;
		while (primero<=ultimo){
        	if (abcMenor(v[medio].first,s)){
            	primero=medio+1;
        	} 
        	else if (v[medio].first== s){
            	cout<<" Se encontro la posición "<<endl;
            	cout<<medio+1<<endl;
            	return v[medio].second;
            	break;
        	}
        	else {
        	    ultimo = medio - 1;
        	}
        	medio = (primero+ultimo)/2;
    	}
    	if (primero>ultimo){
    	    cout<<s<<" no se encontro";
    	    return INT_MIN;
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