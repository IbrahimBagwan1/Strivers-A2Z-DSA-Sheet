#include <iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
  int m = matrix.size();
  int n = matrix[0].size();
  vector<bool> row(m, false), col(n, false);

  // First pass: mark rows and columns that need to be zeroed
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (matrix[i][j] == 0) {
        row[i] = true;
        col[j] = true;
      }
    }
  }

  // Second pass: set zeroes
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (row[i] || col[j]) {
        matrix[i][j] = 0;
      }
    }
  }
}

int main() {
  int m, n;
  cout << "Enter number of rows and columns: ";
  cin >> m >> n;
  vector<vector<int>> matrix(m, vector<int>(n));
  cout << "Enter matrix elements:\n";
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> matrix[i][j];
    }
  }

  setZeroes(matrix);

  cout << "Matrix after setting zeroes:\n";
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}