class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
       queue<pair<pair<int,int>,int>>q;
       int n=grid.size();
       int m=grid[0].size();
       int vis[n][m];
       int freshcount=0;
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(grid[i][j]==2){
                   vis[i][j]=2;
                   q.push({{i,j},0});
                   
               }
                else{
                    vis[i][j]=0;
                    
                }
                if (grid[i][j]==1)
                {
                    freshcount++;
                }
               }
           }
       
       int delrow[]={-1,0,+1,0};
       int delcol[]={0,+1,0,-1};
       int tm=0;
       int count=0;
       while(!q.empty()){
           int r=q.front().first.first;
           int c=q.front().first.second;
           int t=q.front().second;
           tm=max(tm,t);
           q.pop();
        for (int i=0;i<4;i++){
            int nrow=r+delrow[i];
            int ncol=c+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
            grid[nrow][ncol]==1 && vis[nrow][ncol]!=2){
                q.push({{nrow,ncol},t+1});
                vis[nrow][ncol]=2;
                count++;
                
            }
    
        }
           
       }
       if(freshcount!=count){
           return -1;
       }
       return tm;
       
    }
};