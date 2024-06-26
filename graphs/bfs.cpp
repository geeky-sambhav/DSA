class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
       queue<int>q;
       int vis[V]={0};
       vector<int>bfs;
       q.push(vis[0])// or put the first element;
       vis[0]=1;
       while(!q.empty()){
           int node=q.front();
           q.pop();
           bfs.push_back(node);
           for(auto it:adj[node]){
               if(!vis[it]){
                   vis[it]=1;
                   q.push(it);
               }
           }
       }
       return bfs;                                                                                                                                        
    }
};