int findWays(vector<int> &num, int k){
	int mod =(int) 1e9 + 7;

     int n = num.size();

    vector<vector<int>> dp(n,vector<int>(k+1,0));
    
    for(int i=0; i<n; i++){
        dp[i][0] = 1;
    }
        if(num[0]<=k)
        dp[0][num[0]] = 1;
    for(int ind = 1; ind<n; ind++){
        for(int target= 1; target<=k; target++){
            
            int notTaken = (dp[ind-1][target])%mod;
    
            int taken = 0;
                if(num[ind]<=target)
                    taken = (dp[ind-1][target-num[ind]])%mod;
        
            dp[ind][target]= (notTaken + taken)%mod;
        }
    }
    
    return dp[n-1][k]%mod;
    
}


if(index==0){
if(sum==0 && arr[0]==0){
    return 2;
}
if(sum==0 || arr[0]=sum){
    return 1;
}
return 0;

}