#include <bits/stdc++.h>
#include "MapSV.h"
using namespace std;
string random_string( size_t length )
{
    auto randchar = []() -> char
    {
        const char charset[] = "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[ rand() % max_index ];
    };
    string str(length,0);
    generate_n( str.begin(), length, randchar );
    return str;
}
int main()
{
    srand(time(NULL));
    /*string s;
    string i;
    cout<<"ingrese una palabra: ";
    cin>>s;
    cout<<"ingrese una segunda palabra: ";
    cin>>i;
    if(s > i) cout<<s<<" es mayor que "<<i<<endl;
    else if(i<s) cout<<i<<" es mayor que "<<s<<endl;
    else cout<<"son iguales"<<endl;*/
    MapSV * sv = new MapSV();
    /*for(int i=0;i<1000;i++){
        sv->insert(make_pair(random_string(5),rand()%100+1));

    }*/
    sv->erase("ola");
    sv->insert(make_pair("ola",22));
    sv->insert(make_pair("ola",25));
    sv->insert(make_pair("juan",1213));
    sv->printList();
    if(sv->empty()) cout<<"ta vacio"<<endl;
    else cout<<" no ta vacio "<<endl;
    if(sv->abcMenor("orro","orar"))cout<<"es menor"<<endl;
    else cout<<"no es menor"<<endl<<endl;
    cout << sv->at("ola")<<endl;
    cout << sv->at("juan")<<endl;
    cout << sv->at("caupolican")<<endl;
}