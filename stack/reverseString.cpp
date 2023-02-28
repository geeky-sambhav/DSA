#include <iostream>
#include<stack>
using namespace std;

int main(){
string str="sambhav";
    stack<char> s1;
for (int i = 0; i < str.length(); i++)
{
    s1.push(str[i]);
}
string rev="";

while(!s1.empty()){
rev=rev+s1.top();
s1.pop();
}
cout<<"The reversed string is "<<rev<<endl;



    return 0;
}