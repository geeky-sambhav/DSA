/* ------------------------------- MEMOIZATION ------------------------------ */

#include <bits/stdc++.h> 
int solve(int index,vector<int> &num, int x){

if(index==0){
    if(x%num[0]==0){
        return (x/num[0]);
    } else {
      return 1e9;
    }
}
if (index < 0) {
        return 1e9; // Return a large value to indicate failure
    }


    int pick=1e9;
    if(x>=num[index]){
        pick=1+solve(index,num,x-num[index]);
    }
    int notpick=0+solve(index-1,num,x);

    return min(pick,notpick);
}

