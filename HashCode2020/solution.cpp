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
#include <fstream>
#include <unordered_set>
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
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); //cout.tie(NULL)
#define vi vector<int>
#define pii pair<int,int>
using namespace std;


struct library{
    int id; 
    int suma;
    vector<int> books;
    int booksInLibrary;
    int signupDays;
    int booksShippedPerDay;
    int maxScore;
    bool hasBeenRegistered;
    bool isBeingRegistered;
    int daysToBeRegistered; 
    int howManyToPrint;
    float ordenador;
};

bool orderLibrary(library a, library b){
    return a.ordenador>b.ordenador;
}

vector<int> booksValues;

bool orderBooks(int a, int b){
    return booksValues[a]>booksValues[b];
}

int main(){
    sync;


    ofstream salida;
    ifstream entrada;

    entrada.open("f.txt", std::ios_base::in);
    salida.open("f_output.txt");

    unordered_set<int> s;

    int howManyBooks;
    int howManyLibraries; 
    int daysForScanning;

    entrada>>howManyBooks;
    entrada>>howManyLibraries;
    entrada>>daysForScanning;


    for(int i=0; i<howManyBooks; i++){
        int x;
        entrada>>x;
        booksValues.pb(x);
    }

    vector<library> libraries;

    for(int i=0; i<howManyLibraries; i++){
        library toBeRead; 
        int score = 0;
        toBeRead.id = i;
        int a,b,c;
        entrada>>a;
        toBeRead.booksInLibrary = a;
        entrada>>b; toBeRead.signupDays = b;
        entrada>>c; toBeRead.booksShippedPerDay = c;
        toBeRead.daysToBeRegistered = toBeRead.signupDays;
        toBeRead.howManyToPrint = -1;
        toBeRead.hasBeenRegistered = false; 
        toBeRead.isBeingRegistered = false;
        vector<int> librosAOrdenar;
        for(int j=0; j<a; j++){
            int x = 0;
            entrada>>x;
            librosAOrdenar.pb(x);
            toBeRead.books.pb(x);
            score+=booksValues[x];
        }
        sort(librosAOrdenar.begin(),librosAOrdenar.end(),orderBooks);
        toBeRead.books = librosAOrdenar;
        toBeRead.maxScore = score;
        toBeRead.ordenador = 1/score * 1/toBeRead.signupDays;
        libraries.pb(toBeRead);
    }

    sort(libraries.begin(),libraries.end(),orderLibrary);
  

    vector<library*> registradas;
    bool registering = true;
    
    queue<library*> q;

    library *libraryR = &libraries[0];
    library *nextPush = NULL;
  

    int enCualLibreriaVamos = 0;

    for(int i=0; i<daysForScanning; i++){
        if (nextPush != NULL) {
            registradas.pb(nextPush);
            q.push(nextPush);
            nextPush = NULL;
        } 
   
        if(libraryR!=NULL&&libraryR->daysToBeRegistered > 0){
            libraryR->daysToBeRegistered--;
            if(libraryR->daysToBeRegistered == 0){
                libraryR->hasBeenRegistered = true; 
                registering = false;
                nextPush = libraryR;
            }
        }

        if(!registering){
            enCualLibreriaVamos++;
            if (enCualLibreriaVamos < howManyLibraries) {
                libraryR = &libraries[enCualLibreriaVamos];
                registering = true;
                libraryR->isBeingRegistered = true;
            }
        }
        for(int j = 0; j<registradas.size(); j++){
            library * curr = registradas[j];
            curr->howManyToPrint += curr->booksShippedPerDay;
            if (curr->howManyToPrint >= curr->booksInLibrary) curr->howManyToPrint = curr->booksInLibrary - 1;
        }

    }



    salida<<q.size()<<endl;
    while(!q.empty()){
        library *sacar = q.front();
        salida<<sacar->id<<" ";
        vector<int> paraAfuera;
        for(int k = 0; k<=sacar->howManyToPrint; k++){
            while(s.find(sacar->books[k])!=s.end()&&k<sacar->booksInLibrary&&k<sacar->howManyToPrint){
                k++;
            }
            paraAfuera.pb(sacar->books[k]);
            s.insert(sacar->books[k]);
        }
        salida<<paraAfuera.size()<<endl;
        for(int o=0; o<paraAfuera.size(); o++){
            salida<<paraAfuera[o]<<" ";
        }
        salida<<endl;
        q.pop();

    }
    salida.close();
    entrada.close();
    return 0;
}