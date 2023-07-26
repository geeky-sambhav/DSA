int solve(int i1,int i2,string &s1,string &s2){
if(i1<0 || i2<0){
	return 0;
}
if(s1[i1]==s2[i2]){
	return 1+solve(i1-1,i2-1,s1,s2);
}
return (max(solve(i1-1,i2,s1,s2),solve(i1,i2-1,s1,s2)));


}

int lcs(string s, string t)
{
	int n1=s.size();
	int n2=t.size();
	return solve(n1-1,n2-1,s,t);
}

/* --------------------------- SHIFTING OF INDEXES -------------------------- */
int solve(int i1,int i2,string &s1,string &s2){
if(i1==0 || i2==0){
	return 0;
}
if(s1[i1-1]==s2[i2-1]){
	return 1+solve(i1-1,i2-1,s1,s2);
}
return (max(solve(i1-1,i2,s1,s2),solve(i1,i2-1,s1,s2)));
}

int lcs(string s, string t)
{
	int n1=s.size();
	int n2=t.size();
	return solve(n1,n2,s,t);
}

/* ------------------------------- TABULATION ------------------------------- */

#include<vector>

int lcs(string s, string t)
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
	return dp[n1][n2];
}


/* --------------------------- SPACE OPTIMIZATION --------------------------- */

#include<vector>

int lcs(string s, string t)
{
	int n1=s.size();
	int n2=t.size();
	vector<int>prev(n2+1);
	vector<int>curr(n2+1);
	for (int i=0;i<=n2;i++){
		prev[i]=0;
	}



	for (int i=1;i<=n1;i++){
		for (int j=1;j<=n2;j++){
			if(s[i-1]==t[j-1]){
	curr[j]=1+prev[j-1];
}
else{

	curr[j]=max(prev[j],curr[j-1]);
}
		}
		prev=curr;
	}
	return prev[n2];
}   



int lcs(int )