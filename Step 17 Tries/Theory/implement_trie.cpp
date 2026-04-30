#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node *links[26];
    bool flag = false;

    bool containKey(char letter){
        return links[letter - 'a']!= NULL;
    }

    void setKey(char ch, Node* node){
        links[ch-'a'] = node;
    }

    Node* goNext(char ch){
        return links[ch-'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool retreiveEnd(){
        return flag;
    }
};

class Trie {
private: Node * root;
public:

    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node * node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containKey(word[i])){
                node->setKey(word[i], new Node());
            }
            node = node->goNext(word[i]);
        }   
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containKey(word[i])){
                return false;
            }
            node = node->goNext(word[i]);
        }
        return node->retreiveEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i=0; i<prefix.size(); i++){
            if(!node->containKey(prefix[i])){
                return false;
            }
            node = node->goNext(prefix[i]);
        }
        return true;
    }
};

int main() {
    Trie* obj = new Trie();

    obj->insert("apple");

    cout << "Search 'apple': " << (obj->search("apple") ? "true" : "false") << endl;
    cout << "Search 'app': " << (obj->search("app") ? "true" : "false") << endl;
    cout << "StartsWith 'app': " << (obj->startsWith("app") ? "true" : "false") << endl;

    obj->insert("app");

    cout << "Search 'app' after inserting: " << (obj->search("app") ? "true" : "false") << endl;

    return 0;
}