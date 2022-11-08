#include<iostream>
using namespace std;

void solve(string &a,int open,int close){
    if (open==0 && close==0){
        valid.push_back(a);
        return;
    }
    if (open>0){
a.push_back('(');
solve(a,open-1,close);
a.pop_back();  //popback kiya coz jb bhi choice vala ques aa jaye ya ye ya vo to popback krte taki agle function call k liye empty rhe
    }

    if (close>0)
    {
        if (open<close)
        {
            a.push_back(')');
            solve(a,open,close-1);
            a.pop_back();
            /* code */
        }
    }
}
int main(){
   
string a="";
solve(a,2,2);
return 0;}

//APPROACH
// OPEN WALE SHOULD BE GREATER THAN CLOSE
