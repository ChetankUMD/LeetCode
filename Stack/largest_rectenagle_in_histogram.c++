#include <iostream>
#include <vector>
#include <stack>
#include <algorithm> // For max function

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<pair<int, int>> stack; // pair: (index, height)

        for (int i = 0; i < heights.size(); i++) {
            int start = i;
            while (!stack.empty() && stack.top().second > heights[i]) {
                pair<int, int> top = stack.top();
                int index = top.first;
                int height = top.second;
                maxArea = max(maxArea, height * (i - index));
                start = index;
                stack.pop();
            }
            stack.push({ start, heights[i] });
        }

        while (!stack.empty()) {
            int index = stack.top().first;
            int height = stack.top().second;
            maxArea = max(maxArea, height * (static_cast<int>(heights.size()) - index));
            stack.pop();
        }

        return maxArea;
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<int> heights1 = {2, 1, 5, 6, 2, 3};
    cout << "Example 1: " << endl;
    cout << "Input: heights = [2, 1, 5, 6, 2, 3]" << endl;
    cout << "Output: " << solution.largestRectangleArea(heights1) << endl;
    
    // Example 2
    vector<int> heights2 = {2, 4};
    cout << "\nExample 2: " << endl;
    cout << "Input: heights = [2, 4]" << endl;
    cout << "Output: " << solution.largestRectangleArea(heights2) << endl;

    // Additional test cases
    vector<int> heights3 = {0, 0, 0, 0};
    cout << "\nAdditional Test Case 1: " << endl;
    cout << "Input: heights = [0, 0, 0, 0]" << endl;
    cout << "Output: " << solution.largestRectangleArea(heights3) << endl;

    vector<int> heights4 = {6, 2, 5, 4, 5, 1, 6};
    cout << "\nAdditional Test Case 2: " << endl;
    cout << "Input: heights = [6, 2, 5, 4, 5, 1, 6]" << endl;
    cout << "Output: " << solution.largestRectangleArea(heights4) << endl;

    return 0;
}
