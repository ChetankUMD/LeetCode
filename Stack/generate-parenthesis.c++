#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void generateParenthesisHelper(int open, int close, string current, vector<string>& result) {
        if (open == 0 && close == 0) {
            result.push_back(current);
            return;
        }

        if (open > 0) {
            generateParenthesisHelper(open - 1, close, current + "(", result);
        }
        if (close > open) {
            generateParenthesisHelper(open, close - 1, current + ")", result);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateParenthesisHelper(n, n, "", result);
        return result;
    }
};

int main() {
    Solution solution;
    int n = 3; // Example input; you can change this value as needed
    vector<string> result = solution.generateParenthesis(n);

    // Print the result
    cout << "Generated Parentheses for n = " << n << ":\n";
    for (const string& s : result) {
        cout << s << endl;
    }

    return 0;
}
