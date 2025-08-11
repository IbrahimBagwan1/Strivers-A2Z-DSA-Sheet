/*
  C++ STL Cheat Sheet
  -------------------
  Short and concise notes on Standard Template Library (STL) in C++.
  Covers containers, iterators, algorithms, functors, syntax, and examples.
*/

// ===============================
// What is Standard Template Library(STL)?
// ===============================
// STL is a collection of generic class and function templates for common data structures and algorithms.
// Includes containers (vector, list, stack, queue, etc.), iterators, algorithms, and functors.

// ===============================
// Components of STL
// ===============================
// 1. Containers
// 2. Iterators
// 3. Algorithms
// 4. Functors

// ===============================
// STL Containers
// ===============================
// 1. Sequential Containers: vector, list, deque, array, forward_list
// 2. Container Adapters: stack, queue, priority_queue
// 3. Associative Containers: set, multiset, map, multimap
// 4. Unordered Containers: unordered_set, unordered_multiset, unordered_map, unordered_multimap

// ===============================
// 1.1 - STL Vector
// ===============================
#include <iostream>
#include <vector>
using namespace std;

void vector_example() {
  vector<int> v1 = { 1, 2, 3, 4, 5 };
  vector<vector<int>> v2(3, vector<int>(3, 5));
  v1.push_back(6);
  cout << "v1: ";
  for (int i = 0; i < v1.size(); i++) cout << v1[i] << " ";
  cout << endl;
  v1.erase(v1.begin() + 4);
  cout << "v1: ";
  for (auto i = v1.begin(); i != v1.end(); i++) cout << *i << " ";
  cout << endl;
  cout << "v2:-" << endl;
  for (auto i : v2) {
    for (auto j : i) cout << j << " ";
    cout << endl;
  }
}

// ===============================
// 1.2 - STL List
// ===============================
#include <list>
void list_example() {
  list<int> l1 = { 1, 5, 9, 1, 4, 6 };
  vector<char> v = { 'G', 'e', 'e', 'k', 's' };
  list<int> l2(v.begin(), v.end());
  cout << "First element of l1: " << l1.front() << endl;
  l1.insert(l1.begin(), 5);
  l1.erase(l1.begin());
  cout << "l1: ";
  for (auto i = l1.begin(); i != l1.end(); i++) cout << *i << " ";
  cout << endl;
  cout << "l2: ";
  for (auto i : l2) cout << char(i);
  cout << endl;
}

// ===============================
// 1.3 - STL Deque
// ===============================
#include <deque>
void deque_example() {
  deque<int> d = { 1, 2, 3, 4, 5 };
  d.push_front(d.back()); d.pop_back();
  d.push_front(d.back()); d.pop_back();
  for (auto i : d) cout << i << " ";
  cout << endl;
}

// ===============================
// 1.4 - STL Stack
// ===============================
#include <stack>
void stack_example() {
  stack<int> s;
  for (int i = 1; i <= 5; i++) s.push(i);
  s.push(6);
  cout << "s.top() = " << s.top() << endl;
  cout << "s: ";
  while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }
  cout << "Final Size: " << s.size() << endl;
}

// ===============================
// 1.5 - STL Queue
// ===============================
#include <queue>
void queue_example() {
  queue<int> q;
  for (int i = 1; i <= 5; i++) q.push(i);
  q.push(6);
  cout << "q.front() = " << q.front() << endl;
  cout << "q.back() = " << q.back() << endl;
  cout << "q: ";
  int size = q.size();
  for (int i = 0; i < size; i++) {
    cout << q.front() << " ";
    q.pop();
  }
  cout << endl;
}

// ===============================
// 1.6 - STL Set
// ===============================
#include <set>
void set_example() {
  vector<int> v = { 1, 5, 3, 4, 2 };
  set<int> s(v.begin(), v.end());
  if (s.find(4) == s.end()) cout << "4 not found" << endl;
  else cout << "4 found" << endl;
  s.insert(9);
  cout << "s: ";
  for (set<int>::iterator i = s.begin(); i != s.end(); i++) cout << *i << " ";
  cout << endl;
}

// ===============================
// 1.7 - STL Map
// ===============================
#include <map>
void map_example() {
  map<int, string> m;
  m[1] = "ONE"; m[2] = "TWO"; m[3] = "THREE";
  cout << "Size of map m: " << m.size() << endl;
  m.insert({ 4, "FOUR" });
  m.erase(2);
  cout << "Map:-" << endl;
  for (auto i : m) {
    cout << "Key: " << i.first << "\tValue: " << i.second << endl;
  }
}

// ===============================
// 1.8 - STL Unordered_set
// ===============================
#include <unordered_set>
void unordered_set_example() {
  unordered_set<int> us = { 1, 5, 2, 3, 4 };
  cout << "Size of us: " << us.size() << endl;
  us.insert(7);
  if (us.find(3) != us.end()) cout << "3 found!" << endl;
  else cout << "3 not found" << endl;
  cout << "us: ";
  for (auto i = us.begin(); i != us.end(); i++) cout << *i << " ";
  cout << endl;
}

// ===============================
// 1.9 - STL Unordered_map
// ===============================
#include <unordered_map>
void unordered_map_example() {
  unordered_map<int, string> umap;
  umap[1] = "ONE"; umap[2] = "TWO"; umap[3] = "THREE";
  umap.insert({ 4, "FOUR" });
  if (umap.find(12) != umap.end()) cout << "Key 12 Found!" << endl;
  else cout << "Key 12 Not Found!" << endl;
  cout << "umap:--" << endl;
  for (auto i = umap.begin(); i != umap.end(); i++)
    cout << "Key:" << i->first << "\tValue: " << i->second << endl;
}

// ===============================
// STL Iterators
// ===============================
// Types: Input Iterator, Output Iterator, Forward Iterator, Bi-Directional Iterator, Random Access Iterator

// ===============================
// STL Algorithms
// ===============================
#include <algorithm>
#include <iterator>
#include <sstream>
void algorithms_example() {
  // 1. Sort
  int arr[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
  int n = sizeof(arr) / sizeof(arr[0]);
  sort(arr, arr + n);
  cout << "Array after sorting: ";
  for (int i = 0; i < n; ++i) cout << arr[i] << " ";
  cout << endl;

  // 2. Copy
  vector<int> v = { 1, 2, 3, 4, 5 };
  cout << "Copy vector: ";
  copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
  cout << endl;

  // 3. Max Element
  vector<int> v2 = { 10, 88, 2, 9, 45, 82, 546, 42, 221 };
  auto max = max_element(begin(v2), end(v2));
  cout << "Maximum Element: " << *max << endl;

  // 4. Find
  vector<int> v3 = { 1, 8, 97, 3, 654, 132, 65, 4, 321, 5, 45 };
  auto itr = find(v3.begin(), v3.end(), 5);
  if (itr != v3.end()) cout << *itr << " is found!" << endl;
  else cout << "5 is not found!" << endl;

  // 5. For Each
  vector<int> v4 = { 1, 2, 3, 4, 5 };
  for_each(v4.begin(), v4.end(), [](int& i){ i = i + 1; });
  cout << "for_each vector: ";
  copy(v4.begin(), v4.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
}

// ===============================
// STL Function Objects (Functors)
// ===============================
#include <functional>
void functors_example() {
  equal_to<int> eq;
  not_equal_to<int> neq;
  greater<int> gt;
  less<int> ls;
  plus<int> p;
  minus<int> m;
  cout << "Functors and their return value\n";
  cout << boolalpha;
  cout << "equal_to, (10,20): " << eq(10, 20) << endl;
  cout << "greater, (10,20): " << gt(10, 20) << endl;
  cout << "less, (10,20): " << ls(10, 20) << endl;
  cout << "plus, (10,20): " << p(10, 20) << endl;
  cout << "minus(10,20): " << m(10, 20) << endl;
}

// ===============================
// Main function to run all examples
// ===============================
int main() {
  cout << "=== STL Vector Example ===\n"; vector_example();
  cout << "\n=== STL List Example ===\n"; list_example();
  cout << "\n=== STL Deque Example ===\n"; deque_example();
  cout << "\n=== STL Stack Example ===\n"; stack_example();
  cout << "\n=== STL Queue Example ===\n"; queue_example();
  cout << "\n=== STL Set Example ===\n"; set_example();
  cout << "\n=== STL Map Example ===\n"; map_example();
  cout << "\n=== STL Unordered_set Example ===\n"; unordered_set_example();
  cout << "\n=== STL Unordered_map Example ===\n"; unordered_map_example();
  cout << "\n=== STL Algorithms Example ===\n"; algorithms_example();
  cout << "\n=== STL Functors Example ===\n"; functors_example();
  return 0;
}
