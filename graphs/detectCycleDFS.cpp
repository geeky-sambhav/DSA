class Solution {
  public:
  bool dfs(int vis[],vector<int> adj[],int node,int parent){
      vis[node]=1;
      for (auto it:adj[node]){
          if(!vis[it]){
              if(dfs(vis,adj,it,node)) return true;
          }
          else if(parent!=it){
              return true;
          }
      }
      return false;
      
      
      
      
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V]={0};
        for (int i=0;i<V;i++){
            if(!vis[i]){
               if (dfs(vis,adj,i,-1)) return true;
            }
        }
        return false;
    }
};