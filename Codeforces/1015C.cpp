#include <iostream>
#include <algorithm>
using namespace std;

struct song{
    int len;
    int lenC;
};

int main() {
    int n;
    cin>>n;
    int size;
    cin>>size;
    song songs[n];
    int dif[n];
    long long sum = 0;
    for(int i=0; i<n; i++){
        cin>>songs[i].len;
        sum+=songs[i].len;
        cin>>songs[i].lenC;
        dif[i]=songs[i].lenC-songs[i].len;
    }

    
    if(sum<=size){
        cout<<0<<endl;
    }else{
        sort(dif, dif+n);
        int i=0;
        while(sum>size&& i<n) sum+=dif[i], ++i;
        cout<< (sum<=size? i : -1) <<endl;
    }
  
    
    
}