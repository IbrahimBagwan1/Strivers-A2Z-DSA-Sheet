#include<bits/stdc++.h>
using namespace std;


int generateSubsequences(int arr[], int sum, int i, int n, int s, vector<vector<int>>&ans, vector<int>&temp){
  if(i == n){
    if(s==sum){
      ans.push_back(temp);
      // for(auto ele: temp){
      //   cout<<ele<< " ";
      // }
      // cout<<endl;
      return 1;
    }
    return 0;
  }
    s += arr[i];
    temp.push_back(arr[i]);
    int l = generateSubsequences(arr, sum, i+1, n, s, ans, temp);
    
    temp.pop_back();
    s-=arr[i];
    int right = generateSubsequences(arr, sum, i+1, n, s, ans, temp);
    return l+right;
}

int main(){
  int arr[]={1,1,2};
  int sum = 2;
  int n = sizeof(arr)/ sizeof(arr[0]);
  vector<vector<int>> ans;
  vector<int> temp;
  cout<< generateSubsequences(arr, sum,0, n,0, ans, temp);


  return 0;
}