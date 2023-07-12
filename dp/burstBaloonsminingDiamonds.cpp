int solve(int i,int j,vector<int>&arr,vector<vector<int>>&dp) {
	if(i>j){
		return 0;
	}
	if(dp[i][j]!=-1) return dp[i][j];
int maxi=-1e9;
for (int index=i;index<=j;index++){
	int value=arr[i-1]*arr[index]*arr[j+1]+solve(i,index-1,arr,dp)+
	solve(index+1,j,arr,dp);
	if(value>maxi) maxi=value;
}
return dp[i][j]=maxi;
}

// TABULATION

int maxCoins(vector<int>& arr)
{int n=arr.size();
vector<vector<int>>dp(n+2,vector<int>(n+2,0));
	arr.emplace_back(1);
	arr.push_back(1);
for (int i=n;i>=1;i--){
	for (int j=1;j<=n;j++){
		if(i>j) continue;

int maxi=-1e9;
for (int index=i;index<=j;index++){
	int value=arr[i-1]*arr[index]*arr[j+1]+dp[i][index-1]+
	dp[index+1][j];
	if(value>maxi) maxi=value;
}
dp[i][j]=maxi;
	}
}
return dp[1][n];
}