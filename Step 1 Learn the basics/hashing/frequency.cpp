#include<bits/stdc++.h>
using namespace std;

// int number[1000000]= {0};
// global initialization max array limit is 10^7, the limit.

int main(){
  int n=5;
  int arr[5] = {3,2,1,2,3};

  int number[13]= {0};
  // main function max array limit is 10^6, the limit.
  int query[]={3,2,4,1,12};
  for(int i=0; i<n; i++){
    number[arr[i]]++;
  }
  
  for(int i=0; i<n; i++){
    cout<<number[query[i]]<<" ";
  }

  return 0;
}