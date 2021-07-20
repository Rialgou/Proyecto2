//mapa en base a arreglo ordenado
#ifndef	MAPSV_H
#define MAPSV_H
#include "ADTMap.h"
#include <vector>
using namespace std;
class MapSV : public ADTMap{

private:
	vector<pair<string,int>> v;
public:
	MapSV();
	~MapSV();
	void insert(pair<string,int> p);
	void erase(string s);
	int at(string s);
	int size();
	bool empty();
	void printList();
	bool abcMenor(string s1, string s2);
};
#endif