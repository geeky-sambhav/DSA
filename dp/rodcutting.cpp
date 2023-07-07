int solve(int index,vector<int> &price,int totalrod){
if(index==0){
	return totalrod*price[0];
}
int pick=INT_MIN;
if(index+1<=totalrod){
pick=price[index]+solve(index,price,totalrod-index-1);
}
int notpick=0+solve(index-1,price,totalrod);
return max(pick,notpick);
}


int cutRod(vector<int> &price, int n)
{	vector<vector<int>>dp(n,vector<int>(n+1,0));
	for (int i=0;i<=n;i++){
dp[0][i]=i*price[0];
	}
for (int i=1;i<n;i++){
	for (int j=0;j<=n;j++){
int pick=INT_MIN;
			if(i+1<=j){
pick=price[i]+dp[i][j-i-1];
}
int notpick=0+dp[i-1][j];
dp[i][j]=max(pick,notpick);

	}
}

	return dp[n-1][n];
}

