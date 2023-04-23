class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
       queue<int>q;
       int arr[V]={0};
       vector<int>bfs;
       q.push(arr[0]);
       arr[0]=1;
       while(!q.empty()){
           int node=q.front();
           q.pop();
           bfs.push_back(node);
           for(auto it:adj[node]){
               if(!arr[it]){
                   arr[it]=1;
                   q.push(it);
               }
           }
       }
       return bfs;
    }
};