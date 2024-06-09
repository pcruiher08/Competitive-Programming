
#include <iostream>

#include <string>

#define ll long long
#define ull unsigned long long
#define FOR(m,s,n,u) for(ull m=s; m<n; m+=u)

#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

void cuenta(ull r) {
    ull count = 0;
    ull ymax = r;
    FOR(i,0,r+1,1){
        while(i * i + ymax * ymax >= (r + 1) * (r + 1)){
            ymax--;
        }
        ull prim = ymax;
        while(i * i + prim * prim >= r * r && prim > 0){
            prim--;
            count++;
        }
    }
    cout << count * 4 << endl;
}
   
int main(){
sync;



int n; cin>>n;
while(n--){
    ull r; cin>>r;
    //cout<<lattice(r, r + 1)<<endl;
    
    cuenta(r);
}

return 0;
}