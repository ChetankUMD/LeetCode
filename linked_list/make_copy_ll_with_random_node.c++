#include <iostream>
#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr; // Handle empty list case

        Node* p = head, *q = head;
        unordered_map<Node*, Node*> map;

        // Step 1: Create new nodes and store them in a hashmap
        while (p) {
            map[p] = new Node(p->val); // Create a copy node
            p = p->next;
        }

        // Step 2: Assign next and random pointers using the hashmap
        while (q) {
            map[q]->next = map[q->next];     // Set next pointer
            map[q]->random = map[q->random]; // Set random pointer
            q = q->next;
        }

        return map[head]; // Return the copied head
    }
};

// Function to print the list
void printList(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << "Value: " << curr->val;
        if (curr->random)
            cout << ", Random: " << curr->random->val;
        else
            cout << ", Random: NULL";
        cout << endl;
        curr = curr->next;
    }
}

int main() {
    // Step 1: Create an example linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    // Step 2: Assign random pointers
    head->random = head->next->next;       // 1 → 3
    head->next->random = head;             // 2 → 1
    head->next->next->random = head->next; // 3 → 2
    head->next->next->next->random = head; // 4 → 1

    // Step 3: Print original list
    cout << "Original List:\n";
    printList(head);

    // Step 4: Copy the list
    Solution solution;
    Node* copiedHead = solution.copyRandomList(head);

    // Step 5: Print copied list
    cout << "\nCopied List:\n";
    printList(copiedHead);

    return 0;
}