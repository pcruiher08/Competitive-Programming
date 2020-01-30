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

class SegmentTree {
public:
    int* max_tree;
    int* min_tree;
    int* arr;
    int size;
    bool intersting;
    pair<int, int> answer;
    SegmentTree(int* _arr, int _size) {
        size = _size;
        max_tree = new int[size * 4];
        min_tree = new int[size * 4];
        arr = _arr;
        intersting = 0;
        build(0, 0, size - 1);

    }

    /*
    ~SegmentTree() {
        delete[] max_tree;
        delete[] min_tree;
        delete[] arr;
    }
    */
    void build(int node, int start, int end) {
        if (start == end) {
    
            max_tree[node] = arr[start];
            min_tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(2 * node + 1, start, mid);
            build(2 * node + 2, mid + 1, end);
            max_tree[node] = max(max_tree[2 * node + 1], max_tree[2 * node + 2]);
            min_tree[node] = min(min_tree[2 * node + 1], min_tree[2 * node + 2]);
            if (max_tree[node] - min_tree[node] >= size) {
                intersting = 1;
                answer = make_pair(start + 1, end + 1);
            }
        }
    }
};

int main(){
sync;


int n; cin>>n; 

while(n--){
    int k; cin>>k; 

    int* arr = new int[k]; 
    int sum = 0;
    FOR(i,0,k,1){cin>>arr[i]; sum+=arr[i];}

    FOR(i,1,k,1)arr[i]+=arr[i-1];

    SegmentTree uno(arr,k-1);
    SegmentTree dos(arr+1,k-1);

    int maximoUno = uno.max_tree[0];
 
    
     int maximoDos = dos.max_tree[0];
    cout<<"suma = "<<sum<<" , "<<"max = "<<max(maximoDos,maximoUno)<<endl; 
     if(max(maximoUno,maximoDos)>k){
         cout<<"YES"<<endl;
     }else{
         cout<<"NO"<<endl;
     }


}

return 0;
}