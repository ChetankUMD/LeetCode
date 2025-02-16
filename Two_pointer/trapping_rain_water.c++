#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 3) return 0; // No water can be trapped if there are less than 3 bars
        
        // Two-pointer approach
        int left = 0, right = n - 1;
        int leftMax = height[left];
        int rightMax = height[right];
        int res = 0;

        while (left < right) {
            if (leftMax < rightMax) {
                left++;
                leftMax = max(leftMax, height[left]);
                res += (leftMax - height[left]);
            } else {
                right--;
                rightMax = max(rightMax, height[right]);
                res += (rightMax - height[right]);
            }
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Input: number of bars
    int n;
    cin >> n;

    // Read the heights
    vector<int> height(n);
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    // Create a Solution object and compute the trapped water
    Solution sol;
    int result = sol.trap(height);

    // Print the result
    cout << result << "\n";

    return 0;
}