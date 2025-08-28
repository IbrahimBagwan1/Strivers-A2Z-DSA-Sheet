#include<bits/stdc++.h>
using namespace std;


void generateSubsequences(int arr[], int sum, int i, int n, int s, vector<vector<int>>&ans, vector<int>&temp){
  if(i == n){
    if(s==sum){
      ans.push_back(temp);
      for(auto ele: temp){
        cout<<ele<< " ";
      }
      cout<<endl;
    }
    return ;
  }
    s += arr[i];
    temp.push_back(arr[i]);
    generateSubsequences(arr, sum, i+1, n, s, ans, temp);
    
    temp.pop_back();
    s-=arr[i];
    generateSubsequences(arr, sum, i+1, n, s, ans, temp);
}

int main(){
  int arr[]={1,1,2};
  int sum = 2;
  int n = sizeof(arr)/ sizeof(arr[0]);
  vector<vector<int>> ans;
  vector<int> temp;
  generateSubsequences(arr, sum,0, n,0, ans, temp);


  return 0;
}