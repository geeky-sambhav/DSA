class Solution {
    bool dfs(int node,int V, vector<int> adj[],int vis[],
    int pathvis[],int check[]){
        vis[node]=1;
        pathvis[node]=1;
        check[node]=0;
        for (auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,V,adj,vis,pathvis,check)==true) return true;
            }
            else if(pathvis[it]==1){
                return true;
            }
            
        
    }
    pathvis[node]=0;
    check[node]=1;
    return false;
    }
    
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        int vis[V]={0};
        int pathvis[V]={0};
        int check[V]={0};
        vector<int>safenodes;
        for(int i=0;i<V;i++){
             dfs(i,V,adj,vis,pathvis,check);
        }
        for (int i=0;i<V;i++){
            if(check[i]==1){
                safenodes.push_back(i);
            }
        }
        return safenodes;
    }
};