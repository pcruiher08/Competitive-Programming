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


/*
int main() {
    sync;

    vector<int> nums = {};

    int n; 
    cin>>n;
    NumberCounterWithFenwickTree numCounter(nums);

    while(n--){
        string queryType = "";
        int c;
        cin>>queryType;
        cin>>c;

        if(queryType == "REGISTRA"){
            numCounter.insert(c);
        }else{
            int a, b; 
            cin>>a>>b;
            cout<<"\nRES::::"<<numCounter.query(c,a ,b  )<<endl;
            
        }
    }




    return 0;
}
*/



#include <iostream>
#include <vector>

using namespace std;

class FenwickTree {
public:
    FenwickTree(int n) : tree(n + 1, 0) {}

    void update(int index, int delta) {
        // Increment the value at index and update its ancestors
        for (; index < tree.size(); index += index & -index) {
            tree[index] += delta;
        }
    }

    int query(int index) {
        // Calculate the cumulative sum from 1 to index
        int sum = 0;
        for (; index > 0; index -= index & -index) {
            sum += tree[index];
        }
        return sum;
    }

private:
    vector<int> tree;
};

class NumberCounterWithFenwickTree {
public:
    NumberCounterWithFenwickTree(vector<int>& nums, int x) : fenwick(nums.size() + 1), nums(nums), x(x) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == x) {
                fenwick.update(i + 1, 1); // Increment Fenwick Tree at index i + 1
            }
        }
    }

    void insert(int x) {
        nums.push_back(x);
        if (x == this->x) {
            fenwick.update(nums.size(), 1); // Increment Fenwick Tree at the end
        }
    }

    int query(int left, int right) {
        return fenwick.query(right + 1) - fenwick.query(left); // Adjust indices by +1
    }

private:
    FenwickTree fenwick;
    vector<int> nums;
    int x;
};

int main() {
    vector<int> nums = {1, 2, 1, 3};
    int x = 1;

    NumberCounterWithFenwickTree numCounter(nums, x);

    // Insert new numbers
    numCounter.insert(1);
    numCounter.insert(2);

    // Count occurrences of 1 in range [0, 2]
    int result = numCounter.query(0, 2);
    cout << "Count of " << x << " in range [0, 2]: " << result << endl;  // Output: 3

    // Count occurrences of 2 in range [0, 4]
    result = numCounter.query(0, 4);
    cout << "Count of 2 in range [0, 4]: " << result << endl;  // Output: 2

    return 0;
}
