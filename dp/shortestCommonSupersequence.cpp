#include <bits/stdc++.h> 
string shortestSupersequence(string s, string t)
{
	 int n1=s.size();
	int n2=t.size();
	vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
	for (int i=0;i<=n2;i++){
		dp[0][i]=0;
	}
for (int i=0;i<=n1;i++){
		dp[i][0]=0;
	}


	for (int i=1;i<=n1;i++){
		for (int j=1;j<=n2;j++){
			if(s[i-1]==t[j-1]){
	dp[i][j]=1+dp[i-1][j-1];
}
else{

	dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
}
		}
	}
string ans="";
while(n1>0 && n2>0){
if(s[n1-1]==t[n2-1]){
ans+=s[n1-1];
n1--;
n2--;
}
else{
 if(dp[n1-1][n2]>dp[n1][n2-1]){
	 ans+=s[n1-1];
	 n1--;

 }
 else{
	 ans+=t[n2-1];
	 n2--;
 }
}
}
while(n1>0){
	ans+=s[n1-1];
	n1--;
}
while(n2>0){
	ans+=t[n2-1];
	n2--;
}
reverse(ans.begin(),ans.end());
return ans;

}