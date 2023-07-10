int solve(int index1,int index2,string s1,string s2){
if(index2<0 && index1>=0){
   for (int i=0;i<=index1;i++){
      if(s1[i]!='*'){
         return false;
      }
   }
   return true;
}
if(index1<0 && index2<0){
   return true;
}
if(index1<0 || index2<0){
   return false;
}

if(s1[index1]=='?' || s1[index1]==s2[index2]){
   return solve(index1-1,index2-1,s1,s2);
}
if(s1[index1]=='*'){
   return solve(index1-1,index2,s1,s2) || solve(index1,index2-1,s1,s2);
}
return false;
}

bool wildcardMatching(string pattern, string text)
{
   int n1=pattern.size();
   int n2=text.size();
   return solve(n1-1,n2-1,pattern,text);
}
