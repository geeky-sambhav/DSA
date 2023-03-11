// STARTING MEIN -1 STACK MEIN PUSH KRDO
 //AGR OPENING BRACKET HO TO PUSH KRDO STACK MEIN INDEXES
// NHI TO AGR CLOSING BRACKET HO TO 
// PEHLE POP KRDO TAKI -1 NIKAL JAYE
// FIR CHECK KRO KI STACK IS EMPTY OR NOT 
// IF NOT EMPTY IT MEANS THAT THERE IS SOME OPENING BRACKET IN STACK SO THE RESULT WILL BE CURRENT INDEX-THE TOP OF STACK


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