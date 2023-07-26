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
divisible set


//SPACE OPTIMIZATION
int longestSubsequence(int n, int a[])
    {
       vector<int>current(n+1,0);
       vector<int>next(n+1,0);
      for(int curr=n-1;curr>=0;curr--){
          for (int prev=curr-1;prev>=-1;prev--){
              
        int len=0+next[prev+1];
        if(prev==-1 || a[curr]>a[prev]){
            len=max(len,1+next[curr+1]);
        }
      current[prev+1]=len;
        
              
              
          }
          next=current;
      }
        
        
       return next[0];
    }
};


//recursion
class Solution
{
    public:
    int solve(int curr,int prev,int a[],int n,vector<vector<int>>&dp){
        if (curr==n) return 0;
        if(dp[curr][prev+1]!=-1) return dp[curr][prev+1];
        int pick=0;
        int notpick=0+solve(curr+1,prev,a,n,dp);
        if(prev==-1 || a[curr]>a[prev]){
            pick=1+solve(curr+1,curr,a,n,dp);
        }
        return dp[curr][prev+1]=max(pick,notpick);
        
        
    }

    //TABULATION
      int longestSubsequence(int n, int a[])
    {
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
      for(int curr=n-1;curr>=0;curr--){
          for (int prev=curr-1;prev>=-1;prev--){
              int pick=0;
        int notpick=0+dp[curr+1][prev+1];
        if(prev==-1 || a[curr]>a[prev]){
            pick=1+dp[curr+1][curr+1];
        }
      dp[curr][prev+1]=max(pick,notpick);
        
              
              
          }
      }
        
        
       return dp[0][0];
    }
};