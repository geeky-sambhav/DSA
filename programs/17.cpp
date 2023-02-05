#include <iostream>
#include <string>
using namespace std;
int main() {
  // Prompt the user to enter a string
  string str;
  cout << "Enter a string: ";
cin>>str;

  // Find the length of the longest repeating sequence
  int max_length = 0;
  for (int i = 0; i < str.length(); i++) {
    for (int j = i + 1; j < str.length(); j++) {
      int length = 0;
      while (str[i + length] == str[j + length] && (i + length) < str.length() && (j + length) < str.length()) {
        length++;
      }
      if (length > max_length) {
        max_length = length;
      }
    }
  }

  // Print the result
  cout << "The longest repeating sequence has a length of " << max_length << "." << endl;

  return 0;
}