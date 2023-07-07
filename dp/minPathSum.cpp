/* ------------------------------- MEMOIZATION ------------------------------ */


int solve(int row,int col,vector<vector<int>>& triangle, int n,
vector<vector<int>>dp){
if(row==n-1){
	return triangle[n-1][col];
}
if(dp[row][col]!=-1) return(dp[row][col]);
int down=solve(row+1,col,triangle,n,dp)+triangle[row][col];
int dg=solve(row+1,col+1,triangle,n,dp)+triangle[row][col];
return dp[row][col]=min(down,dg);
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
vector<vector<int>>dp(n,vector<int>(n,-1));
return solve(0,0,triangle,n,dp);
}


/* -------------------------------------------------------------------------- */
/*                                TABULATION IS  ALWAYS REVERSE OF RECURSION IF RECURION IS FROM 0 TO N-1 TABULATION IS FROM N-1 TO 0                             */
/* -------------------------------------------------------------------------- */


/* ------------------------------- TABULATION ------------------------------- */

int minimumPathSum(vector<vector<int>>& triangle, int n){
int dp[n][n];
for (int i = 0; i < n; i++) {
  dp[n - 1][i] = triangle[n - 1][i];
}
for(int i=n-2;i>=0;i--){
	for (int j=i;j>=0;j--){
		int down=triangle[i][j]+dp[i+1][j];
		int dg=triangle[i][j]+dp[i+1][j+1];
		dp[i][j]=min(down,dg);

	}
}
return dp[0][0];







/* --------------------------- SPACE OPTIMIZATION --------------------------- */

int minimumPathSum(vector<vector<int>>& triangle, int n){
vector<int>front(n,0); //previous row
vector<int>curr(n,0);
for (int i = 0; i < n; i++) {
  front[i] = triangle[n - 1][i];
}
for(int i=n-2;i>=0;i--){
	for (int j=i;j>=0;j--){
		int down=triangle[i][j]+front[j];
		int dg=triangle[i][j]+front[j+1];
		curr[j]=min(down,dg);

	}
	front=curr;
}
return front[0];
}