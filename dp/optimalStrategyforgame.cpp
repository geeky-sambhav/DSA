class Solution{
    public:
    
    long long solve(int arr[], int i,int j){
        if(i>j) return 0;
        if(i==j) return arr[i];
     long long left=arr[i]+min(solve(arr,i+2,j),solve(arr,i+1,j-1));
    long long right=arr[j]+min(solve(arr,i+1,j-1),solve(arr,i,j-2));
        return max(left,right);
        
        
    }
    
    long long maximumAmount(int arr[], int n){
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for (int j=i;j<n;j++){
                   if(i==j)dp[i][j]=arr[i];
              
              else{
                  long long left=arr[i]+min(dp[i+2][j],dp[i+1][j-1]);
                  long long right=arr[j]+min(dp[i+1][j-1],dp[i][j-2]);
                  
                  dp[i][j]=max(left,right);
                
            }
            
        }
        }
        
   
        
        
        return dp[0][n-1];
    }
};