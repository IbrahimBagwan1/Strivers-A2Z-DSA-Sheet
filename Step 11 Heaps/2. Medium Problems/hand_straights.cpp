#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;

        map<int,int> mp;
        for (int i=0; i<n; i++){
            mp[hand[i]]++; 
        }
        
        while (!mp.empty()) {
            int curr = mp.begin()->first;  // smallest available card

            for (int i=0; i<groupSize; i++) {
                if (mp[curr+i] == 0) {
                    return false;  // missing a needed card
                }
                mp[curr+i]--;
                if (mp[curr+i] < 1) mp.erase(curr+i);
            }
        }

        return true;
    }
};

int main() {
    Solution sol;

    vector<int> hand1 = {1,2,3,6,2,3,4,7,8};
    int groupSize1 = 3;
    cout << (sol.isNStraightHand(hand1, groupSize1) ? "true" : "false") << endl;

    vector<int> hand2 = {1,2,3,4,5};
    int groupSize2 = 4;
    cout << (sol.isNStraightHand(hand2, groupSize2) ? "true" : "false") << endl;

    return 0;
}
