#include<bits/stdc++.h>
using namespace std;
#define Size 100

void merge(int arr[],int lo, int mid, int hi){
  int i,j,k;
  i = lo;
  j = mid+1;
  k = lo;
  int brr[Size];
  while(i<=mid && j<=hi){
    if(arr[i] < arr[j]){
      brr[k++] = arr[i++];
    }
    else{
      brr[k++] = arr[j++];
    }
  }
  
  while(i<=mid){
    brr[k++] = arr[i++];
  }
  
  while(j<= hi){
    brr[k++] = arr[j++];
  }

  for(int i=lo; i<=hi; i++){
    arr[i] = brr[i];
  }
}

void merge_sort(int arr[], int lo, int hi){
  if(lo<hi){
    int mid = lo + (hi-lo)/2;

    merge_sort(arr, lo, mid);
    merge_sort(arr, mid+1, hi);

    merge(arr, lo, mid, hi);
  }
}


int main(){
  int arr[] = {2,44,22,3,5,1,9,8,7,6,4};
  // int n = 9;
  int n = sizeof(arr)/ sizeof(arr[0]);
  merge_sort(arr, 0, n-1);
  for(int ele: arr){
    cout<< ele<< " ";
  }
}