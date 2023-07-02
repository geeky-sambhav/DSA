class Solution{
    public:
    void solve(int x,int y,vector<vector<int>> &m,vector <string>&ans,
    vector<vector<bool>>&visited,int n,int delrows[],int delcols[],
    string move){
        if(x==n-1 && y==n-1){
            ans.push_back(move);
            return;
        }
        string moves="DLRU";
       for (int i=0;i<4;i++){
           int delr=x+delrows[i];
           int delc=y+delcols[i];
           if(delr>=0 && delr<n && delc>=0 && delc<n && 
           visited[delr][delc]==0 && m[delr][delc]==1){
             visited[delr][delc]=1;
             solve(delr,delc,m,ans,visited,n,delrows,delcols,move+moves[i]);
             visited[delr][delc]=0;
           }
       }
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector <string>ans;
        if(m[0][0]==0){
            return ans;
        }
        
        vector<vector<bool>>visited(n,vector<bool>(n,0));
        int delrows[]={1,0,0,-1};
        int delcols[]={0,-1,1,0};
        visited[0][0]=1;
        solve(0,0,m,ans,visited,n,delrows,delcols,"");
        return ans;
    }
};
