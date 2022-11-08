#include<iostream>
using namespace std;
void solve (char a[],char *b,int i,int j){
    if (a[i]=='\0'){
        b[j]='\0';
        cout<<b<<endl;
        return;
    }
    b[j]=a[i];
    solve(a,b,i+1,j+1);
    solve(a,b,i+1,j);
}
int main(){
char a[]="abc";
char b[10];
solve(a,b,0,0);
return 0;}