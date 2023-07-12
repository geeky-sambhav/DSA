#include <bits/stdc++.h> 
#define ll long long 

int mod= 1000000007;
int solve(int i,int j,int istrue,string & exp,vector<vector<vector<ll>>>&dp){
if(i>j){
    return 0;
}
if(i==j){
if(istrue) return exp[i]=='T';
else{
    return exp[i]=='F';
}
}
if(dp[i][j][istrue]!=-1) return dp[i][j][istrue];
ll ways=0;
for (int index=i+1;index<=j-1;index+=2){
ll lt=solve(i,index-1,1,exp,dp);
ll lf=solve(i,index-1,0,exp,dp);
ll rt=solve(index+1,j,1,exp,dp);
ll rf=solve(index+1,j,0,exp,dp);


if(exp[index]=='&'){
if(istrue){
ways+=(lt*rt)%mod;
}
else{
    ways+=((lt*rf)+(lf*rt)+(lf*rf))%mod;
}
}
else if(exp[index]=='|'){
if(istrue){
    ways+=((lt*rt)+(lt*rf)+(lf*rt))%mod;
}
else{
    ways+=(lf*rf)%mod;
}
}
else {
if(istrue){
    ways+=((lt*rf)+(lf*rt))%mod;
}
else{
    ways+=((lt*rt)+(rf*lf))%mod;
}
}
}
 ways %= mod;
return dp[i][j][istrue]=ways;






}
int evaluateExp(string & exp) {
    int n=exp.size();
    vector<vector<vector<ll>>>dp(n,vector<vector<ll>>(n,vector<ll>(2,-1)));
    return solve(0,n-1,1,exp,dp);
}