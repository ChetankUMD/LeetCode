#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (int i = 0; i < tokens.size(); i++) {
            // If the token is an operator
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int a = stk.top(); // Top of the stack is the right operand
                stk.pop();
                int b = stk.top(); // Next top is the left operand
                stk.pop();
                if (tokens[i] == "+") stk.push(b + a);
                else if (tokens[i] == "-") stk.push(b - a);
                else if (tokens[i] == "*") stk.push(b * a);
                else if (tokens[i] == "/") stk.push(b / a); // Ensure no division by zero (not needed here as per constraints)
            } else {
                // If the token is a number, push it onto the stack
                stk.push(stoi(tokens[i]));
            }
        }
        return stk.top(); // The final result is at the top of the stack
    }
};

// Main function to demonstrate the usage
int main() {
    Solution sol;

    vector<string> tokens1 = {"2", "1", "+", "3", "*"};
    cout << "Result: " << sol.evalRPN(tokens1) << endl; // Output: 9

    vector<string> tokens2 = {"4", "13", "5", "/", "+"};
    cout << "Result: " << sol.evalRPN(tokens2) << endl; // Output: 6

    vector<string> tokens3 = {"10", "6", "9", "3", "/", "*", "11", "+", "-"};
    cout << "Result: " << sol.evalRPN(tokens3) << endl; // Output: 25

    return 0;
}
