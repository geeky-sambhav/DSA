class Solution {
  public:
    int findMaxLen(string s) {
        stack<int>s1;
        s1.push(-1);
        int result=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                s1.push(i);
            }
            else{
                s1.pop();
                if(!s1.empty()){
                result=max(result,i-s1.top());
                
                    }
                else{
                    s1.push(i);
                }
            
        }}
        return result;
    }
};