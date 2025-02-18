#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;

        int l = 0, h = m - 1, mid = 0;

        // Binary search to find the correct row
        while (l <= h) {
            mid = l + (h - l) / 2;
            if (matrix[mid][0] <= target && target <= matrix[mid][n - 1]) {
                break; // Found the row where the target might exist
            }
            if (matrix[mid][0] > target) {
                h = mid - 1; // Move up
            } else {
                l = mid + 1; // Move down
            }
        }

        // If the row is not found, return false
        if (h < 0) return false;

        // Perform binary search in the identified row
        int row = mid;
        l = 0;
        h = n - 1;

        while (l <= h) {
            mid = l + (h - l) / 2;
            if (matrix[row][mid] == target) {
                return true; // Found the target
            }
            if (matrix[row][mid] > target) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return false; // Target not found
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target;
    cout << "Enter the number to search: ";
    cin >> target;

    bool found = sol.searchMatrix(matrix, target);
    cout << (found ? "Target found in matrix." : "Target not found.") << endl;

    return 0;
}