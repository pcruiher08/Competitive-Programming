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
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <string>
#include <vector>
#include <cstring>
#include <climits>
#include <tuple>
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

ull cuenta(vector<ull>& a) {
    ull count = 0;

    vector<tuple<ull, ull, ull>> triples;
    for (ull j = 0; j <= a.size() - 3; j++) {
        triples.emplace_back(a[j], a[j + 1], a[j + 2]);
    }

    ull m = triples.size();
    for (ull i = 0; i < m; i++) {
        for (ull j = i + 1; j < m; j++) {

            int b1 = std::get<0>(triples[i]);
            int b2 = std::get<1>(triples[i]);
            int b3 = std::get<2>(triples[i]);

            int c1 = std::get<0>(triples[j]);
            int c2 = std::get<1>(triples[j]);
            int c3 = std::get<2>(triples[j]);

            ull diff = (b1 != c1) + (b2 != c2) + (b3 != c3);
            count += (diff == 1);
        }
    }

    return count;
}




unsigned long long cuenta2(const vector<ull>& a) {
    unsigned long long count = 0;
    int n = a.size();

    for (int i = 0; i <= n - 3; ++i) {
        for (int j = i + 1; j <= n - 3; ++j) {
            int diff_count = 0;
            for (int k = 0; k < 3; ++k) {
                if (a[i + k] != a[j + k]) {
                    diff_count++;
                    if (diff_count > 1) break;
                }
            }
            if (diff_count == 1) count++;
        }
    }

    return count;
}

unsigned long long cuenta3(const vector<int>& a) {
    unsigned long long count = 0;
    int n = a.size();

    // Sort the array
    sort(a.begin(), a.end());

    // Iterate through each element of the array
    for (int i = 0; i < n; ++i) {
        int left = 0;
        int right = n - 1;

        // Use two pointers technique to find beautiful triplets
        while (left < right) {
            unsigned long long diff = (a[i] != a[left]) + (a[i] != a[right]) + (a[left] != a[right]);
            if (diff == 1) {
                ++count;
            }
            // Move pointers based on the comparison result
            if (a[left] < a[right]) {
                ++left;
            } else {
                --right;
            }
        }
    }

    return count;
}


int main() {
    sync;
    int n; cin>>n;
    while(n--){
        int lec; cin>>lec;
        vector<int> v;
        for(int i = 0; i < lec; i++){
            int read; cin>>read;
            v.push_back(read);
        }
        cout <<cuenta3(v) << endl;

    }
    return 0;
}

