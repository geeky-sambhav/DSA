#include <bits/stdc++.h> 
int solve(int i,int j,vector<int> arr){
if(i==j) return 0;
int mini=1e9;
for (int k=i;k<j;k++){
    int steps=arr[i-1]*arr[k]*arr[j]+solve(i,k,arr)+solve(k+1,j,arr);
if(steps<mini) mini=steps;
}
return mini;
}
int matrixMultiplication(vector<int> &arr, int N)
{
   return solve(1,N-1,arr);
}

//TABULATION
#include <bits/stdc++.h> 

int matrixMultiplication(vector<int> &arr, int N)
{
   int dp[N][N];
   for (int i=1;i<N;i++){
       dp[i][i]=0;
   }

   for (int i=N-1;i>=1;i--){
        for (int j=i+1;j<N;j++){
            int mini=1e9;
            for (int k=i;k<j;k++){
            int steps=arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j];
            if(steps<mini) mini=steps;
}
dp[i][j]=mini;

        }


   }
   return dp[1][N-1];
}