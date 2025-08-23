#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        int i =0;
        int j = m-1;

        while(i<n && j>=0){
            if(matrix[i][j] == target) return true;
            else if(matrix[i][j] > target) j--;
            else i++;
        }

        return false;
    }
};

int main(){
    Solution s;
    vector<vector<int>> matrix = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}
    };
    int target = 5;

    if(s.searchMatrix(matrix, target)){
        cout << "Found\n";
    } else {
        cout << "Not Found\n";
    }
    return 0;
}
