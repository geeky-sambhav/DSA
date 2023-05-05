class Solution{
private:
void dfs(int row,int col,  vector<vector<int>>&vis,
vector<vector<char>> &mat){
    vis[row][col]=1;
    int n=mat.size();
    int m=mat[0].size();
    int delrows[]={-1,0,1,0};
    int delcols[]={0,-1,0,1};
    for (int i=0;i<4;i++){
        int nrow=row+delrows[i];
        int ncol=col+delcols[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
        !vis[nrow][ncol] && mat[nrow][ncol]=='O'){
            dfs(nrow,ncol,vis,mat);
        }
            }
    }

public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        //first and last row 
       for (int i=0;i<m;i++){
           if(mat[0][i]=='O' && !vis[0][i]){
               dfs(0,i,vis,mat);
           }
           
           if(mat[n-1][i]=='O' && !vis[n-1][i]){
               dfs(n-1,i,vis,mat);
           }
       }
       
       for(int j=0;j<n;j++){
           if(mat[j][0]=='O' && !vis[j][0]){
               dfs(j,0,vis,mat);
           }
           if(mat[j][m-1]=='O' && !vis[j][m-1]){
               dfs(j,m-1,vis,mat);
           }
           
       } 
      for (int i=0;i<n;i++){
          for (int j=0;j<m;j++){
              if(!vis[i][j] && mat[i][j]=='O'){
                  mat[i][j]='X';
              }
              
          }
      }
      return mat;
    }
};