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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, total = 0;
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* res = new ListNode(0);
        ListNode* r = res;

        while (p || q || carry) {
            total = carry;
            
            if (p) {
                total += p->val;
                p = p->next;
            }
            if (q) {
                total += q->val;
                q = q->next;
            }

            carry = total / 10;
            total = total % 10;
            r->next = new ListNode(total);
            r = r->next;
        }
        return res->next;
    }
};

// Function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Function to create a linked list from a vector of digits
ListNode* createList(const vector<int>& digits) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    for (int digit : digits) {
        current->next = new ListNode(digit);
        current = current->next;
    }
    return dummy->next;
}

int main() {
    // Example: l1 = [2,4,3] (342), l2 = [5,6,4] (465)
    vector<int> num1 = {2, 4, 3}; // Represents 342
    vector<int> num2 = {5, 6, 4}; // Represents 465

    ListNode* l1 = createList(num1);
    ListNode* l2 = createList(num2);

    cout << "First Number: ";
    printList(l1);

    cout << "Second Number: ";
    printList(l2);

    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);

    cout << "Sum: ";
    printList(result); // Output should be [7,0,8] which represents 807

    return 0;
}