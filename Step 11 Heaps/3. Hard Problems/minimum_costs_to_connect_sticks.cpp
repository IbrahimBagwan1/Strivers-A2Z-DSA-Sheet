#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        int n = sticks.size();
        priority_queue<int, vector<int> , greater<int>> pq;

        for(int &ele: sticks) pq.push(ele);

        int fullCost=0;

        while(!pq.empty()){
            int first = 0;
            if(!pq.empty()) first = pq.top(); pq.pop();
            
            int second = 0; 
            if(!pq.empty()) second = pq.top(); pq.pop();
           
            int combine = first + second;

            fullCost += combine;
            if(!pq.empty()) pq.push(combine);
        }
        return fullCost;
    }
};

int main(){
  vector<int> sticks = {1, 8, 3, 5};
  Solution sol;
  cout<< sol.connectSticks(sticks);
  return 0;
}