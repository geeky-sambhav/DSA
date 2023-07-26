  long long noOfWays(int M, int N, int X) {
    vector<vector<long long >> dp(N + 1, vector<long long>(X + 1, 0));
    int faces = M;
    dp[0][0] = 1;

    for (int dice = 1; dice <= N; dice++) {
        for (int target = 1; target <= X; target++) { // Fix the loop bounds here
            long long ans = 0;
            for (int i = 1; i <= M; i++) {
                if (target-i>=0) {ans +=  dp[dice - 1][target - i];}
            }
            dp[dice][target] = ans;
        }
    }

    return dp[N][X];
}

//   long long solve(int faces,int dice,int target,vector<vector<int>>&dp){
//       if(target<0) return 0;
//       if(dice==0 && target!=0) return 0;
//       if(dice==0 && target==0) return 1;
//       if(target==0 && dice!=0) return 0;
//       long long ans=0;
//       for(int i=1;i<=faces;i++){
//           ans+=solve(faces,dice-1,target-i,dp);
//       }
//       return dp[dice][target]=ans;
      
      
      
//   }