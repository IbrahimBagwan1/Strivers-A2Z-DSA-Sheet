#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int countPrimes(int n) {
        vector<bool> seive(n+1,1);
        int count=0;
        for(int i=2; i<=sqrt(n); i++){
            if(seive[i]){
                for(int j = i * i; j < n; j += i){
                    seive[j] = false;
                }
            }
        }

        for(int i=2; i<n; i++){
            if(seive[i]) count++;
        }
        return count;
    }
};

int main(){
  Solution sol;
  cout<< "The Prime Numbers in the Range 19 is: "<< sol.countPrimes(19);

  return 0;
}