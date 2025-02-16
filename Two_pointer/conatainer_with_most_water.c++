#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int i = 0, j = n - 1;
        int res = 0;

        while (i < j) {
            int height = min(heights[i], heights[j]);
            int length = j - i;
            res = max(res, height * length);

            // Move the pointer that has the smaller height
            if (heights[i] < heights[j]) {
                i++;
            } else {
                j--;
            }
        }

        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read the size of the array
    int n;
    cin >> n;
    
    // Read the array values (heights)
    vector<int> heights(n);
    for(int i = 0; i < n; ++i) {
        cin >> heights[i];
    }

    // Create an instance of Solution and compute the result
    Solution sol;
    int result = sol.maxArea(heights);

    // Output the result
    cout << result << "\n";

    return 0;
}