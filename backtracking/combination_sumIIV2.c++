#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Main function to be called with input candidates and target
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;   // Stores the final result (all unique combinations)
        vector<int> cur;           // Current path/combination being built

        // Step 1: Sort the candidates to handle duplicates and enable early stopping
        sort(candidates.begin(), candidates.end());

        // Step 2: Begin DFS/backtracking from index 0, with sum = 0
        dfs(0, res, 0, cur, candidates, target);
        return res;
    }

private:
    // Recursive DFS function
    void dfs(int idx, vector<vector<int>>& res, int sum, vector<int> cur, vector<int>& nums, int target) {
        // Base case: if current sum equals target, we found a valid combination
        if (sum == target) {
            res.push_back(cur);
            return;
        }

        // Traverse the candidates starting from index `idx`
        for (int i = idx; i < nums.size(); i++) {
            // Skip duplicates: if current number is same as previous at same depth, skip it
            if (i > idx && nums[i] == nums[i - 1]) {
                continue;
            }

            // Early stopping: since array is sorted, no point in continuing if sum exceeds target
            if (sum + nums[i] > target) {
                break;
            }

            // Include nums[i] in the current combination
            cur.push_back(nums[i]);

            // Recur with next index (i + 1) because each number can be used at most once
            dfs(i + 1, res, sum + nums[i], cur, nums, target);

            // Backtrack: remove last element to try the next candidate
            cur.pop_back();
        }
    }
};

// Helper function to print result
void printResult(const vector<vector<int>>& res) {
    for (const auto& comb : res) {
        cout << "[ ";
        for (int num : comb) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
}

// Main function for testing
int main() {
    Solution solution;

    // Test input
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    // Call the function
    vector<vector<int>> result = solution.combinationSum2(candidates, target);

    // Print the result
    cout << "Unique combinations that sum to " << target << ":\n";
    printResult(result);

    return 0;
}