class Solution {
bool bfs(int start,vector<int>&color, vector<int>adj[]) {
    
    queue<int>q;
    q.push(start);
    color[start]=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it:adj[node]){
            if(color[it]==-1){
                q.push(it);
                color[it]=!color[node];
            }
            else if (color[it]==color[node]){
                return false;
            }
            
        }
        
    }
    return true;
    
    
    
    
}   
    
    
public:

	bool isBipartite(int V, vector<int>adj[]){
	vector<int>color(V,-1);
	 
	  for(int i=0;i<V;i++){
	      if(color[i]==-1){
	          if(bfs(i,color,adj)==false){
	              return false;
	          }
	      }
	      
	  }
	  return true;
	  
	  
	}

};