#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Data {
        int st;
        int ed;
        int pos;
    };

    static bool cmp(Data a, Data b) {
        return a.ed < b.ed;
    }

    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<Data> arr;
        
        for (int i = 0; i < n; i++) {
            arr.push_back({start[i], end[i], i+1});  // correct order
        }

        sort(arr.begin(), arr.end(), cmp);
        
        int counter = 1;
        int freeTime = arr[0].ed;

        for (int i = 1; i < n; i++) {
            if (arr[i].st > freeTime) {
                counter++;
                freeTime = arr[i].ed;
            }
        }
        return counter;
    }
};

int main() {
    Solution obj;

    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end   = {2, 4, 6, 7, 9, 9};

    cout << "Maximum meetings: " << obj.maxMeetings(start, end) << endl;
    return 0;
}
