#include <iostream>
using namespace std;
string concat(string s1,string s2,string result){
for ( int i = 0; i < s1.size(); i++)  
{  
result = result + s1[i]; 
}   
for ( int i = 0; i < s2.size(); i++)  
{  
result = result + s2[i]; 
} 
return result;
}
int main()
{
    string s1, s2, result;
result="";
    cout << "Enter string s1: ";
    getline (cin, s1);

    cout << "Enter string s2: ";
    getline (cin, s2);
result=concat(s1,s2,result);
    cout << "Resultant String = "<< result;
    return 0;
}