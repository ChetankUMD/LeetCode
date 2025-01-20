#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        // Map each number in mat to its position
        vector<pair<int, int>> pos(m * n + 1); // Using 1-based indexing
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                pos[mat[i][j]] = {i, j};
            }
        }
        // Arrays to track painted cells in rows and columns
        vector<int> rowCount(m, 0), colCount(n, 0);
        // Iterate through arr and update row/column counts
        for (int i = 0; i < arr.size(); ++i) {
            auto [r, c] = pos[arr[i]];
            if (++rowCount[r] == n || ++colCount[c] == m) {
                return i; // Return the first index completing a row or column
            }
        }

        return -1; // Should never be reached
    }
};

int main() {
    // Input values
    vector<int> arr = {2, 8, 7, 4, 1, 3, 5, 6, 9};
    vector<vector<int>> mat = {
        {3, 2, 5},
        {1, 4, 6},
        {8, 7, 9}
    };

    // Create a solution object
    Solution sol;
    // Get the result
    int result = sol.firstCompleteIndex(arr, mat);

    // Output the result
    cout << "The smallest index at which a row or column is fully painted: " << result << endl;

    return 0;
}
