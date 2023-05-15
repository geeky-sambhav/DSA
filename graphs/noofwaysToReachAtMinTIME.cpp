class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        vector<pair<long long, long long>> adj[n];
        
        for(auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        vector<long long>dist(n, LLONG_MAX);
        vector<long long>ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> pq;
        //{distance, node}
        pq.push({0, 0});
        
        int mod = (int)(1e9 + 7);           
        
        while(!pq.empty()) {
            int node = pq.top().second;
            int dis = pq.top().first;
          
            pq.pop();
            
            if(dist[node] < dis) continue; //slight change for 13th testcase failure
            
            for(auto it : adj[node]) {
                int adjNode = it.first;
                int edW = it.second;
                
                if(dis + edW < dist[adjNode]) {
                    dist[adjNode] = dis + edW;
                    ways[adjNode]  = ways[node];
                    pq.push({dis+edW, adjNode});
                }
                else if(dis + edW == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode]+ ways[node])%mod;
                }
            }
        }
        
        return int(ways[n-1]) % mod;
        
    }
};