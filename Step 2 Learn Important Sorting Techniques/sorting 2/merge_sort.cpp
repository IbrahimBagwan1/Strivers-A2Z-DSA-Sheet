#include<bits/stdc++.h>
using namespace std;


void merge(int arr[],int lo, int hi){

}

void merge_sort(int arr[], int lo, int hi){
  if(lo<hi){
    int mid = lo + lo-hi/2;

    merge_sort(arr, lo, mid);
    merge_sort(arr, mid+1, hi);

    merge(arr, lo, hi);
  }
}


int main(){
  int arr[] = {2,3,5,1,9,8,7,6,4};
  // int n = 9;
  int n = sizeof(arr)/ sizeof(arr[0]);
  merge_sort(arr, 0, n);
  for(int ele: arr){
    cout<< ele<< " ";
  }
}