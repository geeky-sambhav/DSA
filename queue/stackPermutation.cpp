// IT CHECKS WHETHER A WITH STACK CAN BECOME B
// PUT THE ELEMENT IN THE STACK
// NOW CHECK IF TOP IS EQUAL TO B
// IF YES KEEP POPPING
// AGR LAST TAK STACK EMPTY HAI TO RETURN TRUE ELSE RETURN FALSE

class Solution{
public:
    int isStackPermutation(int N,vector<int> &A,vector<int> &B){
        stack<int>s;
        int j=0;
        for(int i=0;i<N;i++){
            s.push(A[i]);
            while(!s.empty() && s.top()==B[j]){
               s.pop();
               j++;
            }
    }
    return s.empty();}
};