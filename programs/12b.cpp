#include <iostream>  
using namespace std;  
  
void RelationalCompare ( string str1, string str2)  
{  
    // use relational not equal operator  
    if ( str1 != str2)  
    {  
        cout << str1 << " is not equal to " << str2 << " string. " << endl;  
        if (str1 > str2)  
        {  
            cout << str1 << " is greater than " << str2 << " string." << endl;  
        }  
        else  
        {  
            cout << str2 << " is greater than " << str1 << " string." << endl;      
        }  
    }  
        else  
            cout << str1 << " is equal to " << str2 << " string." << endl;  
}  
  
int main ()  
{  
    string str1 ( "Sambhav");  
  
      
    string str2 ("gandhi");  
    // call function  
    RelationalCompare (str1, str2);  
      
  
    return 0;  
}  