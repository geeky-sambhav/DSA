/* -------------------------------------------------------------------------- */
/*                                 MEMOIZATION                                */
/* -------------------------------------------------------------------------- */

//represent in terms of indexes
//perform all possible stuff
// find min
#include <bits/stdc++.h> 

int solve(int n,vector<int>&dp,vector<int> &heights){
if(n==0){
  return 0;
}
if(dp[n]!=-1) return dp[n];
int left=solve(n-1,dp,heights)+abs(heights[n]-heights[n-1]);
int right=INT_MAX;
if (n > 1) {
  right = solve(n - 2, dp, heights) + abs(heights[n] - heights[n - 2]);
}
return dp[n]=min(left,right);


}


/* -------------------- TABULATION WITH SPACE OPTIMIZATON ------------------- */

int frogJump(int n, vector<int> &heights)
{
  vector<int>dp(n+1,-1);
  return solve(n-1,dp,heights);
}


#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
  
   int prev=0;
   int prev2=0;
   for (int i=1;i<n;i++){
     int fs=prev+abs(heights[i]-heights[i-1]);
    int ss=INT_MAX;
    if (i > 1) {
      ss = prev2 + abs(heights[i] - heights[i - 2]);
    }
    int curr=min(fs,ss);
    prev2=prev;
    prev=curr;
   }
   return prev;
}