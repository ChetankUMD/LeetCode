#include <iostream>
#include <unordered_map>
using namespace std;

// Definition of Node for Doubly Linked List
class Node {
public:
    int key_node;
    int val_node;
    Node* next;
    Node* prev;

    Node(int k, int v) : key_node(k), val_node(v), next(nullptr), prev(nullptr) {}
};

// LRU Cache Class
class LRUCache {
private:
    int cap; // Capacity of cache
    unordered_map<int, Node*> map; // Hash map for quick lookup
    Node* left;  // Least Recently Used (LRU) sentinel
    Node* right; // Most Recently Used (MRU) sentinel

    // Remove a node from the doubly linked list
    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    // Insert a node at the MRU position (before right sentinel)
    void insert(Node* node) {
        Node* mru = right->prev;
        mru->next = node;
        right->prev = node;
        node->next = right;
        node->prev = mru;
    }

public:
    // Constructor initializes the cache with a given capacity
    LRUCache(int capacity) : cap(capacity) {
        left = new Node(0, 0);  // Dummy head (LRU side)
        right = new Node(0, 0); // Dummy tail (MRU side)
        left->next = right;
        right->prev = left;
    }
    
    // Get the value of the key if present, otherwise return -1
    int get(int key) {
        if (map.find(key) != map.end()) {
            Node* node = map[key];
            remove(node);  // Remove from current position
            insert(node);  // Move to MRU position
            return node->val_node;
        }
        return -1;
    }
    
    // Insert or update the value of the key in the cache
    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            remove(map[key]); // Remove existing node
        }
        map[key] = new Node(key, value); // Create new node
        insert(map[key]); // Insert at MRU position

        if (map.size() > cap) { // If cache exceeds capacity, remove LRU node
            Node* lru = left->next; // LRU is the first real node
            remove(lru);
            map.erase(lru->key_node);
            delete lru;
        }
    }

    // Destructor to free memory
    ~LRUCache() {
        Node* curr = left;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};

// Function to test the LRUCache implementation
int main() {
    LRUCache cache(2); // Capacity of 2

    cache.put(1, 10);
    cache.put(2, 20);
    cout << "Get(1): " << cache.get(1) << endl; // Returns 10

    cache.put(3, 30); // Removes key 2 since capacity is exceeded
    cout << "Get(2): " << cache.get(2) << endl; // Returns -1 (not found)

    cache.put(4, 40); // Removes key 1
    cout << "Get(1): " << cache.get(1) << endl; // Returns -1 (not found)
    cout << "Get(3): " << cache.get(3) << endl; // Returns 30
    cout << "Get(4): " << cache.get(4) << endl; // Returns is 40

    return 0;
}