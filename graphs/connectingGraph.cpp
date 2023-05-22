class Disjointset{
  public:
  vector<int>size,parent;
  Disjointset(int n){
      size.resize(n+1);
      parent.resize(n+1);
      for (int i=0;i<=n;i++){
          size[i]=1;
          parent[i]=i;
      }}
      int findparent(int node){
          if(parent[node]==node){
              return node;
          }
          return parent[node]=findparent(parent[node]);
          
      }
      void unionbysize(int u,int v){
          int upv=findparent(v);
          int upu=findparent(u);
          if(upv==upu){
              return;
          }
          if (size[upu]<size[upv]){
              parent[upu]=upv;
              size[upv]+=size[upu];
              }
          else{
              parent[upv]=upu;
              size[upu]+=size[upv];
          }
          
      }
  
    
    
    
};
class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        Disjointset ds(n);
        int extraedges=0;
        for (auto it:edge){
            int u=it[0];
            int v=it[1];
            if(ds.findparent(u)==ds.findparent(v)){
                extraedges++;
            }
            else{
                ds.unionbysize(u,v);
        }                    }
        int components=0;
        for (int i=0;i<n;i++){
            if(ds.parent[i]==i){
                components++;
            }
            
        }
        int ans=components-1;
        if(extraedges>=ans){
            return ans;
        }
        return -1;
        
        
            
            
        
        
    }
};