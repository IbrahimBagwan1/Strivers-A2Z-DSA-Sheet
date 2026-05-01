#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node* links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;

    Node() {
        for(int i = 0; i < 26; i++) links[i] = NULL;
    }

    bool containsKey(char ch){
        return links[ch-'a']!=NULL ;
    }

    Node* getKey(char ch){
        return links[ch-'a'];
    }

    void addKey(char ch, Node* node){
        links[ch-'a'] = node;
    }

    void increaseEnd(){
        cntEndWith++;
    }

    void increasePrefix(){
        cntPrefix++;
    }

    void deleteEnd(){
        cntEndWith--;
    }

    void reducePrefix(){
        cntPrefix--;
    }

    int getEnd(){
        return cntEndWith;
    }

    int getPrefix(){
        return cntPrefix;
    }
};

class Trie {
private: 
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;

        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                node->addKey(word[i], new Node());
            }
            node = node->getKey(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string word) {
        Node* node = root;

        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                return 0;
            }
            node = node->getKey(word[i]);
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string word) {
        Node* node = root;

        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                return 0;
            }
            node = node->getKey(word[i]);
        }
        return node->getPrefix();
    }

    void erase(string word) {
        Node* node = root;

        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                return;
            }
            node = node->getKey(word[i]);
        }

        node = root;

        for(int i=0; i<word.size(); i++){
            node = node->getKey(word[i]);
            node->reducePrefix();
        }
        node->deleteEnd();
    }
};

int main() {
    Trie* obj = new Trie();

    obj->insert("apple");
    obj->insert("apple");
    obj->insert("app");

    cout << "Count 'apple': " << obj->countWordsEqualTo("apple") << endl;
    cout << "Count 'app': " << obj->countWordsEqualTo("app") << endl;
    cout << "Prefix 'app': " << obj->countWordsStartingWith("app") << endl;

    obj->erase("apple");

    cout << "After erase 'apple': " << endl;
    cout << "Count 'apple': " << obj->countWordsEqualTo("apple") << endl;
    cout << "Prefix 'app': " << obj->countWordsStartingWith("app") << endl;

    return 0;
}