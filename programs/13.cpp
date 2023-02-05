#include <iostream>
using namespace std;
int main() {
   // Declare Variables
   char str[100], *pt;
     cout << "Enter any string  ";
   cin>>str;
   pt = str;
   while (*pt != '\0') {
      cout << *pt;
      pt++;
   }
   return 0;
}