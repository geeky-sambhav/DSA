class Solution {
    int timer=1;
public:
void dfs(int node,int parent,int low[],int tin[],vector<int>adj[],vector<vector<int>>&bridges,vector<int>&vis){
vis[node]=1;
tin[node]=low[node]=timer;
timer++;
for (auto it:adj[node]){
if(it==parent) continue;
if(vis[it]==0){
    dfs(it,node,low,tin,adj,bridges,vis);
    low[node]=min(low[it],low[node]);
    if(low[it]>tin[node]){
        bridges.push_back({it,node});

    }
    
}
else{
    low[node]=min(low[it],low[node]);
}


}




}

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        int low[n];
        int tin[n];
        vector<int>vis(n,0);
        vector<vector<int>>bridges;
        for (auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(0,-1,low,tin,adj,bridges,vis);
    return bridges;
    }
};