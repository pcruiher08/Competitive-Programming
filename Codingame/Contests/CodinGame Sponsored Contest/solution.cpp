#include <algorithm>
#include <math.h>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <map>
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
#define mod 1000000007
#define PI 3.1415926535897932384626433832795028841971
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
using namespace std;

int main(){
    sync;
    int firstInitInput;
    cin >> firstInitInput; cin.ignore();
    int secondInitInput;
    cin >> secondInitInput; cin.ignore();
    int thirdInitInput;
    cin >> thirdInitInput; cin.ignore();
    cerr<<firstInitInput<<" "<<secondInitInput<<" "<<thirdInitInput<<endl;

    // game loop
    while (1) {
        string firstInput;
        getline(cin, firstInput);
        string secondInput;
        getline(cin, secondInput);
        string thirdInput;
        getline(cin, thirdInput);
        string fourthInput;
        getline(cin, fourthInput);
        cerr<< firstInput<<" "<< secondInput<<" "<< thirdInput<<" "<<fourthInput<<endl;
        for (int i = 0; i < thirdInitInput; i++) {
            int fifthInput;
            int sixthInput;
            cin >> fifthInput >> sixthInput; cin.ignore();
            cerr << fifthInput <<" "<<sixthInput<<endl;
        }

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        cout << "A" << endl;
    }
}