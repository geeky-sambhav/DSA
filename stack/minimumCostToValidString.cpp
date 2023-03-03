#include <bits/stdc++.h> 
int findMinimumCost(string str) {
  if(str.length()%2!=0){
    return -1;
  }
  stack<char>s1;
  for (int i=0;i<str.length();i++){
    char ch=str[i];
    if(ch=='{'){
      s1.push(ch);
    }
    else{
      if(!s1.empty() && s1.top()=='{'){
        s1.pop();
      }
      else{
        s1.push(ch);
      }

    }
  }
int ans=0;
int opening=0;
int closing=0;
while(!s1.empty()){
  if(s1.top()=='{'){
    opening++;
  }
  else {
    closing++;
  }
  s1.pop();
}
ans=((opening+1)/2)+((closing+1)/2);
return ans;
}