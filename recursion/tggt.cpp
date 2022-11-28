#include<iostream>
using namespace std;
void solve(int digits,string mapping[]){
if(digits==0){
    return;
}
int n=digits%10;
string value=mapping [n];
solve(digits/10,mapping);
cout<<value<<" ";

}
int main(){
string mapping[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
solve(123,mapping);
return 0;}