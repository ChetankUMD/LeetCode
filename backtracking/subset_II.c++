#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Main function to generate all subsets
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;  // Resultant vector of all subsets
        vector<int> cur;          // Current subset being constructed
        backtrack(0, nums, cur, res);  // Start backtracking from index 0
        return res;
    }

private:
    // Recursive backtracking function
    void backtrack(int i, vector<int>& nums, vector<int>& cur, vector<vector<int>>& res) {
        // Base case: if we've considered all elements
        if (i >= nums.size()) {
            res.push_back(cur);  // Add the current subset to the result
            return;
        }

        // Decision 1: exclude nums[i]
        backtrack(i + 1, nums, cur, res);

        // Decision 2: include nums[i]
        cur.push_back(nums[i]);
        backtrack(i + 1, nums, cur, res);
        cur.pop_back();  // Backtrack to explore other possibilities
    }
};

// -------- Main Function to Test --------
int main() {
    vector<int> nums = {1, 2, 3};  // Example input
    Solution sol;
    vector<vector<int>> result = sol.subsets(nums);

    // Print the result
    cout << "All subsets:" << endl;
    for (const auto& subset : result) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}