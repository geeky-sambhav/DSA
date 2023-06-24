class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,
                 int distanceThreshold) {
                     
                     vector<pair<int,int>>adj[n];
    for (auto it:edges){
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }
    int citycount=1e9;
    int cityno;
     priority_queue<pair<int,int>,vector<pair<int,int>>,
     greater<pair<int,int>>>pq;
    for (int i=0;i<n;i++){
     vector<int>dist(n,1e9);
     pq.push({0,i});
     dist[i]=0;
    while(!pq.empty()){
        int distance=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for(auto it :adj[node]){
            int adjnode=it.first;
            int wt=it.second;
            if (distance+wt<dist[adjnode] ){
                dist[adjnode]=distance+wt;
                pq.push({dist[adjnode],adjnode});
                
            }
        }
    }
    int count=0;
    for(int j=0;j<n;j++)    {
        if (dist[j]<=distanceThreshold){
            count++;
        }
    }
        if(count<=citycount){
            citycount=count;
            cityno=i;
        }
        
    }
    
                     
                     
        return cityno;    
                 }
};
