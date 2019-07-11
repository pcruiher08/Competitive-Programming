#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0) ;
    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        string entradas;
        vector<string> whatHasBeenSaid;
        set<string> others;
        getline(cin,entradas);
        for(int i=0,j=0;i<entradas.size();i++){
            if(entradas[i]==' '||i==entradas.size()-1){
                string cuenta = entradas.substr(j,i-j) ;
                j = i+1 ;
                whatHasBeenSaid.push_back(cuenta) ;
            }
        }
        whatHasBeenSaid[whatHasBeenSaid.size()-1].push_back(entradas[entradas.size()-1]) ;
        while(1){
            string choice ;
            getline(cin,choice) ;
            if(choice=="what does the fox say?")
                break ;
            for(int i=choice.size()-1;i>=0;i--){
                if(choice[i]==' '){
                    string cuenta = choice.substr(i+1,choice.size()-i+1) ;
                    others.insert(cuenta) ;
                    break ;
                }
            }
        }
        bool scream = 1 ;
        for(int i=0;i<whatHasBeenSaid.size();i++){
            if(others.count(whatHasBeenSaid[i])==0&&scream){
                cout << whatHasBeenSaid[i] ;
                scream = 0 ;
            }
            else if(others.count(whatHasBeenSaid[i])==0)
                cout << " " << whatHasBeenSaid[i] ;
        }
            cout << endl ;
    }
    return 0;
}