#include<iostream>
using namespace std;
vector <string>valid;
void solve(string &a,int open,int close){
    if (open==0 && close==0){
        valid.push_back(a);
        return;
    }
    if (open>0){
a.push_back('(');
solve(a,open-1,close);
a.pop_back();
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