#include <bits/stdc++.h> 


int mod=(int)(1e9+7);
int subsequenceCounting(string &t, string &s, int lt, int ls) {
vector<vector<int>>dp(lt+1,vector<int>(ls+1,0));
for (int i=0;i<=lt;i++){
dp[i][0]=1;
}
for (int i=1;i<=ls;i++){
    dp[0][i]=0;   //yaha 1 s liye aaya coz hm pehle declare kr chuke hai k
}
for (int i=1;i<=lt;i++){
    for (int j=1;j<=ls;j++){
            if(t[i-1]==s[j-1]){
                 dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
}
else{
        dp[i][j]=(dp[i-1][j])%mod;
}

    }
}
return (dp[lt][ls])%mod;
} 

/* ------------------------------------ d ----------------------------------- */
#include <bits/stdc++.h> 


int mod=(int)(1e9+7);
int subsequenceCounting(string &t, string &s, int lt, int ls) {
vector<int>curr(ls+1);
vector<int>prev(ls+1);
curr[0]=prev[0]=1;
for (int i=1;i<=lt;i++){
    for (int j=1;j<=ls;j++){
            if(t[i-1]==s[j-1]){
                 curr[j]=(prev[j-1]+prev[j])%mod;
}
else{
        curr[j]=(prev[j])%mod;
}

    }
    prev=curr;
}
return (prev[ls])%mod;
} 
/* ----------------------------------- dd ----------------------------------- */

#include <bits/stdc++.h> 


int mod=(int)(1e9+7);
int subsequenceCounting(string &t, string &s, int lt, int ls) {

vector<int>prev(ls+1);
prev[0]=1;
for (int i=1;i<=lt;i++){
    for (int j=ls;j>=1;j--){
            if(t[i-1]==s[j-1]){
                 prev[j]=(prev[j-1]+prev[j])%mod;
}


    }
   
}
return (prev[ls])%mod;
} 


