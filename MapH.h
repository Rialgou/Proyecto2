#ifndef	MAPH_H
#define MAPH_H
#include <bits/stdc++.h>
#include "ADTMap.h"
using namespace std;
class MapH: public ADTMap {
	private:
		int mysize,capacity;
		vector<int> cap;
		int insCont,atCont;
		int cont;
		pair <string,int> *myarray;
		void rehash();
	public:
		MapH(int max);
		~MapH();
		void insert(pair<string,int> p);
		int at(string s);
		void erase(string s);
		int size();
		bool empty();
		int hash(string s);
		int dhash(string s);
		int iCont();
		int aCont();
};

#endif
/*#ifndef	MAPH_H
#define MAPH_H
#include "ADTMap.h"
#include <vector>
using namespace std;
class MapH : public ADTMap{

private:
	vector<pair<string,int>> v;
	int fill;
	int hashf(string s,int n);
	int dHashf(string s,int n);
	void rehash();
	int colisionesAt;
	int colisionesInsert;
public:
	MapH(int N);
	~MapH();
	void insert(pair<string,int> p);
	void erase(string s);
	int at(string s);
	int size();
	bool empty();
	void printList();
	int getColisionesAt();
	int getColisionesInsert();
};
#endif
*/