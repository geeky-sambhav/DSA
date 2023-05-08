class Solution {
    
  
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
     queue<int>q;
    int indegree[V]={0};
     for (int i=0;i<V;i++){
         for (auto it:adj[i]){
             indegree[it]++;
            
         }
     }
     for(int i=0;i<V;i++){
         if(indegree[i]==0){
             q.push(i);
         }
     }
     vector<int>ans;
     while(!q.empty()){
         int node=q.front();
         q.pop();
         ans.push_back(node);
         for (auto it:adj[node]){
             indegree[it]--;
             if(indegree[it]==0){
                 q.push(it);
             }
             }
         }
     if (ans.size()!=V){
         return true;
     }
     else{
         return false;
     }}
     
};