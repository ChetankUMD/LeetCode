#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool terminal = false;
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        auto p = root;
        for (int i = 0; i < word.size(); i++) {
            auto it = p->children.find(word[i]);
            if (it == p->children.end()) {
                p->children[word[i]] = new TrieNode();
            }
            p = p->children[word[i]];
        }
        p->terminal = true;
    }
    
    bool search(string word) {
        auto p = root;
        for (auto c : word) {
            if (p->children.find(c) == p->children.end()) {
                return false;
            }
            p = p->children[c];
        }
        return p->terminal;
    }
    
    bool startsWith(string prefix) {
        auto p = root;
        for (auto c : prefix) {
            if (p->children.find(c) == p->children.end()) {
                return false;
            }
            p = p->children[c];
        }
        return true;
    }
};

int main() {
    Trie trie;
    
    trie.insert("apple");
    trie.insert("app");
    trie.insert("application");

    cout << boolalpha; // to print 'true'/'false' instead of '1'/'0'
    
    cout << "Search 'apple': " << trie.search("apple") << endl;       // true
    cout << "Search 'app': " << trie.search("app") << endl;            // true
    cout << "Search 'appl': " << trie.search("appl") << endl;          // false
    cout << "Starts with 'appl': " << trie.startsWith("appl") << endl; // true
    cout << "Starts with 'banana': " << trie.startsWith("banana") << endl; // false
    
    return 0;
}