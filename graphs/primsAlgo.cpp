class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        //pq mein wts,nodes push krte jao
        //vis array mein 1 krte jao when adj ends
        //adj ko check krte jao
        
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair
        <int,int>>>pq;
        pq.push({0,0});
        vector<int>vis(V,0);
        int sum=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int wt=it.first;
            int node=it.second;
            if(vis[node]==1){
                continue;
            }
            vis[node]=1;
            sum+=wt;
            for (auto it:adj[node]){
                int dis=it[1];
                int adjnode=it[0];
                if(!vis[adjnode]){
                    pq.push({dis,adjnode});
                }
                }
            }
        return sum;
    }
};