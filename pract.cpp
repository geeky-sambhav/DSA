#include<iostream>
using namespace std;
int solve(string a,int n){
    if (n==0){
        return 0;
    }
    int b=solve(a,n-1);
    int c=a[n-1]-'0';
    return (b*10+c);
}
int main(){
 string a="14560";
 cout<<solve(a,5);
 cout<<a;
return 0;}