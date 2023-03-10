// AGR OPERAND HAI TO STACK MEIN PUSH KRDO
// AGR OPERATOR HAI TO TOP OF STACK IS SECOND OPERAND AND USKE NEECHE VALA FIRST OPERAND 
// DONO KO POP KRO AUR SOLVE KRKE STACK MEIN PUSH KRDO



class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
       stack<int>s;
       for (int i=0;i<S.length();i++){
           if(S[i]=='+' || S[i]=='-' || S[i]=='*' || S[i]=='/'){
               int b=s.top();
               s.pop();
               int a=s.top();
               s.pop();
               int c;
               if(S[i] == '*')
                    c = a*b;
                else if(S[i] == '/')
                    c = a/b;
                else if(S[i] == '+')
                    c = a+b;
                else if(S[i] == '-')
                    c = a-b;
                
                s.push(c);
           }
           else{
               s.push(S[i]-'0');
           }
       }
       return s.top();
    }
};