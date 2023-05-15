class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, 
    int dst, int K)  {
     vector<pair<int,int>>adj[n];
     for (auto it :flights){
         adj[it[0]].push_back({it[1],it[2]});
     }
     queue<pair<int,pair<int,int>>>q;
     q.push({0,{src,0}});
     vector<int>distance(n,1e9);
     distance[src]=0;
     while(!q.empty()){
         auto it=q.front();
         int steps=it.first;
         int node=it.second.first;
         int dist=it.second.second;
         q.pop();
         if(steps>K){
             continue;
         }
         for (auto it:adj[node]){
             int adjnode=it.first;
             int wt=it.second;
             if(dist+wt<distance[adjnode] && steps<=K){
                 q.push({steps+1,{adjnode,dist+wt}});
                 distance[adjnode]=dist+wt;
             }
             }
         
         
     }
    
         if (distance[dst]==1e9){
             return -1;}
         
         else{
             return distance[dst];
         }
     
     
    }
};