//APROACH
// LAST SE SHURU HO JAO AUR CHECK KRTE JAO
// STARTING MEIN STACK KE -1 DAALDO COZ LAST VALA ELEMENT TO -1 HI RHEGA


#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
 vector<int> ans(n);
 stack<int>s1;
 s1.push(-1);
 for (int i=n-1;i>=0;i--){
while(arr[i]<=s1.top()){
    s1.pop();
}
ans[i]=s1.top();
s1.push(arr[i]);
 }
 return ans;
}