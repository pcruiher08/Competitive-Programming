#include <bits/stdc++.h>

using namespace std;

int toEntero(char n){
	return n-48;
}

int main(){
	string s;
	cin>>s;
	vector<int> digits;
	for(int i=0; i<s.size(); i++){
		if(s[i] != '+'){
			digits.push_back(toEntero(s[i]));
		}
	}
	sort(digits.begin(),digits.end());
	for(int i=0; i<digits.size();i++){
		if(i==digits.size()-1)cout<<digits[i];
		else cout<<digits[i]<<"+";
	}
	cout<<endl;
	return 0;
}