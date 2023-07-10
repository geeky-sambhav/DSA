#include<bits/stdc++.h>
using namespace std;
int longestIncreasingSubsequence(int arr[], int n)
{
      vector<int>dp;
      int ans=1;
      dp.push_back(arr[0]);
      for (int i=1;i<n;i++)
      {
          if (arr[i]>dp.back())
          {
              dp.push_back(arr[i]);
          }
          else{
              int ind=lower_bound(dp.begin(),dp.end(),arr[i])-dp.begin();
              dp[ind]=arr[i];
          }
      }
      return dp.size();
}

//PRINTING 
To printing there is a simpler approach and here is the code with explanation for it =>
        int mx = res;
        vector<int>lis;
        for(int i = n-1;i>=0;--i){
            if(dp[i] == mx){
                lis.emplace_back(v[i]);
                mx--;
            }
        }
        reverse(begin(lis),end(lis));
        for(auto &it : lis) cout<<it<<" ";
        cout<<"\n";