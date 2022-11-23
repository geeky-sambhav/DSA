 
class Solution{
    private:
    
    bool safe(vector <vector<int>>m,vector <vector<int>> visited,int n,int x,int y){
        
        if ((x>=0 &&x<n) && (y>=0 && y<n) && visited[x][y]==0 && m[x][y]==1){
            return true;
        }
        else{
            return false;
        }
        
    }
    
    
    void solve(vector<string> &ans, vector <vector<int>>&m, vector <vector<int>> visited,int n,string path,int x,int y){
        if (x==n-1 && y==n-1){
            ans.push_back(path);
            return;
        }
        
        visited[x][y]=1;
    //down
    int newx=x+1;
    int newy=y;
    if (safe(m,visited,n,newx,newy)){
        path.push_back('D');
        solve(ans,m,visited,n,path,newx,newy);
        path.pop_back();
    }
        
    //up
      newx=x-1;
    newy=y;
    if (safe(m,visited,n,newx,newy)){
        path.push_back('U');
        solve(ans,m,visited,n,path,newx,newy);
        path.pop_back();
    }
     //left
      newx=x;
    newy=y-1;
    if (safe(m,visited,n,newx,newy)){
        path.push_back('L');
        solve(ans,m,visited,n,path,newx,newy);
        path.pop_back();
    }
    
    
        //right
      newx=x;
    newy=y+1;
    if (safe(m,visited,n,newx,newy)){
        path.push_back('R');
        solve(ans,m,visited,n,path,newx,newy);
        path.pop_back();
    }
        
    
    
    
    
    
        
          visited[x][y]=0;
    }
    
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
          vector<string> ans;
        if(m[0][0]==0){
            return ans;
        }
        vector <vector<int>> visited=m;
        for (int i=0; i<visited.size();i++){
            for (int j=0;j<visited.size();j++){
                visited[i][j]=0;
            }
        }
       string path="";
       int x=0;
       int y=0;
      
       solve(ans,m,visited,n,path,x,y);
       sort(ans.begin(),ans.end());
       return ans;
        
        
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends