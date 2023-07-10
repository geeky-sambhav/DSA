long solve(int index,long *values,int n,int buy){
if(index==n){
    return 0;
}
long profit=0;
if(buy){
profit=max((-values[index]+solve(index+1,values,n,0)),
0+solve(index+1,values,n,1));
}
else{
    profit=max((values[index]+solve(index+1,values,n,1)),
    0+solve(index+1,values,n,0));
}
return profit;


}

long getMaximumProfit(long *values, int n)
{
    return solve(0,values,n,1);
}

/* ------------------------------- TABULATION ------------------------------- */

long getMaximumProfit(long *values, int n)
{
    vector<vector<long>>dp(n+1,vector<long>(2,0));
      dp[n][0]=dp[n][1]=0;
   long profit=0;
 for (int i=n-1;i>=0;i--){
     for (int j=0;j<=1;j++){
       if(j==1){
profit=max(-values[i]+dp[i+1][0],0+dp[i+1][1]);
}
else{
    profit=max(values[i]+dp[i+1][1],
    0+dp[i+1][0]);
}
dp[i][j]=profit;
}
 }
return dp[0][1];
}


/* --------------------------- SPACE OPTIMIZATION --------------------------- */

long getMaximumProfit(long *values, int n)
{
    vector<long>ahead(2,0),curr(2,0);
      ahead[0]=ahead[1]=0;
   long profit=0;
 for (int i=n-1;i>=0;i--){
     for (int j=0;j<=1;j++){
       if(j==1){
profit=max(-values[i]+ahead[0],0+ahead[1]);
}
else{
    profit=max(values[i]+ahead[1],
    0+ahead[0]);
}
curr[j]=profit;
}
ahead=curr;
 }
return ahead[1];
}

/* ----------------------------- using variables ---------------------------- */

long getMaximumProfit(long *values, int n)
{
    
long aheadbuy=0;
long aheadnotbuy=0;
long currbuy=0;
long currnotbuy=0;


   
   long profit=0;
   for (int i = n - 1; i >= 0; i--) {

     currbuy = max(-values[i] + aheadnotbuy, 0 + aheadbuy);
     currnotbuy = max(values[i] + aheadbuy, 0 + aheadnotbuy);
     aheadnotbuy = currnotbuy;
     aheadbuy = currbuy;
   }


   return aheadbuy;
}
