#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false)); 
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; 

        pq.push({0, 0, 0}); // cost, row, column
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int cost = curr[0], i = curr[1], j = curr[2];

            if (visited[i][j]) continue;
            visited[i][j] = true;

            if (i == n - 1 && j == m - 1) return cost;

            for (int d = 0; d < 4; ++d) {
                int ni = i + directions[d].first;
                int nj = j + directions[d].second;

                if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                    int newCost = cost + (grid[i][j] != d + 1 ? 1 : 0); 
                    pq.push({newCost, ni, nj});
                }
            }
        }
        return -1; 
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<vector<int>> grid1 = {
        {1, 1, 1, 1},
        {2, 2, 2, 2},
        {1, 1, 1, 1},
        {2, 2, 2, 2}
    };
    cout << "Example 1 Output: " << solution.minCost(grid1) << endl;

    // Example 2
    vector<vector<int>> grid2 = {
        {1, 1, 3},
        {3, 2, 2},
        {1, 1, 4}
    };
    cout << "Example 2 Output: " << solution.minCost(grid2) << endl;

    // Example 3
    vector<vector<int>> grid3 = {
        {1, 2},
        {4, 3}
    };
    cout << "Example 3 Output: " << solution.minCost(grid3) << endl;

    return 0;
}
