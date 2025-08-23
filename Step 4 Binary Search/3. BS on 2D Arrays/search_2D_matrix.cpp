#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(); 
        int m = matrix[0].size();
        int left = 0;
        int right = n*m-1;

        while(left <= right){
            int mid = left+ (right-left)/2;

            if(matrix[mid/m][mid%m] == target)return true;

            if(matrix[mid/m][mid%m] > target){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 3;

    if(s.searchMatrix(matrix, target)){
        cout << "Found\n";
    } else {
        cout << "Not Found\n";
    }
    return 0;
}
