#include <bits/stdc++.h> 
int maximumNonAdjacentSum(vector<int> &nums){
    int prev=nums[0];
    int prev2=0;
    for (int i=1;i<nums.size();i++){
        int take=nums[i];
        if(i>1) take+=prev2;
        int nottake=0+prev;
        int curr=max(take,nottake);
    prev2=prev;
    prev=curr;

    }
    return prev;
}



class Solution
{
    public:
    int solve(int arr[],int n,vector<int>&dp){
        if(n==0){
           return arr[0];
        }
        if(n<0) return 0;
        
        if(dp[n]!=-1) return dp[n];
        int notpick=0+solve(arr,n-1,dp);
        int pick=0;
        if(n>0){
            pick=arr[n]+solve(arr,n-2,dp);
        }
        return dp[n]=max(pick,notpick);
    }
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
     vector<int>dp(n,-1);
        
        
       return solve(arr,n-1,dp);
       
    }
};

//TABULATION
  int FindMaxSum(int arr[], int n)
    {
     vector<int>dp(n,0);
     dp[0]=arr[0];
     for (int i=1;i<n;i++){
         int notpick=0+dp[i-1];
        int pick=arr[i];
        if(i>1){
            pick+=dp[i-2];}
        dp[i]=max(pick,notpick);
     }
        
        
       return dp[n-1];
       
    }
};


 int FindMaxSum(int arr[], int n)
    {
     int prev,prev2,curr;
     prev2=0;
     prev=arr[0];
     for (int i=1;i<n;i++){
         int notpick=0+prev;
        int pick=arr[i];
        if(i>1){
            pick+=prev2;}
        curr=max(pick,notpick);
        prev2=prev;
        prev=curr;
        
     }
        
        
       return prev;
       
    }
};