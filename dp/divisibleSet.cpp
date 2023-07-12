#include <bits/stdc++.h>

using namespace std;

vector<int> divisibleSet(vector<int> &arr) {
    int n = arr.size();
    vector<int> dp(n, 1),hash(n);
int maxi=1;
    sort(arr.begin(), arr.end());
    int lastindex=0;
    for (int i = 0; i < n; i++) {
        hash[i]=i;
        for (int prev = 0; prev < i; prev++) {
            if (arr[i] % arr[prev] == 0 && dp[i] < dp[prev] + 1) {
                dp[i] = dp[prev] + 1;
                hash[i]=prev;
            }
        }
        if(dp[i]>maxi){
            maxi=dp[i];
            lastindex=i;
        }
        
    }
    
    vector<int> temp;
temp.push_back(arr[lastindex]);


  while(lastindex!=hash[lastindex]){
      lastindex=hash[lastindex];
      temp.push_back(arr[lastindex]);
  }
  reverse(temp.begin(),temp.end());
    return temp;
}

