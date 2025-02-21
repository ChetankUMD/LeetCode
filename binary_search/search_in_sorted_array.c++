#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, h = n - 1, mid = 0;

        while (l <= h) {
            mid = l + (h - l) / 2;
            
            if (target == nums[mid]) {
                return mid;
            }
            
            // Check if the left half is sorted
            if (nums[l] <= nums[mid]) {
                // If target lies in the sorted left half
                if (target >= nums[l] && target <= nums[mid]) {
                    h = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            // Otherwise, the right half must be sorted
            else {
                // If target lies in the sorted right half
                if (target >= nums[mid] && target <= nums[h]) {
                    l = mid + 1;
                } else {
                    h = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2}; // Example rotated sorted array
    int target = 0; // Change target to test different cases

    Solution sol;
    int result = sol.search(nums, target);

    if (result != -1) {
        cout << "Target " << target << " found at index: " << result << endl;
    } else {
        cout << "Target " << target << " not found in the array." << endl;
    }

    return 0;
}