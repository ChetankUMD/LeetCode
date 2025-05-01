#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Main function to initiate the combination sum search
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;  // To store all valid combinations
        vector<int> cur;          // Current combination being built
        dfs(0, res, cur, nums, target);
        return res;
    }

private:
    // Depth-first search to explore all combinations
    void dfs(int i, vector<vector<int>>& res, vector<int>& cur, vector<int>& nums, int target) {
        int sum = 0;
        for (int n : cur) {
            sum += n;  // Compute current sum of elements in the path
        }

        // If sum exceeds target or index is out of bounds, stop exploring this path
        if (i >= nums.size() || sum > target) {
            return;
        }

        // If current sum equals target, add this combination to result
        if (sum == target) {
            res.push_back(cur);
            return;
        }

        // Include current number and allow reuse (same index)
        cur.push_back(nums[i]);
        dfs(i, res, cur, nums, target);  // Recurse with same index
        cur.pop_back();  // Backtrack

        // Exclude current number and move to next index
        dfs(i + 1, res, cur, nums, target);
    }
};

// -------- Main Function to Test --------
int main() {
    vector<int> nums = {2, 3, 6, 7};  // Input candidates
    int target = 7;                   // Target sum to achieve

    Solution sol;
    vector<vector<int>> result = sol.combinationSum(nums, target);

    // Print result
    cout << "Combinations that sum to " << target << ":" << endl;
    for (const auto& comb : result) {
        cout << "[ ";
        for (int num : comb) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}