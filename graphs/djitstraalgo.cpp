class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
      set<pair<int,int>>st;
      st.insert({0,S});
      vector<int>distance(V,1e9);
      distance[S]=0;
      while(!st.empty()){
          auto it=*st.begin();
          int node=it.second;
          int dist=it.first;
          st.erase(it);
          for (auto it:adj[node]){
          int adjnode=it[0];
          int wt=it[1];
            if(dist+wt<distance[adjnode]){
                if(distance[adjnode]!=1e9){
                    st.erase({distance[adjnode],adjnode});
                }
                distance[adjnode]=dist+wt;
                st.insert({distance[adjnode],adjnode});
            }
          }
      }
      return distance;
    }
};