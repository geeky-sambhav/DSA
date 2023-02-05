#include<iostream>
using namespace std;
void count(char str[]){
int count = 0;
   while (str[count] != '\0')
   count++;
   cout<<"The string is "<<str<<endl;
   cout <<"The length of the string is "<<count<<endl;

}
int main() {
   char str[] = "Apple";
   count(str);
   return 0;
}