#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Dummy node to mark start of merged list
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;

        // Merge two lists
        while (list1 && list2) {
            if (list1->val < list2->val) {
                cur->next = list1;
                list1 = list1->next;
            } else {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }

        // Attach the remaining part of the list (if any)
        cur->next = list1 ? list1 : list2;

        // Get the head of the merged list
        ListNode* head = dummy->next;
        delete dummy;  // Free memory allocated for dummy node
        return head;
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

// Function to print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Main function to test mergeTwoLists
int main() {
    int arr1[] = {1, 3, 5};  // First sorted list
    int arr2[] = {2, 4, 6};  // Second sorted list

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    // Create linked lists from arrays
    ListNode* list1 = createList(arr1, n1);
    ListNode* list2 = createList(arr2, n2);

    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);

    // Merge the two sorted lists
    Solution sol;
    ListNode* mergedList = sol.mergeTwoLists(list1, list2);

    cout << "Merged List: ";
    printList(mergedList);

    return 0;
}