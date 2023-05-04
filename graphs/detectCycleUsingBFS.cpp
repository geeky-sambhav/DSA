class Solution {
  public:
  
  bool detect(int src,int vis[],vector<int>adj[]){
      queue<pair<int,int>>q;
      vis[src]=1;
      q.push({src,-1});
      while(!q.empty()){
          int node=q.front().first;
          int parent=q.front().second;
          q.pop();
          for(it:adj[node]){
              if(!vis[it]){
                  q.push({it,node});
                  vis[it]=1;
                  
              }
              else if(it!=parent){
                  return true;
              }
          }
          }
      return false;
      }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
      int vis[V]={0};
      for (int i=0;i<V;i++){
          if(!vis[i]){
              if(detect(i,vis,adj)) return true;
              
          }
      }
      return false;
    }
};