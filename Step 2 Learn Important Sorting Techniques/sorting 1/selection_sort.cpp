#include<bits/stdc++.h>
using namespace std;


void swap(int &a, int &b){
  int temp = a;
  a= b;
  b= temp;
}

void selection_sort(int arr[], int n){
  int idx =0;
  for (int i = 0; i < n-1; i++){
    int mini = arr[i];
    for (int j = i; j < n; j++){
      if(mini>arr[j]){
        mini = arr[j];
        idx = j;
      }
    }
    swap(arr[i], arr[idx]);
  }
}

int main(){
  int arr[] = {2,3,5,1,9,8,7,6,4};
  // int n = 9;
  int n = sizeof(arr)/ sizeof(arr[0]);
  selection_sort(arr, n);
  for(int ele: arr){
    cout<< ele<< " ";
  }
  return 0;
}