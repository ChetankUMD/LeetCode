#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    vector<vector<int>> res; // To store all unique subsets
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> path; // Current subset being built
        sort(nums.begin(), nums.end()); // Sort to handle duplicates
        dfs(0, path, nums);
        return res;
    }

private:
    // Backtracking function
    void dfs(int index, vector<int>& path, vector<int>& nums) {
        // Save the current subset
        res.push_back(path);

        // Try adding each element starting from index
        for (int i = index; i < nums.size(); ++i) {
            // Skip duplicates at the same tree level
            if (i > index && nums[i] == nums[i - 1]) continue;

            path.push_back(nums[i]);        // Choose nums[i]
            dfs(i + 1, path, nums);         // Recurse to next element
            path.pop_back();                // Backtrack
        }
    }
};

// Helper function to print 2D vector
void printResult(const vector<vector<int>>& res) {
    for (const auto& subset : res) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
}

// Main function to test the subset generator
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 2}; // Test input with duplicates

    vector<vector<int>> result = sol.subsetsWithDup(nums);

    cout << "Unique subsets:\n";
    printResult(result);

    return 0;
}