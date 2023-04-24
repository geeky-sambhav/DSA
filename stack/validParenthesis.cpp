bool isValidParenthesis(string expression)
{
    stack<char> s1;
    for (int i=0;i<expression.length();i++){
        char str=expression[i];
        //pushing open brackets
        if(str=='[' || str=='(' || str=='{'){
            s1.push(str);
        } else {
          // match closing
          if(!s1.empty()){
          if ((str == ')' && s1.top() == '(') || (str == '}' 
          && s1.top() == '{') || (str==']' && s1.top()=='[')){
              s1.pop();
          } else {
            return false;
          }
          }
          else{//starting mein hi closing bracket aa gya
              return false;
          }
        }
    }
    if(!s1.empty()){
        return false;
    }
    else{
        return true;
    }
}




//simple soluion


class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else{
                 if(st.empty() && (s[i]==')' || s[i]=='}' || s[i]==']')){
                     return false;
                 }

                if((s[i]==')' && st.top()=='(') || (s[i]=='}' && st.top()=='{') || (s[i]==']' && st.top()=='[')  ){
                    st.pop();
                }
                else{
                    return false;
                }


            }
        }
        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};