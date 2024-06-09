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

class heap{

    public:
    vector<int> v;
    int heapSize = 0;
    bool maxmin = true;

    heap(bool maxmin = true){

        heapSize = 0;
        this->maxmin = maxmin;
    }

    heap(vector<int> vec){
        heapSize = vec.size();
        for(int i = 0; i < vec.size(); i++){
            v.push_back(vec[i]);
        }
    }

    void erease(int element){
        int i = 0;
        for(i = 0; i < heapSize; i++){
            if(v[i] == element){
                break;
            }
        }
        int aux = v[i];

        if(maxmin){
            v[i] = v[heapSize - 1];
            v[heapSize - 1] = aux;
            v.pop_back();
        }else{
            v[i] = v[0];
            v[0] = aux;
            v.erase(v.begin());      
        }

        heapSize--;

        fullHeapify();
    }

    void insert(int element){
        if(heapSize == 0){
            v.push_back(element);
            heapSize++;
        }else{
    
            v.push_back(element);
           
            heapSize++;
            fullHeapify();
        }
    };



    void heapify(int index){
        int largest = index;
        int left = index * 2 + 1;
        int right = index * 2 + 2;

        //change logic from largest to smallest for min heap

        if(maxmin){
            if(left < heapSize && v[left] > v[largest])
                largest = left;
            
            if(right < heapSize && v[right] > v[largest])
                largest = right;
        }else{
            if(left < heapSize && v[left] < v[largest])
                largest = left;
            
            if(right < heapSize && v[right] < v[largest])
                largest = right;
        }

        if(largest != index){
            int aux = v[largest];
            v[largest] = v[index];
            v[index] = aux;

            heapify(largest);
        }

    };

    void fullHeapify(){
        for(int i = heapSize/2 - 1; i >= 0; i--){
            heapify(i);
        }
    };

    void printHeap(){
        for(int i = 0; i < heapSize; i++){
            cout<< v[i]<<" ";
            //cout<<"value of i: "<<i<<endl;
            //if((__builtin_popcount(i) == 1 && i != 1) || i == 0){
            //    cout<<"bin: "<<i<<endl;
            //    cout<<endl;
            //}   
        }cout<<endl;
    }


};


int main(){
    sync;


    heap h(1);
    h.insert(20);
    h.insert(2);
    h.insert(5);
    h.insert(12);
    h.insert(3);
    h.insert(3);
    h.insert(3);
    h.insert(3);
    h.insert(3);
    h.insert(3);
    h.insert(3);
    h.insert(300);
    h.printHeap(); 
    h.erease(20);
    h.printHeap();




return 0;
}



