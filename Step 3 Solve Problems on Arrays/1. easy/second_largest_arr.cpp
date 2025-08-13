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
    int n = arr.size();
    if(n<2) return -1;
    int first =INT_MIN;
    int second =0;
    for(int i=0; i<n; i++){
      if(arr[i] > first){
        second = first;
        first = arr[i];
      }
      else if(arr[i] > second && arr[i] != first){
        second = arr[i];
      }
    }
    return second;
  }

  void secondDisplayLargest() {
    int largest = findLargest();
    cout << "The Second Largest element in the array: " << largest << endl;
  }
};

int main() {
  int n;
  cout << "Enter size of array: ";
  cin >> n;

  ArrayOperations ao;
  ao.inputArray(n);
  ao.secondDisplayLargest();

  return 0;
}
