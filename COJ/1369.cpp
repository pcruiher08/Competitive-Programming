#include <iostream>
#include <vector>
#include <math.h>
using namespace std;



int main(){
    int p,q;
    
    while(cin>>p>>q){
        
        if(p==0||q==0)break;
        vector<int> no;
        int frac=p/q;
        int pO = p;
        int qO=q;
        //p=rem;
        int sim;
        //    frac= p/q;
        while(1){
            no.push_back(frac);
            //p-=frac*q;
            p=p%q;
            sim = p/q;
            if(q==1||p==0)break;
            frac=q/p;
            int aux = p;
            p=q;
            q= aux;
        }
        cout<<pO<<"/"<<qO<<"=[";
        for(int i=0; i<no.size(); i++){
            if(i==no.size()-1){
                if(no[i]==1)
                cout<<no[i];
                else
                    cout<<no[i]-1<<","<<1;
            }
            else
            cout<<no[i]<<",";
        }
        cout<<"]"<<endl;
    }
  
}

/*
 75 34
 65 60
 0 0
 */
