class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void solve(vector<int> adj[],vector<int>&dfs,int vis[],int node){
vis[node]=1;
dfs.push_back(node);
for (auto it: adj[node]){
    if(!vis[it]){
        dfs(adj,dfs,vis,it);
    }
}
        
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
       vector<int>dfs;
       int vis[V]={0};
        int node=0;
        solve(adj,dfs,vis,node);
        return dfs;
    }
};