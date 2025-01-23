#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<pair<int, int>> q;
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> h(m, vector<int>(n, 0));
        vector<vector<bool>> v(m, vector<bool>(n, false));
        int level = 0;

        // Initialize the queue with water cells and mark them as visited
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    q.push(make_pair(i, j));
                    v[i][j] = true;
                }
            }
        }

        // Directions for moving up, right, down, left
        vector<int> dir = {-1, 0, 1, 0, -1};

        // BFS traversal
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                pair<int, int> curr = q.front();
                q.pop();

                int x = curr.first;
                int y = curr.second;

                for (int d = 0; d < 4; d++) {
                    int newX = x + dir[d];
                    int newY = y + dir[d + 1];

                    // Check if the new cell is within bounds and not visited
                    if (newX < m && newY < n && newX >= 0 && newY >= 0 && !v[newX][newY]) {
                        q.push(make_pair(newX, newY));
                        h[newX][newY] = 1 + level;
                        v[newX][newY] = true;
                    }
                }
            }
            level++;
        }

        return h;
    }
};

int main() {
    // Test case 1
    vector<vector<int>> isWater = {
        {0, 1},
        {0, 0}
    };

    Solution solution;
    vector<vector<int>> result = solution.highestPeak(isWater);

    // Print the result
    cout << "Resultant Heights Matrix:" << endl;
    for (const auto& row : result) {
        for (int height : row) {
            cout << height << " ";
        }
        cout << endl;
    }

    // Test case 2
    isWater = {
        {0, 0, 1},
        {1, 0, 0},
        {0, 0, 0}
    };

    result = solution.highestPeak(isWater);

    // Print the result
    cout << "Resultant Heights Matrix:" << endl;
    for (const auto& row : result) {
        for (int height : row) {
            cout << height << " ";
        }
        cout << endl;
    }

    return 0;
}
