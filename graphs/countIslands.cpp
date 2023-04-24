class Solution {
  public:
  void bfs(int row,int col,vector<vector<int> &vis,
  vector<vector<char>>& grid){
      vis[row][col]=1;
      queue<pair<int>>q;
      q.push({row,col});
        int n=grid.size();
        int m=grid[0].size();
      while(!q.empty()){
          int r=q.first;
          int c=q.second;
          q.pop();
          
          
          for(delr=-1;delr<=1;delr++){
              for(delc=-1;delc<=1;delc++){
       int nrow=delr+r;
       int ncol=del+c;
       if(ncol>=0 && ncol<m && nrow>=0 && nrow<n && 
       grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
           vis[nrow][ncol]=1;
           q.push({nrow,ncol});
           
       }
                  
              }
          }
                }
      
  }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
       vector<vector<int>>vis(n,vector<int>(m,0));
       int count=0;
       for(int row=0;row<n;row++){
           for (int col=0;col<n;col++){
               if(!vis[row][col] && grid[row][col]=='1'){
                   count++;
                   bfs(row,col,vis,grid);
               }
           }
       }
       return count;
    }
};