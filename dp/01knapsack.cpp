#include <bits/stdc++.h> 


int solve(int index,int maxWeight,vector<int>weight,vector<vector<int>>&dp,
vector<int>value){
if(index==0){
if(weight[0]<=maxWeight){
	return value[0];
}
else{
	return 0;
}
}
if(dp[index][maxWeight]!=-1) return dp[index][maxWeight];
int pick=INT_MIN;
if(weight[index]<=maxWeight){
	pick=value[index]+solve(index-1,maxWeight-weight[index],weight,dp,value);
}
int notpick=0+solve(index-1,maxWeight,weight,dp,value);
return dp[index][maxWeight]=max(pick,notpick);

}


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n,vector<int>(maxWeight+1,0));
	
	return solve(n-1,maxWeight,weight,dp,value);


}


/* ------------------------------- TABULATION ------------------------------- */

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n,vector<int>(maxWeight+1,0));
	for(int i=weight[0];i<=maxWeight;i++) dp[0][i]=value[0];
	for (int i=1;i<n;i++){
		for (int wt=0;wt<=maxWeight;wt++){
			int pick=INT_MIN;
			if(weight[i]<=wt){
	pick=value[i]+dp[i-1][wt-weight[i]];
}
int notpick=0+dp[i-1][wt];
 dp[i][wt]=max(pick,notpick);
		}
	}
return dp[n-1][maxWeight];

}


/* --------------------------- SPACE OPTIMIZATION --------------------------- */


int knapsack(vector<int> &weight, vector<int> &value, int n, int maxWeight) 
{
	vector<int>prev(maxWeight+1,0);
	for(int i=weight[0];i<=maxWeight;i++) prev[i]=value[0];
	for (int i=1;i<n;i++){
		for (int wt=maxWeight;wt>=0;wt--){
			int pick=INT_MIN;
			if(weight[i]<=wt){
	pick=value[i]+prev[wt-weight[i]];
}
int notpick=0+prev[wt];
 prev[wt]=max(pick,notpick);
		}
	}
return prev[maxWeight];

}