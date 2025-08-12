#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b){
  int temp=a;
  a=b;
  b=temp;
}

// Function to reverse the array 
void reverseArray(vector<int>& arr, int start, int end){
  if(start >= end) return ;
  swap(arr[start], arr[end]);
  start++;
  end--;
  reverseArray(arr, start, end);
}

// Function to print the array
void printArray(const vector<int>& arr) {
  for (int num : arr) {
    cout << num << " ";
  }
  cout << endl;
}

// Main function
int main() {
  int n;
  cout << "Enter size of array: ";
  cin >> n;
  vector<int> arr(n);
  cout << "Enter array elements: ";
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  // Call reverseArray (logic to be implemented)
  reverseArray(arr, 0, n - 1);

  cout << "Reversed array: ";
  printArray(arr);

  return 0;
}