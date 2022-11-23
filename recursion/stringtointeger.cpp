#include<iostream>
#include <string.h>
using namespace std;
int solve(char *a,int length){
    if (length==0){
        return 0;}
        int digit=a[length-1]-'0';
        int smallans=solve(a,length-1);
        return smallans*10+digit;
    }

int main(){
char a[]="12345";

int length=strlen(a);
cout<<solve(a,length);
// solve (a);
return 0;}