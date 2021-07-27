#include <bits/stdc++.h>
#include "MapSV.h"
#include "MapAVL.h"
#include "MapH.h"
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


int main(){
    int n;
    cout<<"ingrese la cantidad de claves"<<endl;
    cin >>n;
    int rep =100;
    clock_t start,stop;
    srand(time(NULL));
    //at1=busqueda de elemento existente, at2 busqueda de elemento no existente
    double AVLins=0,AVLat1=0,AVLat2=0;
    double MapHins=0,MapHat1=0,MapHat2=0;
    double SVins=0,SVat1=0,SVat2=0;

    for(int i=0;i<rep;i++){
        cout<<"ciclo: "<<i<<endl;
        MapH *h = new MapH(n);//hash
        MapAVL *a = new MapAVL();//AVL tree
        MapSV *sv = new MapSV();//sorted vector
        string s[n];
        for(int j=0;j<n;j++){
            s[j]= random_string(1+rand()%10);
            while(s[j]=="hola") s[j]= random_string(1+rand()%10);
            pair<string,int> p=make_pair(s[j],rand()%3000);

            start = clock();
            h->insert(p);
            stop = clock();
            MapHins+=(double)(stop-start)/CLOCKS_PER_SEC;
            
            start = clock();
            a->insert(p);
            stop = clock();
            AVLins+=(double)(stop-start)/CLOCKS_PER_SEC;

            start = clock();
            sv->insert(p);
            stop = clock();
            SVins+=(double)(stop-start)/CLOCKS_PER_SEC;
        }
        for(int j=0;j<n;j++){
            start = clock();
            h->at(s[j]);
            stop = clock();
            MapHat1+=(double)(stop-start)/CLOCKS_PER_SEC;

            start = clock();
            h->at("hola");
            stop = clock();
            MapHat2+=(double)(stop-start)/CLOCKS_PER_SEC;
            
            start = clock();
            a->at(s[j]);
            stop = clock();
            AVLat1+=(double)(stop-start)/CLOCKS_PER_SEC;

            start = clock();
            a->at("hola");
            stop = clock();
            AVLat2+=(double)(stop-start)/CLOCKS_PER_SEC;
            
            start = clock();
            sv->at(s[j]);
            stop = clock();
            SVat1+=(double)(stop-start)/CLOCKS_PER_SEC;   

            start = clock();
            sv->at("hola");
            stop = clock();
            SVat2+=(double)(stop-start)/CLOCKS_PER_SEC;   
        }
    }
    cout<<endl;
    printf("MapH insert : %f\n\n",MapHins/(double)rep );
    printf("AVL insert : %f\n\n",AVLins/(double)rep );
    printf("SV insert : %f\n\n",SVins/(double)rep );

    printf("MapH at 1 : %f\n\n",MapHat1/(double)rep );    
    printf("AVL at 1 : %f\n\n",AVLat1/(double)rep );    
    printf("SV at 1 : %f\n\n",SVat1/(double)rep );    

    printf("MapH at 2 : %f\n\n",MapHat2/(double)rep );
    printf("AVL at 2 : %f\n\n",AVLat2/(double)rep );
    printf("SV at 2 : %f\n\n",SVat2/(double)rep );

}
/*
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
    /*MapSV * sv = new MapSV();
    /*for(int i=0;i<1000;i++){
        sv->insert(make_pair(random_string(5),rand()%100+1));

    }
   /* sv->erase("ola");
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
    MapAVL * avl = new MapAVL();
    avl->insert(make_pair("c",23));
    avl->insert(make_pair("a",213));
    avl->insert(make_pair("b",13));
    avl->insert(make_pair("d",1231));
    avl->insert(make_pair("q",1241));
    avl->insert(make_pair("r",1251));
    avl->insert(make_pair("l",12415));
    avl->insert(make_pair("m",10));
    avl->erase("l");
    avl->erase("p");
    avl->printAVL(avl->getRaiz(),5);
    string s;
    cout<<"ingrese el string a buscar: ";
    cin>>s;
    cout<<"el valor del string buscado es: "<< avl->at(s)<<endl;
    delete(avl);
}
*/