int findLongestConseqSubseq(int arr[], int N)
    {
    //   Better
    // sort(arr,arr+N);
    // int longest=1;
    // int lastsmaller=INT_MIN;
    // int currcount=0;
    // for (int i=0;i<N;i++){
    //     if(arr[i]-1==lastsmaller){
    //         currcount++;
    //         lastsmaller=arr[i];
    //     }
    //     else if(arr[i]!=lastsmaller){
    //         currcount=1;
    //         lastsmaller=arr[i];
    //     }
        
    // longest=max(longest,currcount);
    // }
    // return longest;
    // }
    
    
    //OPTIMAL
    
    int longest=1;
    int count=0;
    unordered_set<int> s;
    for (int i=0;i<N;i++){
        s.insert(arr[i]);
    }
    for(auto i:s){
        if(s.find(i-1)==s.end()){
            int x=i;
            count=1;
        while (s.find(x+1)!=s.end()){
            count++;
            x=x+1;
        }
        }
        longest=max(longest,count);
    }
    return longest;
    
    }