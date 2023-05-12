class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
    int n=grid.size();
    int m=grid[0].size();
      if(source.first==destination.first && 
      source.second==destination.second){
          return 0;
      }
      vector<vector<int>>dis(n,vector<int>(m,1e9));
      dis[source.first][source.second]=0;
      queue<pair<int,pair<int,int>>>q;
      q.push({0,{source.first,source.second}});
      int delrows[]={-1,0,1,0};
      int delcols[]={0,1,0,-1};
      while(!q.empty()){
          auto it=q.front();
          int distance=it.first;
          int row=it.second.first;
          int col=it.second.second;
          q.pop();
          for (int i=0;i<4;i++){
              int nrow=row+delrows[i];
              int ncol=col+delcols[i];
              if(nrow<n && ncol<m && nrow>=0 && ncol>=0 && 
              grid[nrow][ncol]==1 && distance+1<dis[nrow][ncol]){
                  dis[nrow][ncol]=distance+1;
                  if(nrow==destination.first && ncol==destination.second){
                      return distance+1;
                  }
                  q.push({distance+1,{nrow,ncol}});
                  }
              }
                }
                
       
            return -1;
        
    }
};