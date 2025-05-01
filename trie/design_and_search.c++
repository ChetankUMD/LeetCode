#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// Definition of a TrieNode
class TrieNode {
public:
    unordered_map<int, TrieNode*> children; // children nodes (key: character, value: next TrieNode)
    bool terminal = false; // true if a complete word ends at this node
};

class WordDictionary {
public:
    TrieNode* root;

    // Constructor initializes an empty root node
    WordDictionary() {
        root = new TrieNode;
    }
    
    // Function to add a word into the Trie
    void addWord(string word) {
        auto p = root;
        for (auto c : word) {
            // If the character doesn't exist in the current node's children, create a new node
            if (p->children.find(c) == p->children.end()) {
                p->children[c] = new TrieNode;
            }
            // Move to the child node corresponding to the current character
            p = p->children[c];
        }
        // After inserting all characters, mark the last node as terminal (end of a word)
        p->terminal = true;
    }
    
    // Function to search a word, which can include '.' wildcards
    bool search(string word) {
        return dfs(word, 0, root);
    }

private:
    // Helper DFS function to handle normal characters and '.' wildcards
    bool dfs(string word, int j, TrieNode* root) {
        TrieNode* p = root;
        for (int i = j; i < word.size(); i++) {
            char c = word[i];

            // If the current character is a '.', try all possible children
            if (c == '.') {
                for (auto& [key, child] : p->children) {
                    if (child != NULL && dfs(word, i + 1, child)) {
                        return true; // If any child path is valid, return true
                    }
                }
                return false; // If none matched, return false
            }
            else {
                // If the current character does not exist in children, word doesn't exist
                if (p->children.find(c) == p->children.end()) {
                    return false;
                }
            }
            // Move to the next node
            p = p->children[c];
        }

        // After processing all characters, check if current node marks the end of a word
        return p->terminal;
    }
};

// Sample main function to test the WordDictionary
int main() {
    WordDictionary wd;
    wd.addWord("bad");
    wd.addWord("dad");
    wd.addWord("mad");

    cout << boolalpha; // Print 'true' or 'false' instead of 1/0

    cout << "Search 'pad': " << wd.search("pad") << endl; // false
    cout << "Search 'bad': " << wd.search("bad") << endl; // true
    cout << "Search '.ad': " << wd.search(".ad") << endl; // true
    cout << "Search 'b..': " << wd.search("b..") << endl; // true

    return 0;
}