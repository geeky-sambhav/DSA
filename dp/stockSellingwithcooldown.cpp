#include <bits/stdc++.h> 
int stockProfit(vector<int> &prices){
  vector<int>ahead1(2,0),curr(2,0),ahead2(2,0);
    int n=prices.size();
   int profit=0;
 for (int i=n-1;i>=0;i--){
          
curr[1]=max(-prices[i]+ahead1[0],0+ahead1[1]);
curr[0] =max(prices[i]+ahead2[1],0+ahead1[0]);
ahead2=ahead1;
ahead1=curr;
}
return ahead1[1];
 }
