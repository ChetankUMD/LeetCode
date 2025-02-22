#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return; // Edge case handling

        // Step 1: Find the middle of the list
        ListNode* mid = head, *mid_prev = NULL, *fast = head;
        while (fast && fast->next) {
            mid_prev = mid;
            mid = mid->next;
            fast = fast->next->next;
        }
        mid_prev->next = NULL;  // Split the list into two halves

        // Step 2: Reverse the second half
        ListNode* prev = NULL, *curr = mid, *next = NULL;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        mid = prev; // New head of reversed second half

        // Step 3: Merge two halves alternatively
        ListNode* first = head;
        ListNode* temp1 = NULL, *temp2 = NULL;
        while (first && mid) {
            temp1 = first->next;
            temp2 = mid->next;
            first->next = mid;
            if (temp1) mid->next = temp1;
            first = temp1;
            mid = temp2;
        }
    }
};

// Function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Function to create a linked list from an array
ListNode* createList(int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5}; // Example input list
    int size = sizeof(arr) / sizeof(arr[0]);

    ListNode* head = createList(arr, size);
    
    cout << "Original List: ";
    printList(head);

    Solution sol;
    sol.reorderList(head);

    cout << "Reordered List: ";
    printList(head);

    return 0;
}