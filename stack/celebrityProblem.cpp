class Solution 
{
    public:
    bool knows(int a,int b,vector<vector<int> >& M, int n){
        
            if(M[a][b]==0){
                return false;
            }
            else{return true;
            }
        
        
    }
    
    
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
      stack<int>s1;
      for (int i=0;i<n;i++){
          s1.push(i);
                }
        while(s1.size()>1){
            int a=s1.top();
            s1.pop();
            int b=s1.top();
            s1.pop();
            if(knows(a,b,M,n)){
                s1.push(b);
            }
            else
            {
                s1.push(a);
                }
            
        }
        int potential=s1.top();
        int rowcount=0;
        for(int i=0;i<n;i++){
            if(M[potential][i]==0){
                rowcount++;
            }
        }
        if(rowcount!=n){
            return -1;
        }
        
        int colcount=0;
        for(int i=0;i<n;i++){
            if(M[i][potential]==1){
                colcount++;
            }
        }
        if(colcount!=n-1){
            return -1;
        }
        return potential;
    }
};