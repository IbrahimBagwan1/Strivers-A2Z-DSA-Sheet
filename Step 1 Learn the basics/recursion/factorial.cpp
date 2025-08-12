#include<bits/stdc++.h>
using namespace std;


int fact(int n){
  if(n==1) return 1;
  if(n==0) return 0;
  return n * fact(n-1);
}

int main(){
  for(int i=1; i<=10; i++){
    cout<<endl;
    cout<<"The Factorial of:"<<i<<" is: "<<fact(i);
  }
  return 0;
}