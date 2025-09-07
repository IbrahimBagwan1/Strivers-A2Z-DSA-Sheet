#include<bits/stdc++.h>
using namespace std;

int binaryToDecimal(string s){
  int n = s.size();
  int decimal=0;
  for(int i=n-1; i>=0; i--){
    int last = s[i]-'0';
    decimal += last * int(pow(2,n-i-1));
  }
  return decimal;
}


int main() {
    cout << "The Decimal Representation of : 1 is: "    << binaryToDecimal("1")    << endl;
    cout << "The Decimal Representation of : 10 is: "   << binaryToDecimal("10")   << endl;
    cout << "The Decimal Representation of : 101 is: "  << binaryToDecimal("101")  << endl;
    cout << "The Decimal Representation of : 110 is: "  << binaryToDecimal("110")  << endl;
    cout << "The Decimal Representation of : 111 is: "  << binaryToDecimal("111")  << endl;
    cout << "The Decimal Representation of : 1000 is: " << binaryToDecimal("1000") << endl;
    cout << "The Decimal Representation of : 1001 is: " << binaryToDecimal("1001") << endl;
    cout << "The Decimal Representation of : 1010 is: " << binaryToDecimal("1010") << endl;
    cout << "The Decimal Representation of : 1101 is: " << binaryToDecimal("1101") << endl;
    cout << "The Decimal Representation of : 1110 is: " << binaryToDecimal("1110") << endl;

    return 0;
}