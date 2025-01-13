#include <iostream>
#include <stack>
using namespace std;

// MinStack Class Definition
class MinStack {
private:
    stack<int> mainStack;  // Stack to store all elements
    stack<int> minStack;   // Stack to store minimum elements

public:
    // Constructor to initialize the stack
    MinStack() {
    }
    
    // Push a value onto the stack
    void push(int val) {
        mainStack.push(val);  // Push the value to mainStack
        // Push to minStack if it's empty or val is smaller/equal to the current minimum
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }
    
    // Remove the top element from the stack
    void pop() {
        if (mainStack.empty()) return;  // If stack is empty, do nothing
        int val = mainStack.top();
        if (minStack.top() == val) {
            minStack.pop();  // Remove from minStack if it's the current minimum
        }
        mainStack.pop();
    }
    
    // Get the top element of the stack
    int top() {
        return mainStack.top();
    }
    
    // Retrieve the minimum element in the stack
    int getMin() {
        return minStack.top();
    }
};

// Main Function to Test MinStack
int main() {
    MinStack minStack;

    // Perform operations as in the example
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);

    cout << "getMin: " << minStack.getMin() << endl; // Output: -3
    minStack.pop();
    cout << "top: " << minStack.top() << endl;       // Output: 0
    cout << "getMin: " << minStack.getMin() << endl; // Output: -2

    return 0;
}
