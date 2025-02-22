#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* p = head;
        ListNode* q = head;
        
        if (!head || head->next == NULL) {
            return false;
        }

        do {
            p = p->next;  // Slow pointer moves one step
            q = q->next;
            q = (q != NULL) ? q->next : NULL;  // Fast pointer moves two steps
        } while (p && q && p != q);

        return (p == q);
    }
};

// Function to create a linked list from an array
ListNode* createList(int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < n; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Function to print linked list (for debugging, not needed for cycle detection)
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Function to create a cycle in the linked list at a given position
void createCycle(ListNode* head, int pos) {
    if (pos == -1) return; // No cycle

    ListNode* temp = head;
    ListNode* cycleNode = NULL;
    int count = 0;

    while (temp->next) {
        if (count == pos) {
            cycleNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = cycleNode; // Creating the cycle
}

int main() {
    int arr[] = {3, 2, 0, -4}; // Example list
    int n = sizeof(arr) / sizeof(arr[0]);

    // Create linked list
    ListNode* head = createList(arr, n);

    // Create a cycle at position 1 (0-based index)
    createCycle(head, 1);

    // Check for cycle
    Solution sol;
    bool cycleExists = sol.hasCycle(head);

    // Print result
    if (cycleExists) {
        cout << "The linked list has a cycle." << endl;
    } else {
        cout << "The linked list does NOT have a cycle." << endl;
    }

    return 0;
}