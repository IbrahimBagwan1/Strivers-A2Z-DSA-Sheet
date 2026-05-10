#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:

    int LongestBitonicSequence(vector<int> arr) {

        int n = arr.size();

        if(n == 1) return 1;

        vector<int> dpForward(n, 1);
        vector<int> dpBackward(n, 1);

        // LIS from left to right
        for(int i = 1; i < n; i++){

            for(int prev = 0; prev < i; prev++){

                if(arr[i] > arr[prev] &&
                   1 + dpForward[prev] > dpForward[i]){

                    dpForward[i] = 1 + dpForward[prev];
                }
            }
        }

        // LIS from right to left (decreasing part)
        for(int i = n-1; i >= 0; i--){

            for(int prev = n-1; prev > i; prev--){

                if(arr[i] > arr[prev] &&
                   1 + dpBackward[prev] > dpBackward[i]){

                    dpBackward[i] = 1 + dpBackward[prev];
                }
            }
        }

        int maxi = 1;

        for(int i = 0; i < n; i++){

            maxi = max(maxi,
                       dpForward[i] + dpBackward[i] - 1);
        }

        return maxi;
    }
};

int main(){

    Solution obj;

    vector<int> arr = {1, 11, 2, 10, 4, 5, 2, 1};

    cout << obj.LongestBitonicSequence(arr);

    return 0;
}