#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; 
    cin>>n; 
    vector <int> nums;
    int per=0; 
    int e; 
    for(int i=0; i<n; i++){
      cin>>e; 
      nums.push_back(e);
    }
    sort(nums.begin(), nums.end());
    
      if(n%2==0){
        //par
        for(int i=0; i<(n/2)+1; i++){
          per += (nums[i]/2)+1;
        }
        
      }else{
        //imppar
        for(int i=0; i<(n/2)+1; i++){
          per += (nums[i]/2)+1;
        }
      }
      cout<<per;
      
    
}