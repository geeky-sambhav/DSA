class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool safe(int index,bool graph[101][101],int color[],
    int m, int n,int col){
        for (int i=0;i<n;i++){
            if(index!=i && graph[i][index]==1 && color[i]==col){
                return false;
            }
            
        }
        return true;
        
        
    }
    bool solve(int index,bool graph[101][101], int m, int n,
    int color[]){
        if(index>=n){
            return true;
        }
        for (int i=1;i<=m;i++){
          if(safe(index,graph,color,m,n,i)){
              color[index]=i;
              if(solve(index+1,graph,m,n,color)) return true;
              
          }
            
            
        }
        return false;
        
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        int color[n]={0};
       if(solve(0,graph,m,n,color)) return true;
       return false;
       
    }
};