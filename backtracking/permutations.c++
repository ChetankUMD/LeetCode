#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> res; // Stores all the generated permutations
public:

    // Public function to initiate backtracking
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> path;                     // Current permutation path
        vector<bool> pick(nums.size(), false); // Track which elements are used
        dfs(path, nums, pick);                // Start backtracking
        return res;
    }

private:
    // Recursive backtracking function
    void dfs(vector<int>& path, vector<int>& nums, vector<bool>& pick) {
        // Base case: if current path has all elements, it's a valid permutation
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        // Try each unused number at this position
        for (int i = 0; i < nums.size(); i++) {
            if (!pick[i]) {  // If nums[i] is not already used
                path.push_back(nums[i]);  // Choose nums[i]
                pick[i] = true;           // Mark it as used

                dfs(path, nums, pick);    // Recurse to fill the next position

                path.pop_back();          // Backtrack: remove last added number
                pick[i] = false;          // Mark nums[i] as unused for next choices
            }
        }
    }
};

// Helper function to print the 2D result
void printResult(const vector<vector<int>>& res) {
    for (const auto& permutation : res) {
        cout << "[ ";
        for (int num : permutation) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
}

// Main function to test the permutation generation
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3}; // Input array

    // Generate all permutations
    vector<vector<int>> result = sol.permute(nums);

    // Print the result
    cout << "All permutations of [1, 2, 3] are:\n";
    printResult(result);

    return 0;
}