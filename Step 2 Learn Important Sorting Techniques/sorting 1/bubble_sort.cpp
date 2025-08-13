#include<bits/stdc++.h>
using namespace std;

void swap(int &a, int &b){
  int temp = a;
  a= b;
  b= temp;
}

void bubble_sort(int arr[], int n){
  for (int i = 0; i < n-1; i++){
    for (int j = i+1; j < n; j++){
      if(arr[i] > arr[j]){
        swap(arr[i], arr[j]);
      }
    }
  }
}


int main(){
  int arr[] = {2,3,5,1,9,8,7,6,4};
  int n = sizeof(arr)/ sizeof(arr[0]);
  // int n = 9;
  bubble_sort(arr, n);
  for(int ele: arr){
    cout<< ele<< " ";
  }
}