#include <bits/stdc++.h>
#define mod 1000000007

int solve(int n,vector<int>&dp) {
if(n==0){
    return 1;
}
// if(n==1) return 1;
 
if(dp[n]!=-1) return dp[n]%mod;
int onestep=solve(n-1,dp)%mod;
int twostep=0;
if(n>=2){
 twostep=solve(n-2,dp)%mod;}
return dp[n]=(onestep+twostep)%mod;
}
int countDistinctWays(int nStairs) {
   vector<int>dp(nStairs+1,-1);
return solve(nStairs,dp);

}

//TABULATION
int countDistinctWays(int nStairs) {
   vector<int>dp(nStairs+1,0);
int n=nStairs;
dp[0]=1;
for (int i=1;i<=n;i++){
int onestep=dp[i-1]%mod;
int twostep=0;
if(n>=2){
 twostep=dp[i-2]%mod;}

 dp[i]=(onestep+twostep)%mod;
}
return dp[n];
   }

   //SPACE OPTIMIZATION
   int countDistinctWays(int nStairs) {
   vector<int>dp(nStairs+1,0);
int prev,prev2,curr=0;
int n=nStairs;
prev=1;
prev2=1;
for (int i=2;i<=n;i++){
int onestep=prev%mod;
int twostep=0;
if(n>=2){
 twostep=prev2%mod;}

 curr=(onestep+twostep)%mod;
 prev2=prev;
 prev=curr;
}
return prev;
   


}