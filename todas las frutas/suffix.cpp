/*
Longest jump

[1, -3, 1, 2, -3, 1, 2]
^^

-3 - 1 = -4

suffixmax = [2, 2, 2, 2, 2, 2, 2]


[100 90 80 1 2 3 4 5 90]
^^
sm = [100 90 80 6 6 6 6 6 6]

*/


#include <vector>
#include <iostream>

using namespace std;


int maxabsolutevalue(vector<int> arr){
    int absminval = arr[0];
    int absmaxval = arr[0];
    for(auto val : arr){
        absminval = min(absminval, val);
        absmaxval = max(absmaxval, val);
    }
    return abs(absmaxval - absminval);
}

int maxjumptwopointers(vector<int> arr) {
    int maxdelta = 0;
    int right = 0, left = 0;
    while(right != arr.size() && left != arr.size()){
        maxdelta = max(maxdelta, arr[right] - arr[left]);
        if(arr[right] <= arr[left]){
            left = right;
        }
        right++;
    }
    return maxdelta;
}


int maxjump(vector<int> arr) {
  int maxdelta = 0;
  // calculate suffix max array
  int suffixmax[arr.size()];
  for(int i = 0; i < arr.size(); i++){
    suffixmax[i] = 0;
  }

  int maxsofar = arr[arr.size() - 1];
  for (int i = 0; i < arr.size(); i++) {
    maxsofar = max(maxsofar, arr[arr.size() - i - 1]);
    suffixmax[arr.size() - i - 1] = maxsofar;
  }

  // lineary check for the maximum delta
  for (int i = 0; i < arr.size(); i++) {
    maxdelta = max(maxdelta, max(arr[i] - arr[i], suffixmax[i] - arr[i]));
  }

  return maxdelta;
}

int main() {

    cout<<maxjumptwopointers({100, 90, 80, -1, 2, 3, 4, 5, 90})<<endl;
    cout<<maxabsolutevalue({100, 90, 80, -1, 2, 3, 4, 5, 90})<<endl;
        
  
}