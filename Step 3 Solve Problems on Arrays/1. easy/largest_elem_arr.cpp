#include <iostream>
#include <vector>
using namespace std;

class ArrayOperations {
private:
  vector<int> arr;
public:
  void inputArray(int n) {
    arr.resize(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }
  }

  // You write the core logic here
  int findLargest() {
    // TODO: the logic to find largest element in arr
    int n = arr.size();
    int max =-1;
    for(int i=0; i<n; i++){
      if(max < arr[i]){
        max = arr[i];
      }
    }
    return max;
  }

  void displayLargest() {
    int largest = findLargest();
    cout << "Largest element in the array: " << largest << endl;
  }
};

int main() {
  int n;
  cout << "Enter size of array: ";
  cin >> n;

  ArrayOperations ao;
  ao.inputArray(n);
  ao.displayLargest();

  return 0;
}
