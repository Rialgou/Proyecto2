#include <bits/stdc++.h>
#include "MapH.h"

using namespace std;

MapH::MapH(int max){
	mysize=0;insCont=0;atCont=0;
	cap={503,1009,1511,2003,2503,3001,3511,4001,4507,5003,6007,7001,8009,9001,10007,12007,14009,16001,18013,20011,20100};
	capacity=max/2;
	for(int i=0;i<21;i++){
		if(capacity+14<cap[i]){
			capacity=cap[i-1];
			break;
		}
	}
	myarray=new pair<string,int>[capacity];
}
MapH::~MapH(){
	delete[] myarray; 
}
int MapH::dhash(string s){
	long pos=0,q=41;
	int z=33;
	for (int i=0;i<s.length();i++) pos+=(long(s[i])*(long)(pow(z,i)));
	return q-((pos)%q);
}
int MapH::hash(string s){
	long pos=0;
	int z=33;
	for (int i=0;i<s.length();i++) pos+=(long(s[i])*(long)(pow(z,i))); 
	return  (pos)%capacity; 
}
void MapH::insert(pair<string,int> p){
	int pos=hash(p.first);
	int des=dhash(p.first);
	for(int i=0;i<capacity;i++){
		if(pos>=capacity) pos=pos-capacity;
		if(myarray[pos].first==""||myarray[pos].first=="$"){
			myarray[pos]=p;
			mysize+=1;
			break;
		}
		else if(myarray[pos].first==p.first){
			break;
		}
		pos+=des;
		insCont+=1;
	}
	if(mysize>capacity/2) rehash();
}
int MapH::at(string s){
	int pos=hash(s);
	for(int i=0;i<capacity;i++){
		//se agrego la condicion en que la clave es vacia, donde se retornara antes
		if(myarray[pos].first == "") {
			cout<<"no encontrado por espacio vacio"<<endl;
			return -1;
		}
		if(s==myarray[pos].first) return myarray[pos].second;
		pos+=dhash(s);
		if(pos>=capacity) pos=pos-capacity;
		atCont+=1;
	}
	cout<<"no encontrado"<<endl;
	return -1;
}
void MapH::erase(string s){
	int pos=hash(s);
	for(int i=0;i<capacity;i++){
		if(s==myarray[pos].first){
			myarray[pos].first="$";
			myarray[pos].second=0;
			mysize-=1;
			break;
		}
		pos+=dhash(s);
		if(pos>=capacity) pos=pos-capacity;
	}
}
int MapH::size(){
	return mysize;
}
bool MapH::empty(){
	if(mysize==0) return true;
	else return false;
}
void MapH::rehash(){
	pair<string,int> *temparray=new pair<string,int>[mysize];
	int i=0;int j=0;
	while(i<mysize){//save
		if(myarray[j].first!=""){
			temparray[i]=myarray[j];
			i++;
		}
		j++;
	}

	capacity=capacity*2;//resize
	for(int i=0;i<21;i++){
		if(capacity+15<cap[i-1]){
			capacity=cap[i-1];
			break;
		}
	}
	//cout<<endl<<capacity<<endl;
	myarray = new pair<string,int>[capacity];

	int size=mysize;
	//insCont=0;
	mysize=0;
	for(int i=0;i<size;i++){//recover
		insert(temparray[i]);
	}
	delete[] temparray;
}
int MapH::iCont(){
	return insCont;
}
int MapH::aCont(){
	return atCont;
}

/*#include <bits/stdc++.h>
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
*/