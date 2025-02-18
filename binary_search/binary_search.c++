#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, h = n - 1, mid = 0;
        
        while (l <= h) {
            mid = l + (h - l) / 2;  // Prevents integer overflow
            
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] > target) {
                h = mid - 1;  // Move left
            }
            else {
                l = mid + 1;  // Move right
            }
        }
        return -1;  // Element not found
    }
};

int main() {
    Solution sol;  // Create an instance of Solution
    vector<int> nums = {-5, 1, 3, 5, 7, 9, 12};  // Sorted array
    int target;

    cout << "Enter the number to search: ";
    cin >> target;

    int result = sol.search(nums, target);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}