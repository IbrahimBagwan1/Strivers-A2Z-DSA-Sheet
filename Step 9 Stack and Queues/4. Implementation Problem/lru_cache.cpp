#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    struct ListNode {
        ListNode* next;
        ListNode* prev;
        int key, value;
        ListNode(int k=0, int v=0) : key(k), value(v), next(NULL), prev(NULL) {}
    };

    int capacity;
    map<int, ListNode*> mp;
    ListNode* head;
    ListNode* tail;

    LRUCache(int capa) {
        capacity = capa;
        head = new ListNode();
        tail = new ListNode();
        head->next = tail;
        head->prev = NULL;
        tail->prev = head;
        tail->next = NULL;
    }

    void insertBegin(ListNode* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void deleteNode(ListNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        ListNode* node = mp[key];
        deleteNode(node);
        insertBegin(node);
        return node->value;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            ListNode* node = mp[key];
            node->value = value;
            deleteNode(node);
            insertBegin(node);
        } else {
            if (mp.size() == capacity) {
                ListNode* lru = tail->prev;
                mp.erase(lru->key);
                deleteNode(lru);
                lru->key = key;
                lru->value = value;
                insertBegin(lru);
                mp[key] = lru;
            } else {
                ListNode* node = new ListNode(key, value);
                insertBegin(node);
                mp[key] = node;
            }
        }
    }
};


// Example usage
int main() {
    LRUCache lru(2);
    lru.put(1, 10);
    lru.put(2, 20);
    cout << lru.get(1) << endl; // 10
    lru.put(3, 30);             // evicts key 2
    cout << lru.get(2) << endl; // -1
    lru.put(4, 40);             // evicts key 1
    cout << lru.get(1) << endl; // -1
    cout << lru.get(3) << endl; // 30
    cout << lru.get(4) << endl; // 40
}
