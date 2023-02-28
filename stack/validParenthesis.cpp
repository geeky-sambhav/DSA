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