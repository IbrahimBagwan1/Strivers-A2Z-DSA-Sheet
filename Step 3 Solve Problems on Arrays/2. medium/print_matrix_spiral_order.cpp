#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int z= matrix.size();
    int col_y= matrix[0].size();
    int minr=0;
    int minc=0;
    int maxr=z-1;
    int maxc=col_y-1;
    int tne= z*col_y;
    int count=0;
    vector<int> v;
    while(minr<=maxr && minc<=maxc){
      for(int j=minc; j<=maxc  && count<tne; j++){
        v.push_back(matrix[minr][j]);
        count++;
      }
      minr++;
      for(int k=minr; k<=maxr && count<tne; k++){
        v.push_back(matrix[k][maxc]);
        count++;
      }
      maxc--;

      for(int l=maxc; l>=minc && count<tne; l--){
        v.push_back(matrix[maxr][l]);
        count++;
      }
      maxr--;

      for(int m=maxr; m>=minr && count<tne; m--){
        v.push_back(matrix[m][minc]);
        count++;
      }
      minc++;
    }
    return v;
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> matrix(n, vector<int>(m));
  for(int i=0; i<n; ++i) {
    for(int j=0; j<m; ++j) {
      cin >> matrix[i][j];
    }
  }
  Solution sol;
  vector<int> result = sol.spiralOrder(matrix);
  for(int x : result) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}