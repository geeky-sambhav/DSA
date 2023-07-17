#include <bits/stdc++.h> 
bool ispalindrome(int i,int j,string s){
while(i<j){
if(s[i]!=s[j]) return false;
i++;
j--;
}
return true;

}
int solve(int i,int n,string str){
if(i==n) return 0;

int mini=1e9;
for (int index=i;index<n;index++){

if(ispalindrome(i,index,str)){
int cost=1+solve(index+1,n,str);
mini=min(mini,cost);
}


}
return mini;

}
int palindromePartitioning(string str) {
    // vector<vector<int>dp(n,vector<int>dp(n,0));
    int n=str.size();
   return solve(0,n,str)-1;
}


TABULATIION


#include <bits/stdc++.h>
int dp[104];

bool isPalindrome(string s) {
  string t = s;
  reverse(t.begin(), t.end());
  return s == t;
}
int palindromePartitioning(string str) {
  int n = str.size();
  memset(dp, 0, sizeof(dp));

  for (int i = n - 1; i >= 0; i--) {
    int mini = INT_MAX;
    for (int k = i; k < n; k++)
      if (isPalindrome(str.substr(i, k - i + 1)))
        mini = min(mini, 1 + dp[k + 1]);

    dp[i] = mini;
  }

  return dp[0] - 1;
}