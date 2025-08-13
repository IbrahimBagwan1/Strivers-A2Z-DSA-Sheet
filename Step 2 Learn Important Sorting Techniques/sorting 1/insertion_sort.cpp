#include<bits/stdc++.h>
using namespace std;


void insertion_sort(int arr[], int n){
  for (int i = 0; i < n; i++)
  {
    int j=i;
    while(j>0 && arr[j-1]> arr[j]){
      int temp = arr[j-1];
      arr[j-1] = arr[j];
      arr[j] = temp;
      j--;
    }
  }
  
}

int main(){
  int arr[] = {2,3,5,1,9,8,7,6,4,77, 48, 22};
  int n = sizeof(arr)/ sizeof(arr[0]);
  insertion_sort(arr, n);
  for(int ele: arr){
    cout<< ele<< " ";
  }
  return 0;
}