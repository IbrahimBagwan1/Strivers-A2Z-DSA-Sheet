#include<bits/stdc++.h>
using namespace std;
int n=3;
vector<int> arr= {3,1,2};

void subsequence(int idx, vector<int> v){
  if(idx>=n) {
    for(int ele: v){
      cout<<ele<<" ";
    }
    cout<<endl;
    return ;
  }
  v.push_back(arr[idx]);
  subsequence(idx+1, v);
  v.pop_back();
  subsequence(idx+1, v);
}

int main(){
  subsequence(0, {});
  return 0;
}