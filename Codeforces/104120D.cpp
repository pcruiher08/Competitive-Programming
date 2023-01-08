#include <algorithm>
#include <math.h>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <map>
#include <list>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <cstring>
#include <climits>
#define ll long long
#define ull unsigned long long
#define FOR(m,s,n,u) for(int m=s; m<n; m+=u)
#define ROF(m,s,n,u) for(int m=n; m>=s; m-=u)
#define FORb(m,s,n,u,k) for(int m=s; m<n&&k; m+=u)
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define PI 3.1415926535897932384626433832795028841971
#define INF 0x3f3f3f3f
#define EPS 1e-9
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
#define pii pair<int,int>
using namespace std;


int main(){
sync;
int m; cin>>m;
vector<ll> v;
multimap<int, int> mapa;

FOR(num,0,m,1){
    int op; cin>>op;
        multimap<int,int>::iterator it,izquierda,derecha;

    int lec; cin>>lec;
    //cout<<"arreglito"<<endl;
    //FOR(i,0,v.size(),1)cout<<i<<" ";
    //cout<<endl;
    //FOR(i,0,v.size(),1)cout<<v[i]<<" ";
    //cout<<endl;
    //cout<<endl;
    switch (op){
    case 1:
        v.pb(lec);
        mapa.insert(pii(lec,num));
        break;
    case 2:
        

        cout<<"map before deletion"<<endl;
        for ( std::multimap< int, int>::const_iterator iter = mapa.begin();iter != mapa.end(); ++iter )
        cout << iter->first << '\t' << iter->second << '\n';
        cout << endl;




        //mapa.erase(v[lec - 1]);
        //v[lec - 1] = -1; 


               //cout<<"caso 4"<<endl; 
        izquierda = mapa.lower_bound(v[lec - 1]); 
        derecha = mapa.upper_bound(v[lec - 1]);
            //std::cout << (*izquierda).first << " => " << (*izquierda).second << '\n';
            //std::cout << (*derecha).first << " => " << (*derecha).second << '\n';
            //cout<<"lec - 1 = "<<lec - 1<<endl;
      

        if((*izquierda).second == (*derecha).second){
            if((*izquierda).second == lec - 1){
                //cout<<"encontre el que tengo que borrar"<<endl;
                mapa.erase(izquierda);
                break;
            }
        }else{
            for(it=izquierda; it!=derecha; ++it){
                //std::cout << (*it).first << " => " << (*it).second << '\n';
                if((*it).second == lec - 1){
                    //cout<<"encontre el que tengo que borrar"<<endl;
                    mapa.erase(it);
                    break;
                }
            }
        }


            //cout<<"v[lec-1] = "<<v[lec - 1]<<endl;
            v[lec - 1] = -1;
            //cout<<"v[lec-1] = "<<v[lec - 1]<<endl;




        cout<<"map after deletion"<<endl;
        for ( std::multimap< int, int>::const_iterator iter = mapa.begin();iter != mapa.end(); ++iter )
        cout << iter->first << '\t' << iter->second << '\n';
        cout << endl;
        break;

    case 3:
        int i; cin>>i;
        //v[i - 1] += lec;
        //debe coincidir el valor con la llave para poder hacer el update
        //cout<<"caso 3"<<endl; 
        izquierda = mapa.lower_bound(i); 
        derecha = mapa.upper_bound(i);
            //std::cout << (*izquierda).first << " => " << (*izquierda).second << '\n';
            //std::cout << (*derecha).first << " => " << (*derecha).second << '\n';
            //cout<<"lec - 1 = "<<lec - 1<<endl;
            //cout<<"v[lec-1] = "<<v[lec - 1]<<endl;
            v[lec - 1] += i;
            //cout<<"v[lec-1] = "<<v[lec - 1]<<endl;

        if((*izquierda).second == (*derecha).second){
            if((*izquierda).second == lec - 1){
                //cout<<"encontre el que tengo que actualizar"<<endl;
                int newvalue = (*izquierda).first + i;
                int previousindex = (*izquierda).second;
                mapa.erase(izquierda);
                mapa.insert({newvalue, previousindex});
                break;
            }
        }else{
            for(it=izquierda; it!=derecha; ++it){
                std::cout << (*it).first << " => " << (*it).second << '\n';
                if((*it).second == lec - 1){
                    //cout<<"encontre el que tengo que actualizar"<<endl;
                    int newvalue = (*it).first + i;
                    int previousindex = (*it).second;
                    mapa.erase(it);
                    mapa.insert({newvalue, previousindex});
                    break;
                }
            }
        }

        //v[lec - 1] += i;
        break;

    case 4:

        cout<<"map state"<<endl;
        for ( std::multimap< int, int>::const_iterator iter = mapa.begin();iter != mapa.end(); ++iter )
        cout << iter->first << '\t' << iter->second << '\n';
        cout << endl;
        cout<<"looking for smaller than: "<<v[lec - 1]<<endl;
        
        cout<<distance(mapa.begin(),mapa.lower_bound(v[lec - 1]))<<endl;
        break;


    }
}
return 0;
}