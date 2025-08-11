// STL : Standard Template Library
// Types :
  // 1. Container
  // 2. Algorithm
  // 3. Iterators
  // 4. Functors

#include<bits/stdc++.h>
using namespace std;

// Pair
pair<int,int> p;

// vector
// C++ program to illustrate the vector container

void vect()
{
    // 1d vector with initialization list
    vector<int> v1 = { 1, 2, 3, 4, 5 };
    // 2d vector with size and element value initialization
    vector<vector<int> > v2(3, vector<int>(3, 5));

    // adding values using push_back()
    v1.push_back(6);
    // printing v1 using size()
    cout << "v1: ";
    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i] << " ";
    }
    cout << endl;

    vector<int>::iterator it = v1.begin();
    it++;
    cout<<*(it);

    v1.erase(v1.begin() + 4);
    // printing v1 using iterators
    cout << "v1: ";
    for (auto i = v1.begin(); i != v1.end(); i++) {
        cout << *i << " ";
    }

    // printing v2 using range based for loop
    cout << "v2:-" << endl;
    for (auto i : v2) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}

// list : the difference to vector is that it allows to push at front also the only difference
#include<list>
void list_example(){
  list<int> li;
  li.push_back(3);
  li.push_back(2);
  li.push_front(1);
  li.push_front(0);
}

// dequeue : similar to list and vector, all operations are generally same
void dequeue_example(){
  deque<int> d;
  d.push_back(2);
  d.push_front(1);
  d.pop_back();
  d.pop_front();
}

// stack
#include<stack>
void stack_example(){
  stack<int> st;
  st.push(44);
  st.size();
  st.top();
  st.pop();
}


// Queue
// #include<queue>
void queue_example(){
  queue<int> q;
  q.push(10);
  q.front();
  q.back();
  q.pop();
}

// priority Queue
void priority_queue(){
  priority_queue<int> pq; // Maxheap
  pq.push(10);
  pq.back();
  pq.top();
  
  priority_queue<int, vector<int> greater<int>> minheap; // this is MinHeap

}

// set
#include<set>
void set_example(){
  set<int> st;
  st.insert(22);
  st.insert(21);
  st.insert(23);
  st.insert(24);

  st.count(22); 
  auto it1 = st.find(21);
  auto it2 = st.find(23);
  st.erase(it1, it2);
  st.erase(st.begin(), st.end());
}


// unordered Set : similar to set, but the only thing is it is not sorted.
void unordered_set_example(){
  unordered_set<int> s;
  s.insert(3);
  s.insert(4);
  s.insert(1);
  s.insert(2);
  
}


// Map
void map_example(){
  map<int, int> mp;
  mp[1] = 3;
  mp.emplace(3, 8);
  mp.insert({4, 2});

}


// unordered_Map
void unordered_map_example(){
  // only thing is, it is not sorted.
  unordered_map<int,int> mp;
  mp.insert({2,3});
}

// custom comparater

bool comp(pair<int,int> p1, pair<int,int> p2){
  if(p1.second < p2.second) return true;
  if(p1.second > p2.second) return false;

  if(p1.first > p2.first) return true;
  else return false;
  // this function helps to sort in increasing order of second element and if two second elements are same then it sorts in decreasing order with reference to the first element.
}

void algo(){
  int n =7;
  int cnt = __builtin_popcount(n);
  string s="123";
  cout<<next_permutation(s.begin(), s.end());

}

int main(){
  return 0;
}