int minSubsetSumDifference(vector<int>& arr, int n)
{
	int totalsum=0;
	int mini=1e9;
	for (int i=0;i<n;i++){
		totalsum+=arr[i];
	}
   vector<vector<bool>> dp(n,vector<bool>(totalsum+1,false));
    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }
    if (arr[0] <= totalsum) {
        dp[0][arr[0]] = true;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= totalsum; j++) {
            bool nottake = dp[i-1][j];
            bool take = false;
            if (j >= arr[i]) {
                take = dp[i-1][j-arr[i]];
            }
            dp[i][j] = take || nottake;
        }
    }
  


	
	for (int i=0;i<=totalsum/2;i++){
		if(dp[n-1][i]){
			int s1=i;
		int s2=totalsum-s1;
		mini=min(mini,abs(s1-s2));
		}

	}
	return mini;
}
