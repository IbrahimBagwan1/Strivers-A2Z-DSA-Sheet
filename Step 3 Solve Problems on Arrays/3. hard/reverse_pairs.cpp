#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long int count=0;
    void merge(vector<int>& arr,int lo, int mid, int hi){
        int i,j,k;
        i = lo;
        j = mid+1;
        k = lo;
        vector<int> brr;
        while(i<=mid && j<=hi){
            if(arr[i]> arr[j]*2){
              count+= (mid-i+1);
            }
            if(arr[i] <= arr[j]){
                brr.push_back(arr[i]);
                k++;
                i++;
              }
              else{
                brr.push_back(arr[j]);
                k++;
                j++;
              }
            }
            
            while(i<=mid){
              brr.push_back(arr[i]);
              k++;
              i++;
            }
            
            while(j<= hi){
              brr.push_back(arr[j]);
              k++;
              j++;
        }

        for(int i=lo; i<=hi; i++){
            arr[i] = brr[i-lo];
        }
    }

    void merge_sort(vector<int>& nums, int lo, int hi){
        if(lo<hi){
            int mid = lo + (hi-lo)/2;
            merge_sort(nums, lo, mid);
            merge_sort(nums, mid+1, hi);
            merge(nums, lo, mid, hi);
        }
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        count=0;
        merge_sort(nums,0,n-1);
        return count;
    }
};

int main(){
  Solution sol;
  vector<int> nums = {1,3,2,3,1};
  int count = sol.reversePairs(nums);
  cout<< count;
  return 0;
}