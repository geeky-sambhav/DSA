#include <bits/stdc++.h> 
int maximumProfit(int n, int fee, vector<int> &prices) {
        vector<int>ahead(2,0),curr(2,0);
      ahead[0]=ahead[1]=0;
   int profit=0;
 for (int i=n-1;i>=0;i--){
     for (int j=0;j<=1;j++){
       if(j==1){
profit=max(-prices[i]+ahead[0],0+ahead[1]);
}
else{
    profit=max(prices[i]+ahead[1]-fee,
    0+ahead[0]);
}
curr[j]=profit;
}
ahead=curr;
 }
return ahead[1];
}
