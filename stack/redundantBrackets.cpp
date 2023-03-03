//LOGIC
// IF ANY OPERATOR OCCURS BETWEEN 2 BRACKETS THEN THEY ARE NOT REDUNDANT


#include <bits/stdc++.h> 
bool findRedundantBrackets(string &s)
{
    stack<char>s1;
                   
    
    for(int i=0;i<s.length();i++){
        if (s[i]=='(' || s[i]=='+' || s[i]=='-' || s[i]=='*' || 
        s[i]=='/'){
            s1.push(s[i]);
        }
        else{
             bool isRedundant=true;
            if(s[i]==')'){
                while(s1.top()!='('){
                  if (s1.top() == '+' || s1.top() == '-' || s1.top() == '*' ||
                      s1.top() == '/') {
                          isRedundant=false;
                  }
                    s1.pop();
                }

                if(isRedundant==true){
                    return true;
                }
                s1.pop();
            }
            }
        
    }
    
return false;
}