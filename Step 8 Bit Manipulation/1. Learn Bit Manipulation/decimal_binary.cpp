#include<bits/stdc++.h>
using namespace std;

string decimalToBinary(int n){
  string binary;
  while(n!=0){
    int last = n%2;
    if(last==0){
      binary += "0";
    }
    else{
      binary += "1";
    }
    n/=2;
  }
  reverse(binary.begin(), binary.end());
  return binary;
}


int main(){
  for(int i=5; i<15; i++){
    cout<<"The Binary Representation of :"<<i<<" is: "<<decimalToBinary(i)<<endl;  
  }

  return 0;
}