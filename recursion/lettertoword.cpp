#include<iostream>
using namespace std;
void solve(int digit,string words[]){
    if (digit==0){
        return;
    }
    solve(digit/10,words);
    int last_digit=digit%10;
    cout<<words[last_digit]<<" ";
}
int main(){
string words[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
solve(12045,words);
return 0;}