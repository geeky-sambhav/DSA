
class Solution {
  public:
  
  void dfs(int node,vector<int>a[], int vis[]){
      vis[node]=1;
      for(auto i:a[node]){
          if(!vis[i]){
              dfs(i,a,vis);
          }
      }
      
  }
    int numProvinces(vector<vector<int>> adj, int V) {
     vector <int> a[V];
     for(int i=0;i<V;i++){
         
         for (int j=0;j<V;j++)
         {
             
             if(adj[i][j]==1 && i!=j){
                 a[i].push_back(j);
                 a[j].push_back(i);
             }
         }
     }
     int vis[V]={0};
    
     int count=0;
     for (int i=0;i<V;i++){
         if(!vis[i]){
             count++;
             dfs(i,a,vis);
         }
     }
     return count;
     
     
    }
};