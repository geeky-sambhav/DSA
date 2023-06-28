//print name 5 times

#include<iostream>
#include<string>
using namespace std;
void op(int count,int sum){
    if (count<1){     
      cout<<sum;
         return ;
    }
  

  op(count-1,sum+count);

}
int main(){
string name="sambhav";
int sum=0;
op(10,sum);

return 0;}