class Solution {
    private:
    void dfs(int row,int col,vector<vector<int>>&vis,
    vector<vector<int>>&grid,int brow,int bcol,
    vector<pair<int,int>>&temp){
        vis[row][col]=1;
        temp.push_back({row-brow,col-bcol});
        int delrows[]={-1,0,1,0};
        int delcols[]={0,1,0,-1};
        int n=grid.size();
        int m=grid[0].size();
        for (int i=0;i<4;i++){
            int nrow=row+delrows[i];
            int ncol=col+delcols[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
            !vis[nrow][ncol] && grid[nrow][ncol]==1){
                dfs(nrow,ncol,vis,grid,brow,bcol,temp);
            }
        }
        
        
        
        
    }
    
    
//   public:
//     int countDistinctIslands(vector<vector<int>>& grid) {
//         set<vector<pair<int,int>>>st;
//         int n=grid.size();
//         int m=grid[0].size();
//         vector<vector<int>>vis(n,vector<int>(m,0));
//         for(int i=0;i<n;i++){
//             for (int j=0;j<m;j++){
//                 if(!vis[i][j] && grid[i][j]==1){
//                     vector<pair<int,int>>temp;
//                     dfs(i,j,vis,grid,i,j,temp);
//                     st.insert(temp);
//                 }
//             }
//         }
//         return st.size();
//     }

//using bfs

 public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        set<vector<pair<int,int>>>st;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        int delrows[]={-1,0,1,0};
        int delcols[]={0,1,0,-1};
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (!vis[i][j] && grid[i][j]==1){
                    q.push({i,j});
                    vector<pair<int,int>>temp;
                    vis[i][j]=1;
                    while(!q.empty()){
                        int row=q.front().first;
                        int col=q.front().second;
                        q.pop();
                        temp.push_back({row-i,col-j});
                        for (int i=0;i<4;i++){
                         int nrow=row+delrows[i];
                         int ncol=col+delcols[i];
  if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
            !vis[nrow][ncol] && grid[nrow][ncol]==1){
                            vis[nrow][ncol]=1;
                            q.push({nrow,ncol});
                            
                           
                            }
                        
                    }
                    
                }
                    st.insert(temp);
                
                
            }
        }
      
      
      
      
      
      
      
    }
        return st.size();}
};
