#include <bits/stdc++.h> 
bool solve(int index,int target,vector<int>arr){
    if(target==0) return true;
    if(index==0) return(arr[0]==target);
    bool nottake=solve(index-1,target,arr);
    bool take=false;
    if(target>=arr[index]){
         take=solve(index-1,target-arr[index],arr);
        }
    return take || nottake;

}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    return solve(n-1,k,arr);
}


/* ------------------------------- TABULATION ------------------------------- */

bool subsetSumToK(int n, int k, vector<int> &arr) {
   vector<vector<bool>> dp(n,vector<bool>(k+1,false));
    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }
    if (arr[0] <= k) {
        dp[0][arr[0]] = true;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            bool nottake = dp[i-1][j];
            bool take = false;
            if (j >= arr[i]) {
                take = dp[i-1][j-arr[i]];
            }
            dp[i][j] = take || nottake;
        }
    }
    return dp[n-1][k];
}


/* --------------------------- SPACE OPTIMIZATION --------------------------- */

// WHENEVER SUBSEQUENCE VALA QUES AA JAYE TO SPACE OPTIMIZATION KE LIYE PREV[0] AND CURR[0]= TRUE KRDO


bool subsetSumToK(int n, int k, vector<int> &arr) {
   vector<bool> prev(k+1,0);
   vector<bool> curr(k+1,0);
   prev[0]=curr[0]=true;
    if (arr[0] <= k) {
      prev[arr[0]] = true;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            bool nottake = prev[j];
            bool take = false;
            if (j >= arr[i]) {
                take = prev[j-arr[i]];
            }
            curr[j] = take || nottake;
        }
        prev=curr;
    }
    return prev[k];
}
