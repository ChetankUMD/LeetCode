#include <iostream>
#include <vector>
#include <climits> // For INT_MAX
#include <algorithm> // For min()

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, h = n - 1, mid = 0;
        int lowest = INT_MAX;

        while (l <= h) {
            mid = l + (h - l) / 2;
            cout << "Mid element: " << nums[mid] << endl;

            lowest = min(lowest, nums[mid]);

            if (nums[mid] > nums[h]) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return lowest;
    }
};

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2}; // Example rotated sorted array

    Solution sol;
    int minElement = sol.findMin(nums);

    cout << "Minimum element in the rotated array: " << minElement << endl;

    return 0;
}