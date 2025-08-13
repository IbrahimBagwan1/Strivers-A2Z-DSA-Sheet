#include<iostream>
using namespace std;

int partition(int arr[], int lo, int hi){
  int i , j, pivot;
  i = lo+1;
  j = hi;
  pivot = arr[lo];
  while(1){
    while(pivot >= arr[i] && i<=hi){
      i++;
    }

    while(pivot < arr[j] ){
      j--;
    }

    if(i<j){
      swap(arr[i], arr[j]);
    }else{
      swap(arr[lo], arr[j]);
      return j;
    }
  }
}

void quick_sort(int arr[], int lo , int hi){
  int i;
  if(lo<hi){
    i = partition(arr, lo,hi);
    quick_sort(arr, lo, i-1);
    quick_sort(arr, i+1, hi);
  }
}

int main(){
  int arr[] = {2,44,22,3,5,1,9,8,7,6,4};
  int n = sizeof(arr)/ sizeof(arr[0]);
  quick_sort(arr, 0, n-1);
  for(int ele: arr){
    cout<< ele<< " ";
  }
}