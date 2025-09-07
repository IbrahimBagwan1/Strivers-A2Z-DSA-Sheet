#include<bits/stdc++.h>
using namespace std;

void swap2Num(int &a, int &b){
  a = a^b;
  b = a^b;
  a = a^b;
}

int main(){
  int a=3;
  int b=5;
  cout<<a<<" "<<b<<endl;
  swap2Num(a,b);
  cout<<a<<" "<<b;
  return 0;
}