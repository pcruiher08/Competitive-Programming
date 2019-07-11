#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <cstring>

using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n;
    cin >> n;
    long long k, p, bebidas;
    while(n--){
        cin >> p >> k;
        if(k > 0){
            bebidas = 0;
            bebidas = p + 1;
            k -= ((p) * (p +1) )/ 2;
            //cout << "Las k que meq uqdan son: " << k << endl;
            if(k >= 0){
                if(k % p == 0)
                    cout << bebidas + k / p  << endl;
                else
                    cout <<  "Too drunk to count" << endl;
            }
            else
                cout << "Too drunk to count" << endl;

        }
        else
            cout << "Too drunk to count" << endl;
    }

	return 0;
}