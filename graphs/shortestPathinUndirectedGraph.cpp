class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M,
    int src){
    
    int distance[N];
    vector<int>adj[N];
    for(auto i:edges){
        adj[i[0]].push_back(i[1]);
         adj[i[1]].push_back(i[0]);
    }
    for (int i=0;i<N;i++){
        distance[i]=1e9;
    }
    queue<pair<int,int>>q;
    q.push({src,0});
    distance[src]=0;
    while(!q.empty()){
        int node=q.front().first;
        int dist=q.front().second;
        q.pop();
        for (auto it: adj[node]){
            if(distance[node]+1<distance[it]){
                distance[it]=distance[node]+1;
                q.push({it,distance[it]});
            }
        }
            }
    
    vector <int>ans(N,-1);
    for (int i=0;i<N;i++){
        if(distance[i]!=1e9){
            ans[i]=distance[i];
        }
    }
    
    return ans;
    
    }
};
