#include<iostream>
using namespace std;
int  solve(int n,int k){
    if (n==0){
        return 1;
    }
    if (n<0){
        return 0;
    }
    int ans=0;
    for (int i = 1; i <= k; i++)
    {
        ans+=solve(n-i,k);
    }
    return ans;
    
}
int main(){
int n=4; //steps
int k=3; //1step ,2step ,3 step
cout<<solve(n,k);
return 0;}

//APPROACH
JO BHI NO OF WAYS WALA QUES AA JAYE USME YE APPROACH LGANI KI AGR 1 HO GYA TO BAKI KITNE CASES BNEGE JAISE ISME K KI VALUES 1,2,3 HO SKTI THI TO F(N-1),F(N-2),F(N-3 ) KIYA HAI
 F(N-1)+F(N-2)+F(N-3 ) JISME 1,2,3 K HAI MEANING YE AMOUNT OF STEPS HAI
