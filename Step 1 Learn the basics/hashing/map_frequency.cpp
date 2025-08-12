#include <iostream>
#include <unordered_map>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
  // Example input
  vector<int> arr = {1, 2, 2, 3, 1, 4, 2, 3};

  // Frequency map
  map<int, int> freq;

  // Count frequencies
  for (int num : arr) {
    freq[num]++;
  }

  // Print frequencies
  cout << "Element : Frequency\n";
  for (auto pair : freq) {
    std::cout << pair.first << " : " << pair.second << "\n";
  }

  return 0;
}