int solve(int index,vector<int>& prices,int n,int buy,int left){
if(index==n){
    return 0;
}
if(left==0) return 0;
int profit=0;
if(buy){
profit=max((-prices[index]+solve(index+1,prices,n,0,left)),
0+solve(index+1,prices,n,1,left));
}
else{
    profit=max((prices[index]+solve(index+1,prices,n,1,left-1)),
    0+solve(index+1,prices,n,0,left));
}
return profit;


}

/* ------------------------------- TABULATION ------------------------------- */

int maxProfit(vector<int>& prices, int n)
{
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>
    (2,vector<int>(3,0)));
int profit=0;
for (int i=n-1;i>=0;i--){
    for(int j=0;j<=1;j++){
        for (int k=1;k<=2;k++){
            if(j==1){
dp[i][j][k]=max(-prices[i]+dp[i+1][0][k],
0+dp[i+1][1][k]);
}
else{
    dp[i][j][k]=max(prices[i]+dp[i+1][1][k-1],
    0+dp[i+1][0][k]);
}


        }
    }
}
return dp[0][1][2];


}

/* -------------------------- SPACE OPTIMIZATION ------------------------- */

int maxProfit(vector<int>& prices, int n)
{
    vector<vector<int>>after(2,vector<int>(3,0));
    vector<vector<int>>curr(2,vector<int>(3,0));
int profit=0;
for (int i=n-1;i>=0;i--){
    for(int j=0;j<=1;j++){
        for (int k=1;k<=2;k++){
            if(j==1){
curr[j][k]=max(-prices[i]+after[0][k],
0+after[1][k]);
}
else{
    curr[j][k]=max(prices[i]+after[1][k-1],
    0+after[0][k]);
}


        }
    }
    after=curr;
}
return after[1][2];


}