#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool checkRow(vector<vector<int>> &M, int idx){
        for(int i=0; i<M.size(); i++){
            if(M[idx][i]==1) return false;              // celebrity knows no one
            if(i != idx && M[i][idx]==0) return false; // everyone must know celebrity
        }
        return true;
    }

    int celebrity(vector<vector<int>> &M){
        int n = M.size();
        int down = n-1;
        int top = 0;
        while(top < down){
            if(M[top][down] == 0) down--;  // top doesn't know down → down not celeb
            else top++;                    // top knows down → top not celeb
        }
        return checkRow(M, top) ? top : -1;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> M = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };

    int celeb = sol.celebrity(M);

    if(celeb == -1) cout << "No celebrity\n";
    else cout << "Celebrity is person " << celeb << endl;

    return 0;
}
