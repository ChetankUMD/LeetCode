#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Main function to be called with input candidates and target
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;      // To store all unique combinations
        vector<int> cur;              // Temporary vector to hold current combination
        sort(candidates.begin(), candidates.end()); // Sort to handle duplicates properly
        dfs(0, res, cur, candidates, target);
        return res;
    }

private:
    // Recursive DFS function with backtracking
    void dfs(int i, vector<vector<int>>& res, vector<int> cur, vector<int>& nums, int target) {
        int sum = 0;
        for (int c : cur) {
            sum += c;  // Calculate sum of current combination
        }

        // If current sum matches the target, we found a valid combination
        if (sum == target) {
            res.push_back(cur);
            return;
        }

        // If sum exceeds target or we are out of bounds, return
        if (i >= nums.size() || sum > target) return;

        // ----- Include current number -----
        cur.push_back(nums[i]);
        dfs(i + 1, res, cur, nums, target); // Recurse with next index (no reuse allowed)
        cur.pop_back();                     // Backtrack

        // ----- Skip duplicates for exclusion path -----
        // Move index `i` forward while next value is the same to avoid duplicate combinations
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }

        // ----- Exclude current number -----
        dfs(i + 1, res, cur, nums, target); // Try without including nums[i]
    }
};

// ------------- Main function to test the code -------------
int main() {
    Solution sol;

    // Example input
    vector<int> candidates = {9, 2, 2, 4, 6, 1, 5};
    int target = 8;

    // Run the algorithm
    vector<vector<int>> results = sol.combinationSum2(candidates, target);

    // Print results
    cout << "Unique combinations that sum to " << target << ":\n";
    for (const auto& comb : results) {
        cout << "[ ";
        for (int num : comb) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}