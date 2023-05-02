class Solution {
    void dfs(vector<vector<int>>& image, int row, 
    int col, int newc,vector<vector<int>>& ans,int delrow[],
    int delcol[],int initial){
        ans[row][col]=newc;
        int N=image.size();
        int n=image[0].size();
        for (int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow <N && ncol>=0 && ncol<n && 
            image[nrow][ncol]==initial && ans[nrow][ncol]!=newc){
                 dfs(image,row,col,newc,ans,delrow,delcol,initial);
            }
            
              
        }
        
        
        
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, 
    int sc, int newColor) {
     vector<vector<int>>ans=image;
     int delrow[4]={-1,0,+1,0};
     int delcol[4]={0,+1,0,-1};
     int initial=image[sr][sc];
     dfs(image,sr,sc,newColor,ans,delrow,delcol,initial);
     return ans;
    }
};