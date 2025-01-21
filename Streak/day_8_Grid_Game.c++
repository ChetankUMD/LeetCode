#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long> topPrefix(n, 0), bottomPrefix(n, 0);
        
        // Compute prefix sums for the top and bottom rows
        topPrefix[0] = grid[0][0];
        bottomPrefix[0] = grid[1][0];
        for (int i = 1; i < n; ++i) {
            topPrefix[i] = topPrefix[i - 1] + grid[0][i];
            bottomPrefix[i] = bottomPrefix[i - 1] + grid[1][i];
        }
        
        long long result = LLONG_MAX;
        for (int i = 0; i < n; ++i) {
            long long pointsTop = topPrefix[n - 1] - topPrefix[i];
            long long pointsBottom = (i > 0) ? bottomPrefix[i - 1] : 0;
            result = std::min(result, std::max(pointsTop, pointsBottom));
        }
        
        return result;
        // long long res =0;
        // int n = grid[0].size();
        // vector<vector<long long>> hash(2, vector<long long>(n, 0));
        // int flag =0;

        // for(int i =n-2; i>=0;--i){
        //     hash[0][i] = grid[0][i-1] + grid[0][i];
        //     hash[1][i] = grid[1][i-1] + grid[1][i];
        // }

        // for(int i=0;i<n-1;i++){
        //     if(flag == 1){
        //         grid[1][i] = 0;
        //         continue;
        //     }
        //     if(hash[0][i+1] > hash[1][i] && flag == 0){
        //         grid[0][i] = 0;
        //     }
        //     else{
        //         flag = 1;
        //         grid[0][i] = 0;
        //         grid[1][i] = 0;
        //     }
        // }
        // flag=0;
        // for(int i =n-2; i>=0;--i){
        //     hash[0][i] = grid[0][i-1] + grid[0][i];
        //     hash[1][i] = grid[1][i-1] + grid[1][i];
        // }

        // for(int i=0;i<n-1;i++){
        //     if(flag == 1){
        //         res += grid[1][i];
        //         continue;
        //     }
        //     if(hash[0][i+1] > hash[1][i] && flag == 0){
        //         res = res + grid[0][i];
        //     }
        //     else{
        //         flag = 1;
        //         res += grid[0][i] + grid[1][i];
        //     }
        // }

        // return res;
    }
};

int main() {
    // Example input
    vector<vector<int>> grid = {
        {2, 5, 4},
        {1, 5, 1}
    };

    Solution solution;
    long long result = solution.gridGame(grid);

    cout << "The maximum points collected by the second robot: " << result << endl;

    return 0;
}
