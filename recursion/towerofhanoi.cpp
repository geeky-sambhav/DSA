#include<iostream>
using namespace std;
void solve(int n,char src,char dest,char helper){
    if (n==0){
      return;
    }
    solve(n-1,src,helper,dest);
    cout<<"MOVE "<<n<<" from "<<src<<"to "<<dest<<endl;
    solve(n-1,helper,dest,src);

}
int main(){
int n=3;
solve(n,'A','B','C');
return 0;}