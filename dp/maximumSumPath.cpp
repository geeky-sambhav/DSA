/* ------------------------------- MEMOIZAION ------------------------------- */
#include <bits/stdc++.h> 
int solve(int i,int j,vector<vector<int>> &matrix,
vector<vector<int>>&dp){
if(j<0 || j>=matrix[0].size()){
    return -1e9;
}
if(i==0){
return matrix[0][j];
}
if(dp[i][j]!=-1) return dp[i][j];
int up=matrix[i][j]+solve(i-1,j,matrix,dp);
 
  int left = matrix[i][j] + solve(i - 1, j - 1, matrix, dp);

 
  int right = matrix[i][j] + solve(i - 1, j + 1, matrix, dp);

return dp[i][j]=max(up,max(left,right));


}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    int maxi=-1e9;
   for (int i=0;i<m;i++){
       maxi=max(maxi,solve(n-1,i,matrix,dp));
   }
   return maxi;
}

/* ------------------------------- TABULATION ------------------------------- */

#include <bits/stdc++.h> 

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();
  int dp[n][m];
  for (int i=0;i<m;i++){
      dp[0][i]=matrix[0][i];
  }
    for (int i=1;i<n;i++){
        for (int j=0;j<m;j++){
            int left=-1e9;
            int right=-1e9;
            int up=matrix[i][j]+dp[i-1][j];
            if (j > 0) {
               left = matrix[i][j] + dp[i - 1][j - 1];
            }
            if (j < m - 1) {
               right = matrix[i][j] + dp[i - 1][j + 1];
            }
    dp[i][j]=max(up,max(left,right));
        }
    }
int maxi=-1e9;
for (int i=0;i<m;i++){
    maxi=max(maxi,dp[n-1][i]);
}
return maxi;
}

/* --------------------------- SPACE OPTIMIZATION --------------------------- */
#include <bits/stdc++.h> 

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();
  int dp[n][m];
  for (int i=0;i<m;i++){
      dp[0][i]=matrix[0][i];
  }
    for (int i=1;i<n;i++){
        for (int j=0;j<m;j++){
            int left=-1e9;
            int right=-1e9;
            int up=matrix[i][j]+dp[i-1][j];
            if (j > 0) {
               left = matrix[i][j] + dp[i - 1][j - 1];
            }
            if (j < m - 1) {
               right = matrix[i][j] + dp[i - 1][j + 1];
            }
    dp[i][j]=max(up,max(left,right));
        }
    }
int maxi=-1e9;
for (int i=0;i<m;i++){
    maxi=max(maxi,dp[n-1][i]);
}
return maxi;
}