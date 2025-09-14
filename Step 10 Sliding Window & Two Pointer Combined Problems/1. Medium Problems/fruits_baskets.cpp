// This question can also be stated as : Maximum Subarray with atmost two types of Numbers.
#include <bits/stdc++.h>
using namespace std;

class Solution1{
public:
  int totalFruits(vector<int>& fruits) {
    int n = fruits.size();
    if(n==1) return 1;
    if(n==2) return 2;

    int left =0;
    int right =1;
    int el1=fruits[0],el2=-1; 
    int pointer=-1;
    int maxLen=0;

    while (right< n){
      if(fruits[right]!=el1 && fruits[right]!=el2 && el1!=-1 && el2!=-1){
        left = pointer;
        right=pointer;
        el1=fruits[right];
        el2=-1;
      }

      if(el2==-1 && fruits[right]!=el1){
        el2 = fruits[right];
        pointer = right;
      } 
      maxLen = max(maxLen, right-left+1);


      right++;
    }
    
    return maxLen;
  }
};

class Solution2{
  public:
    int totalFruits(vector<int>& fruits){
        int right=0, left=0;
        int n = fruits.size();
        if(n==0) return 0;
        map<int,int> mp;
        int maxLen = 0;

        while(right<n){
            mp[fruits[right]]++;
            if(mp.size()>2){
                mp[fruits[left]]--;
                if(mp[fruits[left]] == 0) mp.erase(fruits[left]);
                left++;
            }

            if(mp.size()<=2){
                maxLen = max(maxLen, right-left+1);
            }            
            
            right++;
        }
        return maxLen;
    }
};

int main() {
    Solution1 sol1;
    Solution2 sol2;
    vector<vector<int>> tests = {
        {1,2,3,2,2},
        {1,2,1,2,3},
        {1,1,1,1},
        {1},
        {1,2},
        {1,2,3,4,5},
        {1,2,3,2}
    };
    for (auto &t : tests) {
        cout << "arr = ";
        for (int x: t) cout << x << ' ';
        cout << " -> " << sol1.totalFruits((vector<int>&)t) << '\n';
    }

    cout<<endl<< "Solution 2"<<endl;
    for (auto &t : tests) {
        cout << "arr = ";
        for (int x: t) cout << x << ' ';
        cout << " -> " << sol2.totalFruits((vector<int>&)t) << '\n';
    }
    return 0;
}

