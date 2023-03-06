vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, 
                                             long long int K) {
    queue<long long >q;
    vector<long long>ans;
    for(int i=0;i<K-1;i++){
        if(A[i]<0){
            q.push(A[i]);
         
        }
    }
    for (int i=K-1;i<N;i++){
        if(A[i]<0){
            q.push(A[i]);
            }
        if(!q.empty()){
               ans.push_back(q.front());
            //window khtmm ho rhi
            if(q.front()==A[i-K+1]){
                q.pop();
            }
            
        }
        else{
            ans.push_back(0);
        }
        
        
    }
   return ans;                                              
 }