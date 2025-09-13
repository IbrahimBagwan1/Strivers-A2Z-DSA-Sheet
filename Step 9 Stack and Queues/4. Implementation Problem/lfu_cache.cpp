#include <bits/stdc++.h>
using namespace std;

class LFUCache {
public:
    struct Node {
        int key, value, freq;
        Node(int k, int v, int f=1) : key(k), value(v), freq(f) {}
    };

    int capacity, minFreq;
    unordered_map<int, list<Node>> freqList;      // freq -> list of nodes
    unordered_map<int, list<Node>::iterator> keyNode; // key -> node iterator

    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (capacity == 0 || keyNode.find(key) == keyNode.end())
            return -1;

        auto it = keyNode[key];
        int val = it->value;
        int freq = it->freq;

        // remove from old freq list
        freqList[freq].erase(it);
        if (freqList[freq].empty()) {
            freqList.erase(freq);
            if (minFreq == freq) minFreq++;
        }

        // insert into higher freq list
        freqList[freq+1].push_front(Node(key, val, freq+1));
        keyNode[key] = freqList[freq+1].begin();

        return val;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        // if key already exists, update and increase freq
        if (keyNode.find(key) != keyNode.end()) {
            auto it = keyNode[key];
            it->value = value;
            get(key); // update frequency
            return;
        }

        // if at capacity, evict LFU
        if ((int)keyNode.size() == capacity) {
            auto it = freqList[minFreq].back();
            int oldKey = it.key;
            freqList[minFreq].pop_back();
            if (freqList[minFreq].empty())
                freqList.erase(minFreq);
            keyNode.erase(oldKey);
        }

        // insert new node with freq=1
        freqList[1].push_front(Node(key, value, 1));
        keyNode[key] = freqList[1].begin();
        minFreq = 1;
    }
};
int main() {
    LFUCache cache(2);

    cache.put(1, 10);
    cache.put(2, 20);
    cout << cache.get(1) << endl; // 10 (freq of 1 increases)
    cache.put(3, 30);             // evicts key 2 (LFU)
    cout << cache.get(2) << endl; // -1
    cout << cache.get(3) << endl; // 30
    cout << cache.get(1) << endl; // 10
}
