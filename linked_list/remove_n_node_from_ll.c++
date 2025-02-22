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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node that points to the head (to handle edge cases like removing the first node)
        ListNode *res = new ListNode(0, head);
        ListNode *dummy = res;

        // Move the head pointer 'n' steps forward
        for (int i = 0; i < n; i++) {
            head = head->next;
        }

        // Move both head and dummy forward until head reaches NULL
        while (head != NULL) {
            head = head->next;
            dummy = dummy->next;
        }

        // Remove the N-th node from the end
        dummy->next = dummy->next->next;

        // Return the modified list (skipping the dummy node)
        return res->next;
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
    if (size == 0) return nullptr;  // Handle empty list case
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    // Example test cases
    int arr1[] = {1};  // Case: Single element
    int arr2[] = {1, 2};  // Case: Two elements
    int arr3[] = {1, 2, 3, 4, 5};  // Case: Multiple elements

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int size3 = sizeof(arr3) / sizeof(arr3[0]);

    // Create linked lists
    ListNode* head1 = createList(arr1, size1);
    ListNode* head2 = createList(arr2, size2);
    ListNode* head3 = createList(arr3, size3);

    // Print original lists
    cout << "Original List 1: ";
    printList(head1);
    cout << "Original List 2: ";
    printList(head2);
    cout << "Original List 3: ";
    printList(head3);

    // Create Solution object
    Solution sol;

    // Remove N-th node from end
    head1 = sol.removeNthFromEnd(head1, 1);
    head2 = sol.removeNthFromEnd(head2, 1);
    head3 = sol.removeNthFromEnd(head3, 2);

    // Print modified lists
    cout << "Updated List 1 (n=1): ";
    printList(head1);
    cout << "Updated List 2 (n=1): ";
    printList(head2);
    cout << "Updated List 3 (n=2): ";
    printList(head3);

    return 0;
}