#include<iostream>
using namespace std;
void solve(char a[],int i){
    if(a[i]=='\0' || a[i+1]=='\0'){
        return;
    }
if (a[i]=='p' && a[i+1]=='i'){
int j=i+2;
while (a[j]!='\0'){
    j++;
}
//SHIFTING FROM RIGHT
while (j>=i+2){
    a[j+2]=a[j];
    j--;
}
//  SINCE THE SPACE IS EMPTY NOW WE CAN PUT OUR ELEMENTS
a[i]='3';
a[i+1]='.';
a[i+2]='1';
a[i+3]='4';
//CALL THE FUNCTION
solve(a,i+4); //since 4 indexes use hue
}
//IF PI IS NOT THERE 
else{
    solve(a,i+1);
}
}
int main(){
char a[1000]="opibhpi";
solve(a,0);
cout<<a<<endl;

return 0;}

//APPROACH
// 1. CHECK IF PI IS THERE IF YES:
//  -->JO AGLA ELEMENT HOTA REPLACE KRNE VALE SE VAHA SE SHURU HONA AUR USKE INDEX KO STORE KRLO EG IN J
//  --> J KO LAST TK LE JAO
//  -->SHIFTING KRLO
//  -->PUT THE ELEMENTS
// -->RECURSIVE CALL

// 2. 
// RECURSIVE CALL