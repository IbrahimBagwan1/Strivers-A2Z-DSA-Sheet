#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {
    string cleaned;
    for(char c: s){
      if(isalnum(c)){
        cleaned += tolower(c);
      }
    }

    int i = 0;
    int j = cleaned.length() - 1;
    while(i < j){
      if(cleaned[i] != cleaned[j]) return false;
      i++;
      j--;
    }
    return true;
  }
};

int main() {
  Solution sol;
  string test;
  cout << "Enter a string: ";
  getline(cin, test);
  if(sol.isPalindrome(test)) {
    cout << "Palindrome" << endl;
  } else {
    cout << "Not a palindrome" << endl;
  }
  return 0;
}