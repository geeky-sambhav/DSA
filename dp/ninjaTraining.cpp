/* ------------------------------- MEMOIZATION ------------------------------ */

int solve(int day,vector<vector<int>> &points,int ind,
vector<vector<int>>&dp){
if (day==0){
    int maxi=0;
    for (int i=0;i<3;i++){
        if(i!=ind){
            maxi=max(points[day][i],maxi);
        }

    }
    return maxi;
}
if(dp[day][ind]!=-1){
    return dp[day][ind];
}
int maxi=0;
for(int i=0;i<3;i++){
if(i!=ind){
 
 int point= points[day][i] + solve(day - 1, points, i,dp);
maxi=max(maxi,point);

}


}


return dp[day][ind]=maxi;


}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>>dp(n,vector<int>(4,-1));
   return solve(n-1,points,3,dp);
}


/* ------------------------------- TABULATION ------------------------------- */

int ninjaTraining(int n, vector<vector<int>> &points)
{
   vector<vector<int>>dp(n,vector<int>(4,-1));
   dp[0][0]=max(points[0][1],points[0][2]);
    dp[0][1]=max(points[0][0],points[0][2]);
     dp[0][2]=max(points[0][1],points[0][0]);
      dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for(int day=1;day<n;day++){
        for (int last=0;last<4;last++){
            dp[day][last]=0;
         
            for (int task=0;task<3;task++){
                if(task!=last){
                    int point=points[day][task]+dp[day-1][task];
                  dp[day][last]=max(dp[day][last],point);
                }
            }


        }

    }
    return dp[n-1][3];
}

/* ------------------------- WITH SPACE OPTIMIZATION ------------------------ */

int ninjaTraining(int n, vector<vector<int>> &points)
{
   vector<int>dp(4,0);
   dp[0]=max(points[0][1],points[0][2]);
    dp[1]=max(points[0][0],points[0][2]);
     dp[2]=max(points[0][1],points[0][0]);
      dp[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for(int day=1;day<n;day++){
            vector<int>temp(4,0);
        for (int last=0;last<4;last++){
            
         
            for (int task=0;task<3;task++){
                if(task!=last){
      temp[last]=max(temp[last],points[day][task]+dp[task]);
                }
            }

        }
            dp=temp;

    }
    return dp[3];
}