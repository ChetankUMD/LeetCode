#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<int> conRow(m, 0);
        vector<int> conCol(n, 0);

        // Count the number of servers in each row and column
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    conRow[i]++;
                    conCol[j]++;
                }
            }
        }

        // Check if a server can communicate with others
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && (conRow[i] > 1 || conCol[j] > 1)) {
                    res++;
                }
            }
        }

        return res;

                // int res = 0;
        // int m = grid.size();
        // int n = grid[0].size();
        // vector<vector<bool>> v(m, vector<bool>(n,false));

        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(grid[i][j] == 1){
        //             for(int row = 0; row < m;row++){
        //                 if(row != i) v[row][j] = true;
        //             }
        //             for(int col = 0; col < n;col++){
        //                 if(col != j) v[i][col] = true;
        //             }
        //         }
        //     }
        // }

        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(grid[i][j] == 1 and v[i][j] == true){
        //             res++;
        //         }
        //     }
        // }

        // return res;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<vector<int>> grid1 = {{1, 0}, {0, 1}};
    cout << "Output for grid1: " << solution.countServers(grid1) << endl;

    // Test case 2
    vector<vector<int>> grid2 = {{1, 0}, {1, 1}};
    cout << "Output for grid2: " << solution.countServers(grid2) << endl;

    // Test case 3
    vector<vector<int>> grid3 = {{1, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
    cout << "Output for grid3: " << solution.countServers(grid3) << endl;

    return 0;
}
