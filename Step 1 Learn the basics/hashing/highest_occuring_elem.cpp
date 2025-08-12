#include<bits/stdc++.h>
using namespace std;

int main(){
  unordered_map<int,int> mp;
  vector<int> arr = {2,3,4,2,1,2,3,8};
  for(int i=0; i<arr.size(); i++){
    mp[arr[i]]++;
  }

  priority_queue<pair<int,int>> pq;
  for(auto ele: mp){
    pq.push({ele.second, ele.first});
  }

  cout<< "The Max Frequent element is: "<<pq.top().second;
  return 0;
}