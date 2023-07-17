class Solution {
public:
int solve(int i,vector<int>&arr,int k,int n){
if(i==n) return 0;
int len=0;
int maxi=-1e9;
int ansmaxi=-1e9;
int sum=0;
for (int index=i;index<min(n,i+k);index++){
len++;
maxi=max(maxi,arr[index]);
sum=(len*maxi)+solve(index+1,arr,k,n);
ansmaxi=max(ansmaxi,sum);
}
return ansmaxi;

}

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
         int n=arr.size();
         return solve(0,arr,k,n);

    }
};


// TABULATION

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
         int n=arr.size();
        vector<int>dp(n+1,0);
for (int i=n-1;i>=0;i--){
  int len=0;
int maxi=-1e9;
int ansmaxi=-1e9;
int sum=0;
for (int index=i;index<min(n,i+k);index++){
len++;
maxi=max(maxi,arr[index]);
sum=(len*maxi)+dp[index+1];
ansmaxi=max(ansmaxi,sum);
}
dp[i]=ansmaxi;
}

return dp[0];
    }
};