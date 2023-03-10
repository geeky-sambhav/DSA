// STEP 1 FIND POTENTIAL CANDIDATE
// STACK MEIN 2 ELEMENTS KO UTHAYE JAO AUR DEKHO KE VO EK DUSRE KO JAANTE HAI KE NHI
// LAST MEIN 1 BNDA REH JAYEGA JO KISI KO NHI JAANTA HO VO HOGA POTENTIAL CANDIDATE

// STEP 2 FIND ZEROCOUNT AND ONECOUNT AND RETURN THE ANSWER



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
        int zerocount=0;
        for(int i=0;i<n;i++){
            if(M[potential][i]==0){
                zerocount++;
            }
        }
        if(zerocount!=n){
            return -1;
        }
        
        int onecount=0;
        for(int i=0;i<n;i++){
            if(M[i][potential]==1){
                onecount++;
            }
        }
        if(onecount!=n-1){
            return -1;
        }
        return potential;
    }
};